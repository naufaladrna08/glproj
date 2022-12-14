#include <Cube.hpp>

/* JUST TO REMEMBER
 * 
 * Vertex attribute has 3 elements: vertices, color, normal and 
 * texture coordinates. By default, texture coordinate is not
 * "pushed" yet. To use a texture, push a vertex attribute for
 * texture coordinate.
 */

Cube::Cube() {
  GLfloat vertices[64] = {
    // -0.5,  0.5f, 1.0f, 0.2f, 0.6f, 1.0f, 0.0, 1.0, // top left
    //  0.5,  0.5f, 1.0f, 0.2f, 0.6f, 1.0f, 1.0, 1.0, // top right
    //  0.5, -0.5f, 1.0f, 0.2f, 0.6f, 1.0f, 1.0, 0.0, // bottom right
    // -0.5, -0.5f, 1.0f, 0.2f, 0.6f, 1.0f, 0.0, 0.0  // bottom left
    -1, -1,  0.5, 0.2f, 0.6f, 1.0f, 0.0, 1.0, //0
     1, -1,  0.5, 0.2f, 0.6f, 1.0f, 1.0, 1.0, //1
    -1,  1,  0.5, 0.2f, 0.6f, 1.0f, 1.0, 0.0, //2
     1,  1,  0.5, 0.2f, 0.6f, 1.0f, 0.0, 0.0, //3
    -1, -1, -0.5, 0.2f, 0.6f, 1.0f, 0.0, 1.0, //4
     1, -1, -0.5, 0.2f, 0.6f, 1.0f, 1.0, 1.0, //5
    -1,  1, -0.5, 0.2f, 0.6f, 1.0f, 1.0, 0.0, //6
     1,  1, -0.5, 0.2f, 0.6f, 1.0f, 0.0, 0.0, //7
  };

  unsigned int indices[36] = {
    //Top
    2, 6, 7,
    2, 3, 7,

    //Bottom
    0, 4, 5,
    0, 1, 5,

    //Left
    0, 2, 6,
    0, 4, 6,

    //Right
    1, 3, 7,
    1, 5, 7,

    //Front
    0, 2, 3,
    0, 1, 3,

    //Back
    4, 6, 7,
    4, 5, 7
  };

  m_buffer = new Buffer();
  m_buffer->BindData(vertices, indices, 64, 36);
  m_buffer->PushFloat(3, 8 * sizeof(float), (void*) 0);
  m_buffer->PushFloat(3, 8 * sizeof(float), (void*) (3 * sizeof(float)));
  m_buffer->PushFloat(2, 8 * sizeof(float), (void*) (6 * sizeof(float)));

  m_shader = new Shader("../shader/Basic.vert", "../shader/Basic.frag");
  m_shader->CreateProgram();
  // m_texture = new Texture("../assets/wall.jpg");

  m_camera = nullptr;
}

