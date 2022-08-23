#pragma once
#include <glm/glm.hpp>

class Camera {
    glm::vec3 cameraPos;
    glm::vec3 cameraTarget;
    glm::vec3 up;
   
public:
    Camera(glm::vec3 pos = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 target = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f));
    // "cameraDirection"
    glm::vec3 getPosition();
    glm::vec3 getForward();
    glm::vec3 getRight();
    glm::vec3 getUp();
    void setPosition(glm::vec3 pos);

     glm::mat4 getLookAtMatrix();


};