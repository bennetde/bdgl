#pragma once
#include <string>
#include <filesystem>
#include <glad/glad.h>

class Shader {
    unsigned int ID;
public:
    Shader(std::filesystem::path vertexShader, std::filesystem::path fragmentShader);
    void use();

    template <typename T>
    void set(const std::string &name, T value) const;
    ~Shader();
    //void set(const std::string &name, int value) const;
    //void set(const std::string &name, float value) const;

    // TODO: CHANGE COPY/MOVE CONSTRUCTORS, ASSIGNMENT OPERATORS AND DESTRUCTOR. WE DONT WANT THE SHADER TO BE ACCESSIBLE ANYMORE WHEN THIS OBJECT GETS REMOVED
};


unsigned int createShader(const std::string vertexShaderSource, const std::string fragmentShaderSource);