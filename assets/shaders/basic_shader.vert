#version 460 core
layout (location = 0) in vec3 VPOS;

void main()
{
	gl_Position = vec4(VPOS, 1.0);
}
