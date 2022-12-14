#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include <OpenGLBuffer.hpp>
#include <Texture.hpp>
#include <Shader.hpp>
#include <Camera.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Rectangle {
  public:
    Rectangle();
    Rectangle(Camera& camera);
    ~Rectangle();

    void Draw();
    void SetScale(glm::vec3 scale);
    void SetRotation(float angle);

  private: 
    float m_x, m_y, m_width, m_height;
    glm::vec3 m_scale = glm::vec3(1.0f);
    float m_rotate = 0.0f;
    
    Buffer* m_buffer;
    Shader* m_shader;
    Texture* m_texture;
    Camera* m_camera;
};

#endif