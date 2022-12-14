#include <iostream>
#include <Window.hpp>
#include <Rectangle.hpp>
#include <Cube.hpp>
#include <LightObjects/PointLight.hpp>
#include <ShaderCollection.hpp>

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

void cam_move(GLFWwindow* window, float dt) {
  float speed = 5.0f * dt;

  /* Camera movement */
  if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
    campos.x += speed * camera->GetFront().x;
    // campos.y += speed * camera->GetFront().y;
    campos.z += speed * camera->GetFront().z;
  }
  if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
    campos.x -= speed * camera->GetFront().x;
    // campos.y -= speed * camera->GetFront().y;
    campos.z -= speed * camera->GetFront().z;
  }
  
  if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) 
    campos -= glm::normalize(glm::cross(camera->GetFront(), {0.0f, 1.0f, 0.0f})) * speed;
  if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    campos += glm::normalize(glm::cross(camera->GetFront(), {0.0f, 1.0f, 0.0f})) * speed;

  /* Light movement */
  if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
    lightpos.z -= speed;
  if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
    lightpos.z += speed;
  if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
    lightpos.x += speed;
  if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
    lightpos.x -= speed;
  if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS)
    lightpos.y += speed;
  if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS)
    lightpos.y -= speed;

  if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
    debug -= debugStep;
  if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
    debug += debugStep;
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
  float xoffset = xpos - lastX;
  float yoffset = lastY - ypos; // reversed since y-coordinates range from bottom to top
  lastX = xpos;
  lastY = ypos;

  const float sensitivity = 0.1f;
  xoffset *= sensitivity;
  yoffset *= sensitivity;

  if (moveCameraMode) {
    std::cout << glfwGetTime() << std::endl;
    float camX = sin(xoffset * 6.0f);
    // float camZ = cos(yoffset / 10) * 10.0f;
    float camZ = cos(yoffset * 6.0f) ;

    std::cout << camX << std::endl;
    // campos = glm::vec3(xoffset, yoffset, camera->GetPosition().z);
    camera->SetFront(glm::vec3(0.0f, 0.0f, 0.0f));
    campos.x = camX;
    campos.z = camZ;
  } else {
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
}

void mouse_button(GLFWwindow* window, int button, int action, int mods) {
  if (button == GLFW_MOUSE_BUTTON_MIDDLE && action == GLFW_PRESS) {
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    moveCameraMode = true;
  } else {
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    moveCameraMode = false;
  }
}

int main(int argc, char const *argv[]) {
  Window* window = new Window(800, 600, "Test");
  camera = new Camera(PROJECTION::PERSPECTIVE, 800.0f, 600.0f, 0.1f, 100.0f, campos, glm::vec3(0.0f));

  Cube* rect = new Cube(*camera);
  rect->SetTexture("/home/naufal/Documents/Projects/cpp-opengl-learnopengl/assets/container2.png", GL_TEXTURE0);
  rect->SetTexture("/home/naufal/Documents/Projects/cpp-opengl-learnopengl/assets/container2_specular.png", GL_TEXTURE1);
  PointLight* light = new PointLight(*camera);
  Cube* floor = new Cube(*camera);
  floor->SetTexture("/home/naufal/Documents/Projects/cpp-opengl-learnopengl/assets/grass.jpg", GL_TEXTURE0);
  floor->SetScale({30.0f, 0.5f, 30.0f});
  floor->SetPosition({0.0f, -2.5f, 0.0f});

  light->SetPosition(lightpos);

  rect->SetScale(glm::vec3(2.0));
  rect->GetShader().UniformVec3("eyePosition", camera->GetPosition());
  rect->GetShader().UniformVec3("light.position", light->GetPosition());
  floor->GetShader().UniformVec3("eyePosition", camera->GetPosition());

  glEnable(GL_DEPTH_TEST);
  glfwSetCursorPosCallback(window->GetWindow(), mouse_callback);
  glfwSetMouseButtonCallback(window->GetWindow(), mouse_button);
  glfwSetInputMode(window->GetWindow(), GLFW_CURSOR, GLFW_CURSOR_HIDDEN | GLFW_CURSOR_DISABLED);

  while (window->IsOpen()) {
    float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;

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
    cam_move(window->GetWindow(), deltaTime);
    camera->SetPosition(campos);

    rect->Draw();
    floor->Draw();
    light->Draw();

    glfwPollEvents();
    window->Display();
  }

  return 0;
}
