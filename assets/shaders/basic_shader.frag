#version 460 core
out vec4 frag_color;

uniform float u_time;

void main()
{
	float col = ((sin(u_time) + 1) / 2);

	frag_color = vec4(col, col, col, 1.0);
}