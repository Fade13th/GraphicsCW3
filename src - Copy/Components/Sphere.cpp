#include "Sphere.h"

static GLdouble* toBoundary(GLdouble a[], float radius) {
	float length = sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);

	if (length != 0) {
		GLdouble* newPos = new GLdouble[3];
		newPos[0] = radius*a[0] / length;
		newPos[1] = radius*a[1] / length;
		newPos[2] = radius*a[2] / length;

		return newPos;
	}
}

static GLdouble* toBoundary(GLdouble a[], GLdouble b[], float radius) {
	double combined[3];
	combined[0] = (a[0] + b[0]) / 2;
	combined[1] = (a[1] + b[1]) / 2;
	combined[2] = (a[2] + b[2]) / 2;

	return toBoundary(combined, radius);
}

struct Vertex* makeSphere(int divisions, float radius) {
	int size = 24;

	GLfloat R = 1.0f;
	GLfloat G = 1.0f;
	GLfloat B = 1.0f;

	struct Vertex *current;

	current = new Vertex[size]{
		{ { 1.0, 0.0, 0.0 },{ R,  0.0f,  0.0f } },
		{ { 0.0, 0.0, 1.0 },{ R,  0.0f,  0.0f } },
		{ { 0.0, 1.0, 0.0 },{ R,  0.0f,  0.0f } },
		{ { -1.0, 0.0, 0.0 },{ 1.0f,  0.0f,  0.0f } },
		{ { 0.0, 0.0, 1.0 },{ 1.0f,  0.0f,  0.0f } },
		{ { 0.0, 1.0, 0.0 },{ 1.0f,  0.0f,  0.0f } },
		{ { 1.0, 0.0, 0.0 },{ 1.0f,  0.0f,  0.0f } },
		{ { 0.0, 0.0, 1.0 },{ 1.0f,  0.0f,  0.0f } },
		{ { 0.0, -1.0, 0.0 },{ 1.0f,  0.0f,  0.0f } },
		{ { -1.0, 0.0, 0.0 },{ 1.0f,  0.0f,  0.0f } },
		{ { 0.0, 0.0, 1.0 },{ 1.0f,  0.0f,  0.0f } },
		{ { 0.0, -1.0, 0.0 },{ 1.0f,  0.0f,  0.0f } },
		{ { 1.0, 0.0, 0.0 },{ 1.0f,  0.0f,  0.0f } },
		{ { 0.0, 0.0, -1.0 },{ 1.0f,  0.0f,  0.0f } },
		{ { 0.0, 1.0, 0.0 },{ 1.0f,  0.0f,  0.0f } },
		{ { -1.0, 0.0, 0.0 },{ 1.0f,  0.0f,  0.0f } },
		{ { 0.0, 0.0, -1.0 },{ 1.0f,  0.0f,  0.0f } },
		{ { 0.0, 1.0, 0.0 },{ 1.0f,  0.0f,  0.0f } },
		{ { 1.0, 0.0, 0.0 },{ 1.0f,  0.0f,  0.0f } },
		{ { 0.0, 0.0, -1.0 },{ 1.0f,  0.0f,  0.0f } },
		{ { 0.0, -1.0, 0.0 },{ 1.0f,  0.0f,  0.0f } },
		{ { -1.0, 0.0, 0.0 },{ 1.0f,  0.0f,  0.0f } },
		{ { 0.0, 0.0, -1.0 },{ 1.0f,  0.0f,  0.0f } },
		{ { 0.0, -1.0, 0.0 },{ 1.0f,  0.0f,  0.0f } }
	};

	for (int i = 0; i < divisions; i++) {
		struct Vertex next[size * 16];

		int k = 0;

		for (int j = 0; j < (size)-2; j += 3) {
			Vertex a = current[j];
			Vertex b = current[j + 1];
			Vertex c = current[j + 2];

			GLdouble *PosA1 = toBoundary(a.position, radius);
			GLdouble *PosB1 = toBoundary(a.position, b.position, radius);
			GLdouble *PosC1 = toBoundary(a.position, c.position, radius);

			next[k++] = (Vertex) { { PosA1[0], PosA1[1], PosA1[2] }, { R, G, B } };
			next[k++] = (Vertex) { { PosB1[0], PosB1[1], PosB1[2] }, { R, G, B } };
			next[k++] = (Vertex) { { PosC1[0], PosC1[1], PosC1[2] }, { R, G, B } };

			GLdouble *PosA2 = toBoundary(b.position, radius);
			GLdouble *PosB2 = toBoundary(a.position, b.position, radius);
			GLdouble *PosC2 = toBoundary(b.position, c.position, radius);

			next[k++] = (Vertex) { { PosA2[0], PosA2[1], PosA2[2] }, { R, G, B } };
			next[k++] = (Vertex) { { PosB2[0], PosB2[1], PosB2[2] }, { R, G, B } };
			next[k++] = (Vertex) { { PosC2[0], PosC2[1], PosC2[2] }, { R, G, B } };

			GLdouble *PosA3 = toBoundary(c.position, radius);
			GLdouble *PosB3 = toBoundary(a.position, c.position, radius);
			GLdouble *PosC3 = toBoundary(b.position, c.position, radius);

			next[k++] = (Vertex) { { PosA3[0], PosA3[1], PosA3[2] }, { R, G, B } };
			next[k++] = (Vertex) { { PosB3[0], PosB3[1], PosB3[2] }, { R, G, B } };
			next[k++] = (Vertex) { { PosC3[0], PosC3[1], PosC3[2] }, { R, G, B } };

			GLdouble *PosA4 = toBoundary(a.position, b.position, radius);
			GLdouble *PosB4 = toBoundary(b.position, c.position, radius);
			GLdouble *PosC4 = toBoundary(a.position, c.position, radius);

			next[k++] = (Vertex) { { PosA4[0], PosA4[1], PosA4[2] }, { R, G, B } };
			next[k++] = (Vertex) { { PosB4[0], PosB4[1], PosB4[2] }, { R, G, B } };
			next[k++] = (Vertex) { { PosC4[0], PosC4[1], PosC4[2] }, { R, G, B } };
		}
		size *= 4;
		current = next;
	}

	return current;
}