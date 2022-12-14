#ifndef CUBE_HPP
#define CUBE_HPP
#include <OpenGLBuffer.hpp>
#include <Texture.hpp>
#include <Shader.hpp>
#include <Camera.hpp>
#include <ShaderCollection.hpp>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Cube {
  public:
    Cube();
    Cube(Camera& camera);
    ~Cube();

    void Draw();
    void SetScale(glm::vec3 scale);
    void SetRotation(float angle);
    void SetTexture(std::string path, int slot);
    void SetPosition(glm::vec3 pos);

    inline Shader& GetShader() { return *m_shader; }

  private: 
    float m_x, m_y, m_width, m_height;
    float m_rotate = 0.0f;

    glm::vec3 m_scale = glm::vec3(1.0f);
    glm::vec3 m_pos;

    bool m_useTexture = false;
    
    Buffer* m_buffer;
    Shader* m_shader;
    Camera* m_camera;
    Texture* m_texture;

    std::vector<TextureSpec> m_textures;

    std::string m_vertexShader;
    std::string m_fragmentShader;
};

#endif