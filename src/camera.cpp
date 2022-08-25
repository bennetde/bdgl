#include "camera.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stdexcept>

Camera::Camera(float speed) : transform{}, cameraSpeed{speed}, fovY(60.f), nearPlane(0.1f), farPlane(100.f) {
}

glm::mat4 Camera::getLookAtMatrix() {
    return glm::lookAt(transform.position, transform.position - transform.getForward(), glm::vec3(0.f,1.f,0.f));
}

glm::mat4 Camera::getProjectionMatrix() {
    return glm::perspective(glm::radians(fovY), aspectRatio, nearPlane, farPlane);
}

void Camera::update(BDGL& bdgl, float deltaTime) {
    if (bdgl.isKeyPressed(GLFW_KEY_W)) {
        transform.position -= transform.getForward() * (cameraSpeed * deltaTime);
    }
    if (bdgl.isKeyPressed(GLFW_KEY_S)) {
        transform.position += transform.getForward() * (cameraSpeed * deltaTime);
    }
    if (bdgl.isKeyPressed(GLFW_KEY_A)) {
        transform.position -= transform.getRight() * (cameraSpeed * deltaTime);
    }
    if (bdgl.isKeyPressed(GLFW_KEY_D)) {
        transform.position += transform.getRight() * (cameraSpeed * deltaTime);
    }
}