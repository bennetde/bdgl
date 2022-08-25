#pragma once
#include <iostream>
#include <glm/vec2.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class BDGL {

private:
    GLFWwindow* window;
    int frameCount;
    int width, height;
    float deltaTime, lastFrame;
    double mouseX, mouseY, lastMouseX, lastMouseY;
    glm::vec2 mouseDelta;
    void processInput();
    void updateMousePos();

public:
    BDGL();
    void run();
    void init();
    void createWindow(std::string name);
    int getWindowWidth();
    int getWindowHeight();
    bool isKeyPressed(int key);
    glm::vec2 getMouseDelta();
    glm::vec2 getMousePos();
    
};