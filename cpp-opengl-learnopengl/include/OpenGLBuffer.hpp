#ifndef OPENGLBUFFER_HPP
#define OPENGLBUFFER_HPP

#include <iostream>
#include <glad/glad.h>

/*! 
 * @brief This class do "the buffer" part for you :*
 * 
 * Creating a vertex buffer for vertices, and create VAO, including Index
 * Buffer. This can be used to create a shape on screen.
 */
class Buffer {
  public:
    /*!
     * @brief Construct the buffer on the memory.
     */
    Buffer();
    ~Buffer();

    void BindData(float* vertices, unsigned int* indices, int vertex_size, int indices_size);
    void PushFloat(int length, int size, void* offset);
    
    void BindBuffer();
    void UnbindBuffer();

    void BindVAO();
    void UnbindVAO();
      
  private:
    unsigned int m_vao, m_vbo, m_ibo;
    int m_layout = 0;
    
    float* m_vertices;
    unsigned int* m_indices;
};

#endif