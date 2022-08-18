#include "BDGL.h"
#include "shader.h"
#include "texture.h"
#include <glm/vec4.hpp>
#include <glm/common.hpp>
unsigned int VAO, VBO, EBO;

BDGL::BDGL() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


}

void BDGL::createWindow(std::string name) {
    window = glfwCreateWindow(800,800, name.c_str(), NULL, NULL);
    if(window == NULL) {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }
    glfwMakeContextCurrent(window);

    //Init GLAD
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        throw std::runtime_error("Failed to init GLAD");
    }

    glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    });
}

void BDGL::init() {

    // VERTICES
    float vertices[] = {
        // positions          // colors           // texture coords
        0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
        0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
    };

    unsigned int indices[] = {
        0, 1, 2,   // first triangle
        3, 0, 2    // second triangle
    }; 

    // gen buffers
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);  
    glGenBuffers(1, &EBO);

    // bind objects
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO); 
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO); 

    // copy data to gpu
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW); 

    // configure and enable attributes
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);  

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3* sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2); 

    //glBindBuffer(GL_ARRAY_BUFFER, 0); 
    //glBindVertexArray(0); 
}

void BDGL::run() {
    init();
    Shader shader("./shaders/vertex.glsl", "./shaders/fragment.glsl");
    Texture containerTexture("./textures/container.jpg", TEXTURE_WRAP::REPEAT, TEXTURE_WRAP::REPEAT);
    Texture smileyTexture("./textures/awesomeface.png", TEXTURE_WRAP::REPEAT, TEXTURE_WRAP::REPEAT, PNG);

    while(!glfwWindowShouldClose(window)) {
        processInput();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        float timeValue = static_cast<float>(glfwGetTime());
        float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
        shader.set("ourColor", glm::vec4(0.0f, greenValue, 0.0f, 1.0f));
        shader.use();
        containerTexture.use(shader, "texture1", 0);
        smileyTexture.use(shader, "texture2", 1);
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glfwTerminate();
}

void BDGL::processInput() {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}