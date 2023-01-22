#include <LightObjects/PointLight.hpp>

PointLight::PointLight() {
  GLfloat vertices[] = {
    -1.0, -1.0,  1.0,
     1.0, -1.0,  1.0,
     1.0,  1.0,  1.0, 
    -1.0,  1.0,  1.0,

    // Back face
    -1.0, -1.0, -1.0,
    -1.0,  1.0, -1.0,
     1.0,  1.0, -1.0,  
     1.0, -1.0, -1.0,  

    // Top face
    -1.0,  1.0, -1.0,
    -1.0,  1.0,  1.0,
     1.0,  1.0,  1.0,  
     1.0,  1.0, -1.0,  

    // Bottom face
    -1.0, -1.0, -1.0,
     1.0, -1.0, -1.0,  
     1.0, -1.0,  1.0,  
    -1.0, -1.0,  1.0,

    // Right face
    1.0, -1.0, -1.0,  
    1.0,  1.0, -1.0,  
    1.0,  1.0,  1.0,  
    1.0, -1.0,  1.0,  

    // Left face
    -1.0, -1.0, -1.0,
    -1.0, -1.0,  1.0,
    -1.0,  1.0,  1.0,
    -1.0,  1.0, -1.0,
  };

  unsigned int indices[] = {
    0,  1,  2,  0,  2,  3,    // front
    4,  5,  6,  4,  6,  7,    // back
    8,  9,  10, 8,  10, 11,   // top
    12, 13, 14, 12, 14, 15,   // bottom
    16, 17, 18, 16, 18, 19,   // right
    20, 21, 22, 20, 22, 23,   // left
  };

  m_buffer = new Buffer();
  m_buffer->BindData(vertices, indices, 3 * 4 * 6, 6 * 6);
  m_buffer->PushFloat(3, 6 * sizeof(float), (void*) 0);
  m_buffer->PushFloat(3, 6 * sizeof(float), (void*) (3 * sizeof(float)));

  m_shader = new Shader("../shader/Basic.vert", "../shader/Basic.frag");
  m_shader->CreateProgram();

  m_camera = nullptr;
}

PointLight::PointLight(Camera& camera) {        
  GLfloat vertices[] = {
    -1.0, -1.0,  1.0, 0.0, 0.0, 1.0,
     1.0, -1.0,  1.0, 0.0, 0.0, 1.0,
     1.0,  1.0,  1.0, 0.0, 0.0, 1.0, 
    -1.0,  1.0,  1.0, 0.0, 0.0, 1.0,

    // Back face
    -1.0, -1.0, -1.0, 0.0,  0.0, -1.0,
    -1.0,  1.0, -1.0, 0.0,  0.0, -1.0,
     1.0,  1.0, -1.0, 0.0,  0.0, -1.0,  
     1.0, -1.0, -1.0, 0.0,  0.0, -1.0,  

    // Top face
    -1.0,  1.0, -1.0, 0.0,  1.0,  0.0,
    -1.0,  1.0,  1.0, 0.0,  1.0,  0.0,
     1.0,  1.0,  1.0, 0.0,  1.0,  0.0,  
     1.0,  1.0, -1.0, 0.0,  1.0,  0.0,  

    // Bottom face
    -1.0, -1.0, -1.0, 0.0, -1.0,  0.0,
     1.0, -1.0, -1.0, 0.0, -1.0,  0.0,  
     1.0, -1.0,  1.0, 0.0, -1.0,  0.0,  
    -1.0, -1.0,  1.0, 0.0, -1.0,  0.0,

    // Right face
    1.0, -1.0, -1.0, 1.0,  0.0,  0.0,
    1.0,  1.0, -1.0, 1.0,  0.0,  0.0, 
    1.0,  1.0,  1.0, 1.0,  0.0,  0.0, 
    1.0, -1.0,  1.0, 1.0,  0.0,  0.0, 

    // Left face
    -1.0, -1.0, -1.0, -1.0,  0.0,  0.0,
    -1.0, -1.0,  1.0, -1.0,  0.0,  0.0,
    -1.0,  1.0,  1.0, -1.0,  0.0,  0.0,
    -1.0,  1.0, -1.0, -1.0,  0.0,  0.0
  };

  unsigned int indices[] = {
    0,  1,  2,  0,  2,  3,    // front
    4,  5,  6,  4,  6,  7,    // back
    8,  9,  10, 8,  10, 11,   // top
    12, 13, 14, 12, 14, 15,   // bottom
    16, 17, 18, 16, 18, 19,   // right
    20, 21, 22, 20, 22, 23,   // left
  };

  m_buffer = new Buffer();
  m_buffer->BindData(vertices, indices, 6 * 4 * 6, 6 * 6);
  m_buffer->PushFloat(3, 6 * sizeof(float), (void*) 0);
  m_buffer->PushFloat(3, 6 * sizeof(float), (void*) 3);

  // m_shader = new Shader("../shader/Light.vert", "../shader/Light.frag");
  // m_shader = new Shader(
  //   ShaderCollection::GetShader("VERTEX", "LIGHT"), 
  //   ShaderCollection::GetShader("FRAGMENT", "LIGHT"),
  //   false, // Compile
  //   true  // Using text
  // ); 
  m_shader = new Shader("../shader/Light.vert", "../shader/Light.frag");

  m_shader->CreateProgram();

  this->m_camera = &camera;
}

PointLight::~PointLight() {
  delete m_buffer;
  delete m_shader;
}

void PointLight::Draw() {
  m_shader->UseProgram();

  glm::mat4 model = glm::mat4(1.0f);
  model = glm::translate(model, m_pos);
  model = glm::scale(model, m_scale);
  model = glm::rotate(model, glm::radians(m_rotate), glm::vec3(0.0f, 0.0f, 1.0f));

  glm::mat4 vp;
  
  if (m_camera == nullptr) {
    glm::mat4 view = glm::mat4(1.0f);
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -5.0f)); 
    glm::mat4 projection;
    projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

    vp = projection * view;
  } else {
    vp = m_camera->GetVP();
  }
  
  m_shader->UniformMat4("model", model);
  m_shader->UniformMat4("vp", vp);
  m_shader->UniformVec3("color", m_color);
  
  m_buffer->BindVAO();
  glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
  m_buffer->UnbindVAO();
}

void PointLight::SetScale(glm::vec3 scale) {
  this->m_scale = scale;
}

void PointLight::SetRotation(float angle) { 
  this->m_rotate = angle;
}

void PointLight::SetPosition(glm::vec3 pos) {
  this->m_pos = pos;
}

void PointLight::SetColor(glm::vec3 col) {
  this->m_color = col;
}