#include "BDGL.h"

BDGL::BDGL() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


}

void BDGL::createWindow(std::string name) {
    window = glfwCreateWindow(800,600, name.c_str(), NULL, NULL);
    if(window == NULL) {
        glfwTerminate();
        throw std::exception("Failed to create GLFW window");
    }
    glfwMakeContextCurrent(window);

    //Init GLAD
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        throw std::exception("Failed to init GLAD");
    }

    glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    });
}

void BDGL::run() {
    while(!glfwWindowShouldClose(window)) {
        processInput();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        float vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f,  0.5f, 0.0f
        };

        unsigned int VBO;
        glGenBuffers(1, &VBO);  

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}

void BDGL::processInput() {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}