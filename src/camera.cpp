#include "camera.h"
#include <glm/glm.hpp>
#include <glm/ext/matrix_projection.hpp>
#include <stdexcept>

Camera::Camera(glm::vec3 pos, glm::vec3 nUp) : cameraPos{pos}, up{nUp} {
}

glm::vec3 Camera::getForward() {
    return glm::normalize(cameraPos - cameraTarget);
}

glm::vec3 Camera::getUp() {
    return glm::cross(getForward(), getRight());
}

glm::mat4 Camera::getLookAtMatrix() {
    throw std::runtime_error("not implemented");
    return glm::mat4(0.0f);
}