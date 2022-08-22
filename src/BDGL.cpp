#include "BDGL.h"
#include "shader.h"
#include "texture.h"
#include <glm/vec4.hpp>
#include <glm/common.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <array>

unsigned int VAO, VBO, EBO;

BDGL::BDGL() : frameCount{0} {
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
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
        0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
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
    // Positions
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);  

    // Vertex Color
    // glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3* sizeof(float)));
    // glEnableVertexAttribArray(1);

    // UVs
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1); 

    //glBindBuffer(GL_ARRAY_BUFFER, 0); 
    //glBindVertexArray(0); 
}

void BDGL::run() {
    init();
    Shader shader("./shaders/vertex.glsl", "./shaders/fragment.glsl");
    Texture containerTexture("./textures/container.jpg", TEXTURE_WRAP::REPEAT, TEXTURE_WRAP::REPEAT);
    Texture smileyTexture("./textures/awesomeface.png", TEXTURE_WRAP::REPEAT, TEXTURE_WRAP::REPEAT, PNG);

    std::array<glm::vec3, 10> cubePositions = {
        glm::vec3( 0.0f,  0.0f,  0.0f), 
        glm::vec3( 2.0f,  5.0f, -15.0f), 
        glm::vec3(-1.5f, -2.2f, -2.5f),  
        glm::vec3(-3.8f, -2.0f, -12.3f),  
        glm::vec3( 2.4f, -0.4f, -3.5f),  
        glm::vec3(-1.7f,  3.0f, -7.5f),  
        glm::vec3( 1.3f, -2.0f, -2.5f),  
        glm::vec3( 1.5f,  2.0f, -2.5f), 
        glm::vec3( 1.5f,  0.2f, -1.5f), 
        glm::vec3(-1.3f,  1.0f, -1.5f)  
    };

    glEnable(GL_DEPTH_TEST);  

    while(!glfwWindowShouldClose(window)) {
        double lastTime = glfwGetTime();
        processInput();

        // // Transformation Matrix
        // glm::mat4 trans = glm::mat4(1.0f);
        // trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(0.0, 0.0, 1.0));
        // trans = glm::translate(trans, glm::vec3(0.5f, -0.5f, 0.0f));


        // View Matrix (Global -> View)
        glm::mat4 view = glm::mat4(1.0f);
        // note that we're translating the scene in the reverse direction of where we want to move
        view = glm::translate(view, glm::vec3(sin(glfwGetTime()), 0.0f, -3.0f)); 

        // Projection (View -> Clip)
        glm::mat4 projection;
        projection = glm::perspective(glm::radians(140.0f), 800.0f / 800.0f, 0.1f, 100.0f);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        float timeValue = static_cast<float>(glfwGetTime());
        float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
        shader.set("ourColor", glm::vec4(0.0f, greenValue, 0.0f, 1.0f));

        shader.set("view", view);
        shader.set("projection", projection);
        shader.use();
        containerTexture.use(shader, "texture1", 0);
        smileyTexture.use(shader, "texture2", 1);
        glBindVertexArray(VAO);
        for(unsigned int i = 0; i < cubePositions.size(); i++) {
            // Model Matrix (Local -> Global)
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, cubePositions[i]);
            float angle = 20.0f * i; 
            model = glm::rotate(model, (float)glfwGetTime() * glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f)); 
            shader.set("model", model);

            glDrawArrays(GL_TRIANGLES, 0, 36);
        }


        double secondsPerFrame = glfwGetTime() - lastTime;
        frameCount++;
        std::string title = "Frame Time:" + std::to_string(secondsPerFrame*1000) + "ms";
        glfwSetWindowTitle(window, title.c_str());

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