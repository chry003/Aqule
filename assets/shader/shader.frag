#version 330 core

layout (location = 0) out vec4 color;

uniform vec4 sh_color;
uniform vec2 light_pos;

void main()
{
	color = sh_color;
}