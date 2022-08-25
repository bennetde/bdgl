#include "transform.h"

Transform::Transform(glm::vec3 pos, glm::quat rot, glm::vec3 scl) : position{pos}, rotation{rot}, scale{scl} {}

glm::mat4 Transform::getTranslationMatrix() {
    return glm::translate(glm::mat4(1.0f), position);
}

glm::mat4 Transform::getRotationMatrix() {
    return glm::toMat4(rotation);
}

glm::mat4 Transform::getScaleMatrix() {
    return glm::scale(glm::mat4(1.0f), scale);
}

glm::mat4 Transform::getModelMatrix() {
    return getTranslationMatrix() * getRotationMatrix() * getScaleMatrix();
}

glm::vec3 Transform::getForward() {
    return rotation * glm::vec3(0.0f,0.0f,1.0f);
}

glm::vec3 Transform::getRight() {
    return rotation * glm::vec3(1.0f,0.0f,0.0f);
}

glm::vec3 Transform::getUp() {
    return rotation * glm::vec3(0.0f,1.0f,0.0f);
}

glm::vec3 Transform::getPosition() {
    return position;
}

void Transform::setPosition(glm::vec3 newPos) {
    position = newPos;
}

void Transform::translate(glm::vec3 addPos) {
    position += addPos;
}

glm::vec3 Transform::getScale() {
    return scale;
}

void Transform::setScale(glm::vec3 newScale) {
    scale = newScale;
}

void Transform::setRotation(glm::vec3 eulerAngles) {
    rotation = glm::quat(eulerAngles);
}

void Transform::setRotation(float angle, glm::vec3 axis) {
    rotation = glm::angleAxis(angle, axis);
}

void Transform::setRotation(glm::quat newRot) {
    rotation = newRot;
}

glm::quat Transform::getRotation() {
    return rotation;
}

glm::vec3 Transform::getEulerAngles() {
    return glm::eulerAngles(rotation);
}

glm::vec3 Transform::getEulerAnglesInDegrees() {
    auto radians = getEulerAngles();
    return glm::degrees(radians);
}