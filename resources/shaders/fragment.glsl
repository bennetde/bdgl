#version 410 core
out vec4 FragColor;
in vec2 texCoord;

uniform sampler2D texture1;
uniform sampler2D texture2;


void main()
{
   //FragColor = vec4(ourColor, 1.0);
   FragColor = mix(texture(texture1, texCoord), texture(texture2, texCoord), .5); /** vec4(ourColor, 1.0)*/
};