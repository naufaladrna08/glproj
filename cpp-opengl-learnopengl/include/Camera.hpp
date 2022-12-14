#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

enum PROJECTION {
  ORTHOGRAPHIC,
  PERSPECTIVE
};

enum AXIS {
  X, Y, Z
};

class Camera {
  public:
    Camera(PROJECTION proj, float width, float height, float near, float far, glm::vec3 pos, glm::vec3 target);
    ~Camera();

    glm::mat4 GetVP();

    void SetPosition(glm::vec3 pos);
    void SetRotation(glm::vec3 angle);
    void SetFront(glm::vec3 front);

    inline glm::vec3 GetFront() { return m_cameraFront; }
    inline glm::vec3 GetPosition() { return m_pos; }

  private:
    glm::vec3 m_pos;
    glm::vec3 m_target;

    glm::vec3 m_cameraRight;
    glm::vec3 m_cameraUp;
    glm::vec3 m_cameraFront;

    /* Camera projection */
    glm::mat4 m_project;

    float m_width;
    float m_height;
};

#endif