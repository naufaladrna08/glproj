#include <iostream>
#include <Window.hpp>
#include <String.hpp>
#include <Logger.hpp>
#include <Event.hpp>
#include <Rectangle.hpp>
#include <Cube.hpp>
#include <LightObjects/PointLight.hpp>
#include <ShaderCollection.hpp>
#include <GLFW/glfw3.h>
#include <Core/Timer.hpp>
using namespace Tridme;

float deltaTime = 0.0f;
float lastFrame = 0.0f;
float yaw;
float pitch = -90.0f;
float lastX = 400, lastY = 300;

/* Debug for: Ambient Light. 
 * For changing value, use Q and E
 */
float debug = 0.0f;
float debugStep = 0.01f;

Camera* camera;
glm::vec3 campos = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 lightpos = glm::vec3(5.0f, 5.0f, 0.0f);
glm::vec3 lightColor = { 1.0f, 1.0f, 1.0f };

bool moveCameraMode = false;

void mouse_callback(double xpos, double ypos) {
  float xoffset = xpos - lastX;
  float yoffset = lastY - ypos; // reversed since y-coordinates range from bottom to top
  lastX = xpos;
  lastY = ypos;

  const float sensitivity = 0.1f;
  xoffset *= sensitivity;
  yoffset *= sensitivity;

  yaw   += xoffset;
  pitch += yoffset;

  if(pitch > 89.0f)
    pitch =  89.0f;
  if(pitch < -89.0f)
    pitch = -89.0f;

  glm::vec3 direction;
  direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
  direction.y = sin(glm::radians(pitch));
  direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

  camera->SetFront(glm::normalize(direction));
}

// void mouse_button(GLFWwindow* window, int button, int action, int mods) {
//   if (button == GLFW_MOUSE_BUTTON_MIDDLE && action == GLFW_PRESS) {
//     glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//     moveCameraMode = true;
//   } else {
//     glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
//     moveCameraMode = false;
//   }
// }

