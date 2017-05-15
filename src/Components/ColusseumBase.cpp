#include "ColusseumBase.h"

static int size = 0;
static int sectors = 48;

static float R = 0.4f;
static float G = 0.4f;
static float B = 0.2f;

static GLdouble* rotateXY(GLdouble point[], float theta) {
	GLdouble* n = new GLdouble[3];
	n[0] = cos(theta) * point[0] - sin(theta) * point[1];
	n[1] = sin(theta) * point[0] + cos(theta) * point[1];
	n[2] = point[2];
	return n;
}

struct Vertex* makeColusseumBase(float innerSize, float outerSize, float height) {
	float innerRing[sectors][2];
	float outerRing[sectors][2];

	GLdouble rotatePointInner[2] = { 0.0, innerSize };
	GLdouble rotatePointOuter[2] = { 0.0, outerSize };

	for (int i = 0; i < sectors; i++) {
		float theta1 = i * (2 * M_PI / sectors);

		GLdouble* a = rotateXY(rotatePointInner, theta1);
		innerRing[i][0] = a[0];
		innerRing[i][1] = a[1];

		GLdouble* b = rotateXY(rotatePointOuter, theta1);
		outerRing[i][0] = b[0];
		outerRing[i][1] = b[1];
	}

	size = sectors * 3 * 8;

	struct Vertex *current;
	current = new struct Vertex[size];

	int k = 0;

	for (int i = 0; i < sectors; i++) {
		int j = i + 1;

		if (j == sectors) j = 0;

		current[k++] = (Vertex) { { innerRing[i][0], innerRing[i][1], 0.0 }, { R, G, B } };
		current[k++] = (Vertex) { { innerRing[j][0], innerRing[j][1], 0.0 }, { R, G, B } };
		current[k++] = (Vertex) { { outerRing[i][0], outerRing[i][1], 0.0 }, { R, G, B } };

		current[k++] = (Vertex) { { innerRing[j][0], innerRing[j][1], 0.0 }, { R, G, B } };
		current[k++] = (Vertex) { { outerRing[j][0], outerRing[j][1], 0.0 }, { R, G, B } };
		current[k++] = (Vertex) { { outerRing[i][0], outerRing[i][1], 0.0 }, { R, G, B } };


		current[k++] = (Vertex) { { innerRing[i][0], innerRing[i][1], height }, { R, G, B } };
		current[k++] = (Vertex) { { innerRing[j][0], innerRing[j][1], height }, { R, G, B } };
		current[k++] = (Vertex) { { outerRing[i][0], outerRing[i][1], height }, { R, G, B } };

		current[k++] = (Vertex) { { innerRing[j][0], innerRing[j][1], height }, { R, G, B } };
		current[k++] = (Vertex) { { outerRing[j][0], outerRing[j][1], height }, { R, G, B } };
		current[k++] = (Vertex) { { outerRing[i][0], outerRing[i][1], height }, { R, G, B } };


		current[k++] = (Vertex) { { innerRing[i][0], innerRing[i][1], 0.0 }, { R, G, B } };
		current[k++] = (Vertex) { { innerRing[i][0], innerRing[i][1], height }, { R, G, B } };
		current[k++] = (Vertex) { { innerRing[j][0], innerRing[j][1], 0.0 }, { R, G, B } };

		current[k++] = (Vertex) { { innerRing[j][0], innerRing[j][1], height }, { R, G, B } };
		current[k++] = (Vertex) { { innerRing[i][0], innerRing[i][1], height }, { R, G, B } };
		current[k++] = (Vertex) { { innerRing[j][0], innerRing[j][1], 0.0 }, { R, G, B } };


		current[k++] = (Vertex) { { outerRing[i][0], outerRing[i][1], 0.0 }, { R, G, B } };
		current[k++] = (Vertex) { { outerRing[i][0], outerRing[i][1], height }, { R, G, B } };
		current[k++] = (Vertex) { { outerRing[j][0], outerRing[j][1], 0.0 }, { R, G, B } };

		current[k++] = (Vertex) { { outerRing[j][0], outerRing[j][1], height }, { R, G, B } };
		current[k++] = (Vertex) { { outerRing[i][0], outerRing[i][1], height }, { R, G, B } };
		current[k++] = (Vertex) { { outerRing[j][0], outerRing[j][1], 0.0 }, { R, G, B } };
	}

	return current;
}

void addColusseumBase(std::vector<GLuint>& vaoArr, struct Vertex* colusseum) {
	GLuint vao, vbo[1];

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);

	glBufferData(GL_ARRAY_BUFFER, size * sizeof(struct Vertex), colusseum, GL_STATIC_DRAW);

	glVertexAttribPointer((GLuint)0, 3, GL_DOUBLE, GL_FALSE, sizeof(struct Vertex), (const GLvoid*)offsetof(struct Vertex, position));
	glEnableVertexAttribArray(0);

	glVertexAttribPointer((GLuint)1, 3, GL_FLOAT, GL_FALSE, sizeof(struct Vertex), (const GLvoid*)offsetof(struct Vertex, color));

	glEnableVertexAttribArray(1);
	glBindVertexArray(0);

	vaoArr.push_back(vao);
}

void translateColusseumBase(glm::vec3 translation, struct Vertex* colusseum) {
	for (int i = 0; i < size; i++) {
		GLdouble* pos = colusseum[i].position;
		colusseum[i].position[0] = pos[0] + translation.x;
		colusseum[i].position[1] = pos[1] + translation.y;
		colusseum[i].position[2] = pos[2] + translation.z;
	}
}