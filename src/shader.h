#include <string>
/*
class Shader {
    std::string vertexShaderSource;
    std::string fragmentShaderSource;

    unsigned int shaderProgram;

    Shader(std::string vertexShader, std::string fragmentShader);
};
*/

unsigned int createShader(const std::string vertexShaderSource, const std::string fragmentShaderSource);