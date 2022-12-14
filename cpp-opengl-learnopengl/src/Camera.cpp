#include <Camera.hpp>

Camera::Camera(PROJECTION proj, float width, float height, float near, float far, glm::vec3 pos, glm::vec3 target) {
  this->m_pos = pos;
  this->m_target = target;
  this->m_width = width;
  this->m_height = height;

  glm::vec3 direction = glm::normalize(m_pos - m_target);
  glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

  this->m_cameraRight = glm::normalize(glm::cross(up, direction));
  this->m_cameraUp = glm::cross(direction, m_cameraRight);
  this->m_cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);

  if (proj == PROJECTION::ORTHOGRAPHIC) {
    this->m_project = glm::ortho(0.0f, width, 0.0f, height, near, far);
  } else if (proj == PROJECTION::PERSPECTIVE) {
    this->m_project = glm::perspective(glm::radians(45.0f), width / height, near, far);
  }
}

Camera::~Camera() {

}

glm::mat4 Camera::GetVP() {
  glm::mat4 view = glm::mat4(1.0f);
  view = glm::lookAt(m_pos, m_pos + m_cameraFront, glm::vec3(0.0, 1.0, 0.0));  

  return m_project * view;
}

void Camera::SetPosition(glm::vec3 pos) {
  this->m_pos = pos;
}

void Camera::SetRotation(glm::vec3 angle) {
  glm::vec3 direction;
  direction.x = cos(glm::radians(angle.x)) * cos(glm::radians(angle.y));
  direction.y = sin(glm::radians(angle.y));
  direction.z = sin(glm::radians(angle.x)) * cos(glm::radians(angle.y));

  m_cameraFront = glm::normalize(direction);
}

void Camera::SetFront(glm::vec3 front) {
  m_cameraFront = front;
}