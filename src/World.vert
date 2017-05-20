#version 330 core
in vec3 in_Position;
in vec3 in_Color;
in vec3 in_Normal;

uniform mat4 mvpmatrix;

// Declare an interface block; see 'Advanced GLSL' for what these are.
out VS_OUT {
    vec3 FragPos;
    vec3 Color;
    vec3 Normal;
} vs_out;

void main()
{
    gl_Position = mvpmatrix * vec4(in_Position, 1.0);
    vs_out.FragPos = in_Position;
	vs_out.Color = in_Color;
    vs_out.Normal = in_Normal;
}
