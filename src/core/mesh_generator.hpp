#pragma once
#include "mesh.hpp"

struct MeshGenerator {
    template <bool useVertexColors = false>
    static constexpr Mesh<true, true, true, true, useVertexColors> generateCube(const float scale = 1.f) {
        using Vert = Vertex<true, true, true, useVertexColors>;

        const std::vector<Vert> vertices {
            // Bottom face
            Vert{glm::vec3{-0.5f,-0.5f,-0.5f} * scale,  glm::vec3{0,-1,0}, glm::vec2{0., 0.}},
            Vert{glm::vec3{0.5f,-0.5f,-0.5f} * scale,   glm::vec3{0,-1,0}, glm::vec2{1., 0.}},
            Vert{glm::vec3{0.5f,-0.5f,0.5f} * scale,    glm::vec3{0,-1,0}, glm::vec2{1., 1.}},
            Vert{glm::vec3{-0.5f,-0.5f,0.5f} * scale,   glm::vec3{0,-1,0}, glm::vec2{0., 1.}},
            // Top Face
            Vert{glm::vec3{-0.5f,0.5f,-0.5f} * scale,   glm::vec3{0,1,0}, glm::vec2{0., 0.}},
            Vert{glm::vec3{0.5f,0.5f,-0.5f} * scale,    glm::vec3{0,1,0}, glm::vec2{1., 0.}},
            Vert{glm::vec3{0.5f,0.5f,0.5f} * scale,     glm::vec3{0,1,0}, glm::vec2{1., 1.}},
            Vert{glm::vec3{-0.5f,0.5f,0.5f} * scale,    glm::vec3{0,1,0}, glm::vec2{0., 1.}},
            // Front Face
            Vert{glm::vec3{-0.5f,-0.5f,0.5f} * scale,   glm::vec3{0,0,1}, glm::vec2{0., 0.}},
            Vert{glm::vec3{0.5f,-0.5f,0.5f} * scale,    glm::vec3{0,0,1}, glm::vec2{1., 0.}},
            Vert{glm::vec3{0.5f,0.5f,0.5f} * scale,     glm::vec3{0,0,1}, glm::vec2{1., 1.}},
            Vert{glm::vec3{-0.5f,0.5f,0.5f} * scale,    glm::vec3{0,0,1}, glm::vec2{0., 1.}},
            // Back Face
            Vert{glm::vec3{-0.5f,-0.5f,-0.5f} * scale,  glm::vec3{0,0,-1}, glm::vec2{0., 0.}},
            Vert{glm::vec3{0.5f,-0.5f,-0.5f} * scale,   glm::vec3{0,0,-1}, glm::vec2{1., 0.}},
            Vert{glm::vec3{0.5f,0.5f,-0.5f} * scale,    glm::vec3{0,0,-1}, glm::vec2{1., 1.}},
            Vert{glm::vec3{-0.5f,0.5f,-0.5f} * scale,   glm::vec3{0,0,-1}, glm::vec2{0., 1.}},
            // Left Face
            Vert{glm::vec3{-0.5f,-0.5f,-0.5f} * scale,  glm::vec3{-1,0,0}, glm::vec2{0., 0.}},
            Vert{glm::vec3{-0.5f,-0.5f,0.5f} * scale,   glm::vec3{-1,0,0}, glm::vec2{1., 0.}},
            Vert{glm::vec3{-0.5f,0.5f,0.5f} * scale,    glm::vec3{-1,0,0}, glm::vec2{1., 1.}},
            Vert{glm::vec3{-0.5f,0.5f,-0.5f} * scale,   glm::vec3{-1,0,0}, glm::vec2{0., 1.}},
            // Right Face
            Vert{glm::vec3{0.5f,-0.5f,0.5f} * scale,    glm::vec3{1,0,0}, glm::vec2{0, 0.}}, // 20
            Vert{glm::vec3{0.5f,-0.5f,-0.5f} * scale,   glm::vec3{1,0,0}, glm::vec2{1, 0.}},
            Vert{glm::vec3{0.5f,0.5f,-0.5f} * scale,    glm::vec3{1,0,0}, glm::vec2{1, 1.}},
            Vert{glm::vec3{0.5f,0.5f,0.5f} * scale,     glm::vec3{1,0,0}, glm::vec2{0, 1.}},
        };

        const std::vector<unsigned int> indices {
            // Bottom
            0, 1, 2,
            2, 3, 0,
            // Top
            7, 6, 5,
            5, 4, 7,
            // Back
            9, 8, 11,
            11, 10, 9,
            // Front
            12, 13, 14,
            14, 15, 12,
            // Left
            16, 17, 18,
            18, 19, 16,
            // Right
            20, 21, 22,
            22, 23, 20

        };

        return Mesh<true, true, true, true, useVertexColors>{vertices, indices};
    };
};