#pragma once
#include <array>
#include <vector>
#include "vertex.h"
#include "../texture.h"

template<bool indexed, bool usePosition = true, bool useNormal = true, bool useTexCoord = false, bool useColor = false>
class Mesh {
    using Vert = Vertex<usePosition, useNormal, useTexCoord, useColor>;
public:    
    std::vector<Vert> vertices;
    std::vector<unsigned int> indices;

    Mesh(std::vector<Vert> verts,std::vector<unsigned int> ind) : vertices{verts}, indices{ind} {
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);

        glBindVertexArray(VAO);
        
        if constexpr(indexed) {
            glGenBuffers(1, &EBO);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);
        }

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vert), vertices.data(), GL_STATIC_DRAW);
        
        if constexpr(usePosition) {
            std::cout << "Using position" << std::endl;
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vert), (void*)offsetof(Vert, position));
        }

        if constexpr(useNormal) {
            std::cout << "Using normal" << std::endl;
            glEnableVertexAttribArray(1);
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vert), (void*)offsetof(Vert, normal));
        }

        if constexpr(useTexCoord) {
            std::cout << "Using texcoord" << std::endl;
            glEnableVertexAttribArray(2);
            glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vert), (void*)offsetof(Vert, texCoord));
        }

        if constexpr(useColor) {
            std::cout << "Using color" << std::endl;
            glEnableVertexAttribArray(3);
            glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vert), (void*)offsetof(Vert, color));
        }
    }
    
    void Draw(Shader& shader) {
        // unsigned int diffuseNr = 1;
        // unsigned int specularNr = 1;
        // std::string name;
        // unsigned int num;
        // for(unsigned int i = 0; i < textures.size(); i++) {
        //     glActiveTexture(GL_TEXTURE0 + i);

        //     switch(textures[i]->type) {
        //         case DIFFUSE:
        //             name = "texture_diffuse" + std::to_string(diffuseNr++);
        //             break;
        //         case SPECULAR:
        //             name = "texture_specular" + std::to_string(specularNr++);
        //             break;
        //         default:
        //             throw std::runtime_error("Texture type unknown");
        //             break;         
        //     };
        //     shader.set(("material" + name).c_str(), i);
        //     glBindTexture(GL_TEXTURE_2D, textures[i]->ID);
        // }
        // glActiveTexture(GL_TEXTURE0);

        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
        // glBindVertexArray(0);
    }
private:
    unsigned int VAO, VBO, EBO;
};