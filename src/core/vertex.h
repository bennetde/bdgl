#pragma once
#include <glm/glm.hpp>
#include <type_traits>

using VPosition = glm::vec3;
using VNormal = glm::vec3;
using VTexCoord = glm::vec2;
using VColor = glm::vec3;

struct Empty {};

template<bool usePosition = true, bool useNormal = true, bool useTexCoord = false, bool useColor = false>
struct Vertex {
    [[no_unique_address]] std::conditional_t<usePosition, VPosition, Empty> position;
    [[no_unique_address]] std::conditional_t<useNormal, VNormal, Empty> normal;
    [[no_unique_address]] std::conditional_t<useTexCoord, VTexCoord, Empty> texCoord;
    [[no_unique_address]] std::conditional_t<useColor, VColor, Empty> color;
};