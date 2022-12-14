#include <Rectangle.hpp>

Rectangle::Rectangle() {
  GLfloat vertices[32] = {
    -0.5,  0.5f, 1.0f, 0.2f, 0.6f, 1.0f, 0.0, 1.0, // top left
     0.5,  0.5f, 1.0f, 0.2f, 0.6f, 1.0f, 1.0, 1.0, // top right
     0.5, -0.5f, 1.0f, 0.2f, 0.6f, 1.0f, 1.0, 0.0, // bottom right
    -0.5, -0.5f, 1.0f, 0.2f, 0.6f, 1.0f, 0.0, 0.0  // bottom left
  };

  unsigned int indices[6] = {
    0, 1, 2,
    2, 0, 3
  };

  m_buffer = new Buffer();
  m_buffer->BindData(vertices, indices, 32, 6);
  m_buffer->PushFloat(3, 8 * sizeof(float), (void*) 0);
  m_buffer->PushFloat(3, 8 * sizeof(float), (void*) (3 * sizeof(float)));
  m_buffer->PushFloat(2, 8 * sizeof(float), (void*) (6 * sizeof(float)));

  m_shader = new Shader("../shader/Basic.vert", "../shader/Basic.frag");
  m_shader->CreateProgram();
  m_texture = new Texture("../assets/wall.jpg");

  m_camera = nullptr;
}

Rectangle::Rectangle(Camera& camera) {
  GLfloat vertices[32] = {
    -0.5,  0.5f, 1.0f, 0.2f, 0.6f, 1.0f, 0.0, 1.0, // top left
     0.5,  0.5f, 1.0f, 0.2f, 0.6f, 1.0f, 1.0, 1.0, // top right
     0.5, -0.5f, 1.0f, 0.2f, 0.6f, 1.0f, 1.0, 0.0, // bottom right
    -0.5, -0.5f, 1.0f, 0.2f, 0.6f, 1.0f, 0.0, 0.0  // bottom left
  };

  unsigned int indices[6] = {
    0, 1, 2,
    2, 0, 3
  };

  m_buffer = new Buffer();
  m_buffer->BindData(vertices, indices, 32, 6);
  m_buffer->PushFloat(3, 8 * sizeof(float), (void*) 0);
  m_buffer->PushFloat(3, 8 * sizeof(float), (void*) (3 * sizeof(float)));
  m_buffer->PushFloat(2, 8 * sizeof(float), (void*) (6 * sizeof(float)));

  m_shader = new Shader("../shader/Basic.vert", "../shader/Basic.frag");
  m_shader->CreateProgram();
  m_texture = new Texture("../assets/wall.jpg");

  this->m_camera = &camera;
}

Rectangle::~Rectangle() {
  delete m_buffer;
  delete m_shader;
  delete m_texture;
}

void Rectangle::Draw() {
  m_texture->Bind();
  m_shader->UseProgram();

  glm::mat4 model = glm::mat4(1.0f);
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
  
  m_buffer->BindVAO();
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
  m_buffer->UnbindVAO();
}

void Rectangle::SetScale(glm::vec3 scale) {
  m_scale = scale;
}

void Rectangle::SetRotation(float angle) { 
  m_rotate = angle;
}