#include "Cone.h"

static GLdouble* rotateXY(GLdouble point[], float theta) {
	GLdouble* n = new GLdouble[3];
	n[0] = cos(theta) * point[0] - sin(theta) * point[1];
	n[1] = sin(theta) * point[0] + cos(theta) * point[1];
	n[2] = point[2];
	return n;
}

static int size = 0;

struct Vertex* makeCone() {
	int radials = 40;
	size = radials * 2 * 3;

	struct Vertex *current;
	current = new struct Vertex[size];

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

void addCone(std::vector<GLuint>& vaoArr, struct Vertex* cone) {
	GLuint vao, vbo[1];

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	print(size);

	glBufferData(GL_ARRAY_BUFFER, size * sizeof(struct Vertex), cone, GL_STATIC_DRAW);

	glVertexAttribPointer((GLuint)0, 3, GL_DOUBLE, GL_FALSE, sizeof(struct Vertex), (const GLvoid*)offsetof(struct Vertex, position));
	glEnableVertexAttribArray(0);

	glVertexAttribPointer((GLuint)1, 3, GL_FLOAT, GL_FALSE, sizeof(struct Vertex), (const GLvoid*)offsetof(struct Vertex, color));

	glEnableVertexAttribArray(1);
	glBindVertexArray(0);

	vaoArr.push_back(vao);
}

void translateCone(glm::vec3 translation, struct Vertex* sphere) {
	for (int i = 0; i < size; i++) {
		GLdouble* pos = sphere[i].position;
		sphere[i].position[0] = pos[0] + translation.x;
		sphere[i].position[1] = pos[1] + translation.y;
		sphere[i].position[2] = pos[2] + translation.z;
	}
}