#include "camera.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stdexcept>

Camera::Camera(glm::vec3 pos, glm::vec3 nUp) : cameraPos{pos}, up{nUp} {
}

glm::vec3 Camera::getForward() {
    return glm::normalize(cameraPos - cameraTarget);
}

glm::vec3 Camera::getUp() {
    return glm::cross(getForward(), getRight());
}

glm::vec3 Camera::getRight() {
    return glm::normalize(glm::cross(up, getForward()));
}
glm::mat4 Camera::getLookAtMatrix() {
    return glm::lookAt(cameraPos, cameraTarget, up);
}

void Camera::setPosition(glm::vec3 pos) {
    cameraPos = pos;
}