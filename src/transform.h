#pragma once
#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

// TODO: Create tests
class Transform {
private:
    glm::vec3 worldUp;
    glm::vec3 front;
    glm::vec3 up;

    glm::mat4 getTranslationMatrix();
    glm::mat4 getRotationMatrix();
    glm::mat4 getScaleMatrix();

public:
    Transform(glm::vec3 pos = glm::vec3(0.f), glm::quat rot = glm::vec3{0.f}, glm::vec3 = glm::vec3(1.f));
    glm::vec3 position;
    glm::quat rotation;
    glm::vec3 scale;

    glm::vec3 getForward();
    glm::vec3 getRight();
    glm::vec3 getUp();
    glm::vec3 getPosition();
    void setPosition(glm::vec3);
    void translate(glm::vec3);
    glm::vec3 getScale();
    void setScale(glm::vec3);

    void setRotation(glm::vec3 eulerAngles);
    glm::vec3 getEulerAngles();
    glm::vec3 getEulerAnglesInDegrees();
    
    //glm::mat4 getViewMatrix();
    glm::mat4 getModelMatrix();
};