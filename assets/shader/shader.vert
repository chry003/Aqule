#version 330 core

layout (location = 0) in vec4 position;

uniform mat4 u_ViewPorjectionMatrix;
uniform mat4 u_ModalViewMatrix;

void main()
{
	gl_Position = u_ViewPorjectionMatrix * u_ModalViewMatrix * position;
};