Cube::Cube(Camera& camera) {        
  GLfloat vertices[] = {
    // Front face
    -1.0, -1.0,  1.0, 0.2f, 0.6f, 1.0f, 0.0, 0.0, 1.0, 0.0, 1.0,
     1.0, -1.0,  1.0, 0.2f, 0.6f, 1.0f, 0.0, 0.0, 1.0, 1.0, 1.0,
     1.0,  1.0,  1.0, 0.2f, 0.6f, 1.0f, 0.0, 0.0, 1.0, 1.0, 0.0, 
    -1.0,  1.0,  1.0, 0.2f, 0.6f, 1.0f, 0.0, 0.0, 1.0, 0.0, 0.0,

    // Back face
    -1.0, -1.0, -1.0, 0.2f, 0.6f, 1.0f, 0.0, 0.0, -1.0, 0.0, 1.0,
    -1.0,  1.0, -1.0, 0.2f, 0.6f, 1.0f, 0.0, 0.0, -1.0, 1.0, 1.0,
    1.0,  1.0, -1.0, 0.2f,  0.6f, 1.0f, 0.0, 0.0, -1.0, 1.0, 0.0,
    1.0, -1.0, -1.0, 0.2f,  0.6f, 1.0f, 0.0, 0.0, -1.0, 0.0, 0.0,

    // Top face
    -1.0,  1.0, -1.0, 0.2f, 0.6f, 1.0f, 0.0,  1.0, 0.0, 0.0, 1.0,
    -1.0,  1.0,  1.0, 0.2f, 0.6f, 1.0f, 0.0,  1.0, 0.0, 1.0, 1.0,
     1.0,  1.0,  1.0, 0.2f, 0.6f, 1.0f, 0.0,  1.0, 0.0, 1.0, 0.0,
     1.0,  1.0, -1.0, 0.2f, 0.6f, 1.0f, 0.0,  1.0, 0.0, 0.0, 0.0,

    // Bottom face
    -1.0, -1.0, -1.0, 0.2f, 0.6f, 1.0f, 0.0, -1.0,  0.0, 0.0, 1.0,
     1.0, -1.0, -1.0, 0.2f, 0.6f, 1.0f, 0.0, -1.0,  0.0, 1.0, 1.0,
     1.0, -1.0,  1.0, 0.2f, 0.6f, 1.0f, 0.0, -1.0,  0.0, 1.0, 0.0,
    -1.0, -1.0,  1.0, 0.2f, 0.6f, 1.0f, 0.0, -1.0,  0.0, 0.0, 0.0,

    // Right face
    1.0, -1.0, -1.0, 0.2f, 0.6f, 1.0f, 1.0,  0.0,  0.0, 0.0, 1.0,
    1.0,  1.0, -1.0, 0.2f, 0.6f, 1.0f, 1.0,  0.0,  0.0, 1.0, 1.0,
    1.0,  1.0,  1.0, 0.2f, 0.6f, 1.0f, 1.0,  0.0,  0.0, 1.0, 0.0,
    1.0, -1.0,  1.0, 0.2f, 0.6f, 1.0f, 1.0,  0.0,  0.0, 0.0, 0.0,

    // Left face
    -1.0, -1.0, -1.0, 0.2f, 0.6f, 1.0f, -1.0,  0.0,  0.0, 0.0, 1.0,
    -1.0, -1.0,  1.0, 0.2f, 0.6f, 1.0f, -1.0,  0.0,  0.0, 1.0, 1.0,
    -1.0,  1.0,  1.0, 0.2f, 0.6f, 1.0f, -1.0,  0.0,  0.0, 1.0, 0.0,
    -1.0,  1.0, -1.0, 0.2f, 0.6f, 1.0f, -1.0,  0.0,  0.0, 0.0, 0.0,
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
  m_buffer->BindData(vertices, indices, 11 * 4 * 6, 6 * 6);
  m_buffer->PushFloat(3, 11 * sizeof(float), (void*) 0);
  m_buffer->PushFloat(3, 11 * sizeof(float), (void*) (3 * sizeof(float)));
  m_buffer->PushFloat(3, 11 * sizeof(float), (void*) (6 * sizeof(float)));

  /* Using reserved shader code */
  // m_shader = new Shader(
  //  ShaderCollection::GetShader("VERTEX", "BASIC_WITHOUT_TEXTURE"), 
  //   ShaderCollection::GetShader("FRAGMENT", "BASIC_WITHOUT_TEXTURE"),
  //   false, // Compile
  //   true  // Using text
  // ); 

  /* Using external shader code */
  m_shader = new Shader("../shader/BasicWithoutTexture.vert", "../shader/BasicWithoutTexture.frag");
  m_shader->CreateProgram();
  
  this->m_camera = &camera;
  m_buffer->UnbindBuffer();
}

Cube::~Cube() {
  delete m_buffer;
  delete m_shader;

  if (m_useTexture) {
    for (auto tex : m_textures) {
      delete tex.texture;
    }
  }
}

void Cube::Draw() {
  m_buffer->BindBuffer();

  if (m_useTexture) {
    for (auto tex : m_textures) {
      tex.texture->ActivateTexture(tex.slot);
    }
  }

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

  m_buffer->BindVAO();
  glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
  m_buffer->UnbindVAO();
  glBindTexture(GL_TEXTURE_2D, 0);
}

void Cube::SetScale(glm::vec3 scale) {
  m_scale = scale;
}

void Cube::SetRotation(float angle) { 
  m_rotate = angle;
}

void Cube::SetTexture(std::string path, int slot) {
  /* Setup vertex attribute if not enabled */
  if (!this->m_useTexture) {
    m_buffer->BindBuffer();
    m_buffer->PushFloat(2, 11 * sizeof(float), (void*) (9 * sizeof(float)));

    this->m_useTexture = true;
  }

  /* Reset shader */
  delete m_shader;
  // m_shader = new Shader(
  //   ShaderCollection::GetShader("VERTEX", "BASIC_WITH_TEXTURE"), 
  //   ShaderCollection::GetShader("FRAGMENT", "BASIC_WITH_TEXTURE"),
  //   false, // Compile
  //   true  // Using text
  // ); 
  m_shader = new Shader(
    "/home/naufal/Documents/Projects/cpp-opengl-learnopengl/shader/Basic.vert",
    "/home/naufal/Documents/Projects/cpp-opengl-learnopengl/shader/Basic.frag"
  );

  m_shader->CreateProgram();

  /* Create a texture object and specification */
  m_texture = new Texture(path);

  TextureSpec spec;
  spec.texture = m_texture;
  spec.slot = slot;

  /* Push textures */
  m_textures.push_back(spec);

  // delete m_texture;
  m_buffer->UnbindBuffer();
}

void Cube::SetPosition(glm::vec3 pos) {
  this->m_pos = pos;
}