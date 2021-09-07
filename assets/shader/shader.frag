#version 330 core

// Ouput data
layout (location = 0) out vec4 color;

uniform vec4 sh_color = vec4(1, 0, 0, 1);

in vec4 pos;

void main()
{

	// Output color = red 
	// color = pos * 0.5 + 0.5;
	color = sh_color;
	// color = vec4(142 / 255.0f, 10 / 255.0f, 172 / 255.0f, 1.0f);

}