#include "camera.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <stdexcept>

Camera::Camera(float speed) : transform{}, cameraSpeed{speed}, fovY(60.f), nearPlane(0.1f), farPlane(100.f), yaw{0}, pitch{0} {
}

glm::mat4 Camera::getLookAtMatrix() {
    return glm::lookAt(transform.position, transform.position - transform.getForward(), transform.getUp());
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
    if (bdgl.isKeyPressed(GLFW_KEY_SPACE)) {
        transform.translate(transform.getUp() * (cameraSpeed * deltaTime));
    }
    if (bdgl.isKeyPressed(GLFW_KEY_LEFT_CONTROL)) {
        transform.translate(-transform.getUp() * (cameraSpeed * deltaTime));
    }

    // auto rotationDegs = transform.getEulerAnglesInDegrees();
    auto mouseDelta = bdgl.getMouseDelta() * mouseSensitivity;
    pitch += mouseDelta.y;
    yaw += mouseDelta.x;

    if(pitch > 89.f) {
        pitch = 89.f;
    }
    if(pitch < -89.f) {
        pitch = -89.f;
    }
    // std::cout << std::to_string(rotationDegs.x) << " " << std::to_string(rotationDegs.y) << " " << std::to_string(rotationDegs.z) << std::endl;
    transform.setRotation(glm::vec3{glm::radians(pitch), -glm::radians(yaw), 0.f});
    
    if(yaw > 360) {
        yaw -= 360;
    }
    if(yaw < -360) {
        yaw += 360;
    }
    std::cout << std::to_string(yaw) << std::endl;
    // glm::vec3 front;
    // front.x = cos(glm::radians(rotationDegs.y)) * cos(glm::radians(rotationDegs.x));
    // front.y = sin(glm::radians(rotationDegs.x));
    // front.z = sin(glm::radians(rotationDegs.y)) * sin(glm::radians(rotationDegs.x));
    // front = glm::normalize(front);

    // transform.setRotation(transform.getRotation() * glm::angleAxis(-glm::radians(mouseDelta.x), glm::vec3(1.f,0.f,0.f)));
    // transform.setRotation(transform.getRotation() * glm::angleAxis(-glm::radians(mouseDelta.y), glm::vec3(0.f,1.f,0.f)));

    //transform.setRotation(glm::quat{glm::vec3{.0f, -glm::radians(mouseDelta.x), .0f}} * transform.getRotation() * glm::quat{glm::vec3{glm::radians(mouseDelta.y), .0f , .0f}});

    // transform.setRotation(glm::radians(0.f), front);
}