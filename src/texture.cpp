#include "texture.h"
#include "shader.h"
#include <glad/glad.h>


// TODO: Allow user to set Mipmap stuff
// TODO: Add functions that allow changing settings runtime. like filtering
Texture::Texture(std::filesystem::path imagePath, TEXTURE_WRAP horizontalWrap, TEXTURE_WRAP verticalWrap, IMAGE_TYPE imageType) : img(imagePath) {
    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, horizontalWrap);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, verticalWrap);

    if(!img.hasData()) {
        throw std::runtime_error("LOAD::TEXTURE failed");
    }

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img.getWidth(), img.getHeight(), 0, imageType, GL_UNSIGNED_BYTE, img.data);
    glGenerateMipmap(GL_TEXTURE_2D);
}

void Texture::use(Shader &shader, const std::string uniformName, uint_least8_t unit) {
    if(unit > 31) {
        throw std::invalid_argument("Unit cannot be higher than 31.");
    }
    glActiveTexture(GL_TEXTURE0 + unit);
    glBindTexture(GL_TEXTURE_2D, ID);
    shader.set<int>(uniformName, unit);
}