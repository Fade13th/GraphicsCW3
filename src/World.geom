#version 400
layout(triangles) in;

layout(triangle_strip, max_vertices=3) out;

in VS_OUT {
	vec3 FragPos;
	vec3 Color;
	vec3 Normal;
} gs_in[];

out VS_OUT {
	vec3 FragPos;
	vec3 Color;
	vec3 Normal;
} gs_out;

uniform mat4 mvpmatrix;
uniform vec3 rotCenter;
uniform float angle;
uniform float move;

void main() {
	vec3 V = gs_in[1].FragPos - gs_in[0].FragPos;
	vec3 W = gs_in[2].FragPos - gs_in[0].FragPos;

	double nx = (V.y * W.z) - (V.z * W.y);
	double ny = (V.z * W.x) - (V.x * W.z);
	double nz = (V.x * W.y) - (V.y * W.x);

	double ntot = abs(nx) + abs(ny) + abs(nz);

	vec3 norm = vec3(nx/ntot, ny/ntot, nz/ntot);

	for (int i = 0; i < 3; i++) {
		if (move> 0.5) {
			double x_rotated = cos(angle) * (gs_in[i].FragPos.x-rotCenter.x) - sin(angle) * (gs_in[i].FragPos.y-rotCenter.y) + rotCenter.x;
			double y_rotated = sin(angle) * (gs_in[i].FragPos.x-rotCenter.x) + cos(angle) * (gs_in[i].FragPos.y-rotCenter.y) + rotCenter.y;

			vec3 pos = vec3(x_rotated, y_rotated, gs_in[i].FragPos.z);

			gl_Position = mvpmatrix * vec4(pos, 1);
		
			gs_out.FragPos = pos;
		}
		else {
			gl_Position = mvpmatrix * vec4(gs_in[i].FragPos, 1);

			gs_out.FragPos = gs_in[i].FragPos;
		}
		gs_out.Color = gs_in[i].Color;
		gs_out.Normal = norm;

		EmitVertex();
	}
	EndPrimitive();
}