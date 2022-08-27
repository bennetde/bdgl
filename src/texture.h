#pragma once
#include <glad/glad.h>
#include "shader.h"
#include "image.h"

enum IMAGE_TYPE {
    PNG = GL_RGBA, JPG = GL_RGB
};

enum TEXTURE_WRAP {
    REPEAT = GL_REPEAT, MIRRORED_REPEAT = GL_MIRRORED_REPEAT, CLAMP_TO_EDGE = GL_CLAMP_TO_EDGE, CLAMP_TO_BORDER = GL_CLAMP_TO_BORDER
};

enum TEXTURE_TYPE {
    DIFFUSE, SPECULAR
};

class Texture {
    Image img;

    public:
    unsigned int ID;
    TEXTURE_TYPE type;
    Texture(std::filesystem::path, TEXTURE_WRAP horizontalWrap, TEXTURE_WRAP verticalWrap, TEXTURE_TYPE, IMAGE_TYPE imageType = IMAGE_TYPE::JPG);
    void use(Shader& shader, const std::string uniformName, uint_least8_t unit = 0);
};