#pragma once
#include <array>
#include <vector>
#include "vertex.h"
#include "../texture.h"

class Mesh {
public:    
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<std::shared_ptr<Texture>> textures;

    Mesh(std::vector<Vertex>,std::vector<unsigned int>, std::vector<std::shared_ptr<Texture>>);
    void Draw(Shader&);
private:
    unsigned int VAO, VBO, EBO;
};