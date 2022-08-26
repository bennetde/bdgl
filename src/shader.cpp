#include "shader.h"
#include <iostream>
#include <glad/glad.h>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/glm.hpp>
#include <glm/common.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <fstream>
#include <sstream>
#include <string>

Shader::Shader(std::filesystem::path vertexShader, std::filesystem::path fragmentShader) {
    if(!std::filesystem::is_regular_file(vertexShader)) {
        throw std::runtime_error("ERROR::SHADER::FILE_NOT_FOUND\n" + vertexShader.string());
    } else if(!std::filesystem::is_regular_file(fragmentShader)) {
        throw std::runtime_error("ERROR::SHADER::FILE_NOT_FOUND\n" + fragmentShader.string());
    }

    std::ifstream vertexShaderStream(vertexShader);
    std::ifstream fragmentShaderStream(fragmentShader);
    std::string vertexShaderSource;
    std::string fragmentShaderSource;
    if(vertexShaderStream.is_open() && fragmentShaderStream.is_open()) {
        std::ostringstream vss;
        std::ostringstream fss;
        vss << vertexShaderStream.rdbuf();
        vertexShaderSource = vss.str();
        fss << fragmentShaderStream.rdbuf();
        fragmentShaderSource = fss.str();
    } else {
        throw std::runtime_error("ERROR:SHADER::COULD_NOT_OPEN_FILE");
    }

    const char* vertexShaderCodePtr = vertexShaderSource.c_str();
    const char* fragmentShaderCodePtr = fragmentShaderSource.c_str();

    unsigned int vertexId, fragmentId;
    int success;
    char infoLog[512]; // TODO: Make this a string? Or a std::array?

    vertexId = glCreateShader(GL_VERTEX_SHADER);
    fragmentId = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(vertexId, 1, &vertexShaderCodePtr, NULL);
    glShaderSource(fragmentId, 1, &fragmentShaderCodePtr, NULL);

    glCompileShader(vertexId);
    glGetShaderiv(vertexId, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(vertexId, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    glCompileShader(fragmentId);
    glGetShaderiv(fragmentId, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(fragmentId, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    ID = glCreateProgram();
    glAttachShader(ID, vertexId);
    glAttachShader(ID, fragmentId);
    glLinkProgram(ID);
    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(ID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexId);
    glDeleteShader(fragmentId);
}

Shader::~Shader() {
    glDeleteProgram(ID);
}

void Shader::use() {
    glUseProgram(ID);
}

template <>
void Shader::set<float>(const std::string &name, float value) const {
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

template <>
void Shader::set<int>(const std::string &name, int value) const {
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

template <>
void Shader::set<bool>(const std::string &name, bool value) const {
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

template <>
void Shader::set<glm::vec2>(const std::string &name, glm::vec2 value) const {
    glUniform2f(glGetUniformLocation(ID, name.c_str()), value.x, value.y);
}

template <>
void Shader::set<glm::vec3>(const std::string &name, glm::vec3 value) const {
    glUniform3f(glGetUniformLocation(ID, name.c_str()), value.x, value.y, value.z);
}

template <>
void Shader::set<glm::vec4>(const std::string &name, glm::vec4 value) const {
    glUniform4f(glGetUniformLocation(ID, name.c_str()), value.x, value.y, value.z, value.w);
}

template <>
void Shader::set<glm::mat4>(const std::string &name, glm::mat4 value) const {
    glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}