int main(int argc, char const *argv[]) {
  String app_name = "Tridme Engine";
  LOG(LOG_TYPE::INFO, app_name);
  Tridme::Window* window = new Tridme::Window(800, 600, "Tridme Engine");

  window->SetPointerMode(TRIDME_POINTER_MODE_CAPTURED);

  String os_type = window->GetOSImplementation()->GetName().get();
  LOG(LOG_TYPE::INFO, "Running on %s", os_type.get());

  camera = new Camera(PROJECTION::PERSPECTIVE, 800.0f, 600.0f, 0.1f, 100.0f, campos, glm::vec3(0.0f));

  Cube* rect = new Cube(*camera);
  rect->SetTexture("../assets/container2.png", GL_TEXTURE0);
  rect->SetTexture("../assets/container2_specular.png", GL_TEXTURE1);
  PointLight* light = new PointLight(*camera);
  Cube* floor = new Cube(*camera);
  floor->SetTexture("../assets/grass.jpg", GL_TEXTURE0);
  floor->SetScale({30.0f, 0.5f, 30.0f});
  floor->SetPosition({0.0f, -2.5f, 0.0f});

  light->SetPosition(lightpos);

  rect->SetScale(glm::vec3(2.0));
  rect->GetShader().UniformVec3("eyePosition", camera->GetPosition());
  rect->GetShader().UniformVec3("light.position", light->GetPosition());
  floor->GetShader().UniformVec3("eyePosition", camera->GetPosition());

  glEnable(GL_DEPTH_TEST);

  while (window->IsOpen()) {
    float currentFrame = (float) window->GetTime() / (float) 1000000000.0f;
    deltaTime = currentFrame - lastFrame; // 6579578
    lastFrame = currentFrame;

    while (window->PollEvents()) {
      Tridme::Event event = window->GetHandler();

      // LOG(INFO, "Position (%d, %d)", event.mouse.pos_x, event.mouse.pos_y);
      mouse_callback(event.mouse.pos_x, event.mouse.pos_y);
    }
    float speed = 15.0f * deltaTime;

    /* Camera movement */
    if (window->GetKey(Tridme::Keyboard::TRIDME_KEY_W)) {
      campos.x += speed * camera->GetFront().x;
      campos.z += speed * camera->GetFront().z;
    }
    if (window->GetKey(Tridme::Keyboard::TRIDME_KEY_S)) {
      campos.x -= speed * camera->GetFront().x;
      campos.z -= speed * camera->GetFront().z;
    }
    
    if (window->GetKey(Tridme::Keyboard::TRIDME_KEY_A)) 
      campos -= glm::normalize(glm::cross(camera->GetFront(), {0.0f, 1.0f, 0.0f})) * speed;
    if (window->GetKey(Tridme::Keyboard::TRIDME_KEY_D))
      campos += glm::normalize(glm::cross(camera->GetFront(), {0.0f, 1.0f, 0.0f})) * speed;

    /* Light movement */
    if (window->GetKey(Tridme::TRIDME_KEY_UP))
      lightpos.z -= speed;
    if (window->GetKey(Tridme::TRIDME_KEY_DOWN))
      lightpos.z += speed;
    if (window->GetKey(Tridme::TRIDME_KEY_LEFT))
      lightpos.x += speed;
    if (window->GetKey(Tridme::TRIDME_KEY_RIGHT))
      lightpos.x -= speed;
    if (window->GetKey(Tridme::TRIDME_KEY_M))
      lightpos.y += speed;
    if (window->GetKey(Tridme::TRIDME_KEY_N))
      lightpos.y -= speed;

    if (window->GetKey(Tridme::Keyboard::TRIDME_KEY_Q))
      debug -= debugStep;
    if (window->GetKey(Tridme::Keyboard::TRIDME_KEY_E))
      debug += debugStep;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 0.2f);

    /* Light reflection */
    glm::vec3 diffuseColor = lightColor   * glm::vec3(1.0f); // decrease the influence
    glm::vec3 ambientColor = diffuseColor * glm::vec3(0.2f); // low influence

    rect->GetShader().UniformVec3("eyePosition", camera->GetPosition());
    rect->GetShader().UniformInt("material.diffuse", 0);
    rect->GetShader().UniformInt("material.specular", 1);
    rect->GetShader().Uniform1f("material.shiniess", 32.0f);
    rect->GetShader().UniformVec3("light.position", light->GetPosition());
    rect->GetShader().UniformVec3("light.ambient", ambientColor);
    rect->GetShader().UniformVec3("light.diffuse", diffuseColor);
    rect->GetShader().UniformVec3("light.specular", { 1.0f, 1.0f, 1.0f });
    rect->GetShader().UniformVec3("light.direction", -lightpos);
  
    rect->GetShader().Uniform1f("light.constant", 1.0f);
    rect->GetShader().Uniform1f("light.linear", 0.09f);
    rect->GetShader().Uniform1f("light.quadratic", 0.032f);

    floor->GetShader().UniformVec3("eyePosition", camera->GetPosition());
    floor->GetShader().UniformInt("material.diffuse", 0);
    floor->GetShader().Uniform1f("material.shiniess", 32.0f);
    // floor->GetShader().UniformVec3("material.ambient", { 1.0f, 0.5f, 0.31f });
    // floor->GetShader().UniformVec3("material.diffuse", { 1.0f, 0.5f, 0.31f });
    // floor->GetShader().UniformVec3("material.specular", { 0.5f, 0.5f, 0.5f });
    floor->GetShader().Uniform1f("material.shiniess", 32.0f);
    floor->GetShader().UniformVec3("light.position", light->GetPosition());
    floor->GetShader().UniformVec3("light.ambient", ambientColor);
    floor->GetShader().UniformVec3("light.diffuse", diffuseColor);
    floor->GetShader().UniformVec3("light.specular", { 1.0f, 1.0f, 1.0f });
    floor->GetShader().UniformVec3("light.direction", -lightpos);
    floor->GetShader().Uniform1f("light.constant", 1.0f);
    floor->GetShader().Uniform1f("light.linear", 0.09f);
    floor->GetShader().Uniform1f("light.quadratic", 0.032f);

    light->SetColor(lightColor);
    light->SetPosition(lightpos);
    // cam_move(window->GetWindow(), deltaTime);
    camera->SetPosition(campos);

    rect->Draw();
    floor->Draw();
    light->Draw();

    window->Display();
  }

  window->Close();
  return 0;
}
