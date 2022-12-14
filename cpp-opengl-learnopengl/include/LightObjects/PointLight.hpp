#ifndef POINT_LIGHT_HPP
#define POINT_LIGHT_HPP
#include <OpenGLBuffer.hpp>
#include <Texture.hpp>
#include <Shader.hpp>
#include <Camera.hpp>
#include <ShaderCollection.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class PointLight {
  public:
    PointLight();
    PointLight(Camera& camera);
    ~PointLight();

    void Draw();
    void SetScale(glm::vec3 scale);
    void SetRotation(float angle);
    void SetPosition(glm::vec3 pos);
    void SetColor(glm::vec3 col);

    inline glm::vec3 GetColor() { return m_color; }
    inline glm::vec3 GetPosition() { return m_pos; }

  private: 
    float m_x, m_y, m_width, m_height;
    float m_rotate = 0.0f;
    glm::vec3 m_pos;
    glm::vec3 m_scale = glm::vec3(0.2f);
    glm::vec3 m_color = glm::vec3(1.0f);
    
    Buffer* m_buffer;
    Shader* m_shader;
    Camera* m_camera;
};

#endif