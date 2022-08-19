#version 410 core
layout (location = 0) in vec3 vPos;
layout (location = 1) in vec3 vColor;
layout (location = 2) in vec2 vTexCoord;

out vec3 vertexColor;
out vec2 texCoord;

uniform mat4 transform;

void main()
{
   gl_Position = transform * vec4(vPos, 1.0);
   vertexColor = vColor;
   texCoord = vec2(vTexCoord.x, vTexCoord.y);
}