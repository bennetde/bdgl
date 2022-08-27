#version 410 core
layout (location = 0) in vec3 vPos;
layout (location = 1) in vec3 vNormal;
layout (location = 2) in vec2 vTexCoord;

//out vec3 vertexColor;
out vec2 texCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;


void main()
{
   gl_Position = projection * view * model * vec4(vPos, 1.0);
   //vertexColor = vColor;
   texCoord = vec2(vTexCoord.x, vTexCoord.y);
}