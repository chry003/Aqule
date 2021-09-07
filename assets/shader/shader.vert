#version 330 core

layout (location = 0) in vec4 position;

out vec4 pos;

void main()
{
	pos = position;
	gl_Position = position;
};