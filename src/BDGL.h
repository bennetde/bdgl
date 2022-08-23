#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class BDGL {
    GLFWwindow* window;

    public:
    BDGL();
    void run();
    void init();
    void createWindow(std::string name);
    int getWindowWidth();
    int getWindowHeight();

    private:
    int frameCount;
    int width;
    int height;
    void processInput();
};