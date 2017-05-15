#include "Cone.h"

static GLdouble* rotateXY(GLdouble point[], float theta) {
	GLdouble* n = new GLdouble[3];
	n[0] = cos(theta) * point[0] - sin(theta) * point[1];
	n[1] = sin(theta) * point[0] + cos(theta) * point[1];
	n[2] = point[2];
	printf("%f, %f\n", n[0], n[1]);
	return n;
}

struct Vertex* makeCone() {
	int radials = 40;

	struct Vertex *current;
	current = new struct Vertex[radials * 2 * 3];

	int k = 0;
	GLdouble rotatePoint[3] = { 0.0, 1.0, 0.0 };

	for (int i = 0; i < radials; i++) {
		float theta1 = i * (2 * M_PI / 40.0f);
		float theta2 = (i + 1) * (2 * M_PI / 40.0f);

		current[k++] = (Vertex) { { 0.0, 0.0, 0.0 }, { 1.0f,  0.0f,  0.0f } };
		GLdouble* a = rotateXY(rotatePoint, theta1);
		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { 1.0f, 0.0f, 0.0f } };
		GLdouble* b = rotateXY(rotatePoint, theta2);
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { 1.0f, 0.0f, 0.0f } };

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { 1.0f, 0.0f, 0.0f } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { 1.0f, 0.0f, 0.0f } };
		current[k++] = (Vertex) { {0.0, 0.0, 3.0}, { 1.0f, 0.0f, 0.0f } };
	}

	return current;
}