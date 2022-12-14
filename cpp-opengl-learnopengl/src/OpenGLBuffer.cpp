#include <OpenGLBuffer.hpp>

/*!
 * @brief Construct the buffer on the memory.
 */
Buffer::Buffer() {
  glGenVertexArrays(1, &m_vao);
  glBindVertexArray(m_vao);

  glGenBuffers(1, &m_vbo);
  glGenBuffers(1, &m_ibo);
  
  this->BindBuffer();
}

Buffer::~Buffer() {

}

void Buffer::BindData(float* vertices, unsigned int* indices, int vertex_size, int indices_size) {
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
  glBufferData(GL_ARRAY_BUFFER, vertex_size * sizeof(float), vertices, GL_STATIC_DRAW);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices_size * sizeof(unsigned int), indices, GL_STATIC_DRAW);
}

void Buffer::BindBuffer() {
  glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
}

void Buffer::UnbindBuffer() {
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Buffer::PushFloat(int length, int size, void* offset) {
  glVertexAttribPointer(m_layout, length, GL_FLOAT, GL_FALSE, size, offset);
  glEnableVertexAttribArray(m_layout);
  m_layout++;
}

void Buffer::BindVAO() {
  glBindVertexArray(m_vao);
}

void Buffer::UnbindVAO() {
  glBindVertexArray(0);
}
