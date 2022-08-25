#pragma once
#include "BDGL.h"
#include "transform.h"
#include <glm/glm.hpp>

class Camera { 
    float cameraSpeed;
   
public:
    Camera(float speed = 2.5f);
    Transform transform;
    float fovY;
    float aspectRatio;
    float nearPlane, farPlane;

    glm::mat4 getLookAtMatrix();
    glm::mat4 getProjectionMatrix();
    void update(BDGL& bdgl, float deltaTime);
};