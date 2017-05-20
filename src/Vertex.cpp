#include "Vertex.h"

GLdouble* getNormal(glm::vec3 A, glm::vec3 B, glm::vec3 C) {
	glm::vec3 V = B - A;
	glm::vec3 W = C - A;

	GLdouble nx = (V.y * W.z) - (V.z * W.y);
	GLdouble ny = (V.z * W.x) - (V.x * W.z);
	GLdouble nz = (V.x * W.y) - (V.y * W.x);

	GLdouble ntot = abs(nx) + abs(ny) + abs(nz);
	
	GLdouble* norm = new GLdouble[3];

	norm[0] = nx / ntot;
	norm[1] = ny / ntot;
	norm[2] = nz / ntot;

	return norm;
}

GLdouble* getNormal(GLdouble A[], GLdouble B[], GLdouble C[]) {
	return getNormal(glm::vec3(A[0], A[1], A[2]), glm::vec3(B[0], B[1], B[2]), glm::vec3(C[0], C[1], C[2]));
}