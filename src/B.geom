#version 400
layout(triangles) in;

layout(triangle_strip, max_vertices=3) out;

uniform mat4 mvpmatrix;

in VS_OUT {
	vec4 FragPos;
	vec4 Color;
} gl_in[];

out Vertex {
	vec4 FragPos;
	vec4 Normal;
	vec4 Color;
} Fragvertex;

void main() {

	
	EndPrimitive();
}