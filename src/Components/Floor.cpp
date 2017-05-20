#include "Floor.h"

static int size = 0;

static GLdouble* rotateXY(GLdouble point[], float theta) {
	GLdouble* n = new GLdouble[3];
	n[0] = cos(theta) * point[0] - sin(theta) * point[1];
	n[1] = sin(theta) * point[0] + cos(theta) * point[1];
	n[2] = point[2];
	return n;
}

struct Vertex* makeFloor(float radius, glm::vec3 colour) {
	int sectors = 40;

	GLfloat R = colour[0];
	GLfloat G = colour[1];
	GLfloat B = colour[2];

	GLdouble rotatePoint[3] = { 0.0, radius, 0.0 };

	size = sectors * 3;

	struct Vertex *current;
	current = new struct Vertex[size];

	int k = 0;

	for (int i = 0; i < sectors; i++) {
		float theta1 = i * (2 * M_PI / sectors);
		float theta2 = (i + 1) * (2 * M_PI / sectors);

		GLdouble* a = rotateXY(rotatePoint, theta1);
		GLdouble* b = rotateXY(rotatePoint, theta2);
		GLdouble* norm1 = getNormal(new GLdouble[3]{ 0,0,0 }, a, b);

		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm1[0], norm1[1], norm1[2] } };
		current[k++] = (Vertex) { { 0.0, 0.0, 0.0 }, { R,G,B }, { norm1[0], norm1[1], norm1[2] } };
		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm1[0], norm1[1], norm1[2] } };
	}

	return current;
}

void addFloor(std::vector<GLuint>& vaoArr, std::vector<GLuint>& sizes, struct Vertex* colusseum) {
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

	glVertexAttribPointer((GLuint)2, 3, GL_FLOAT, GL_FALSE, sizeof(struct Vertex), (const GLvoid*)offsetof(struct Vertex, normal));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0);

	vaoArr.push_back(vao);
	sizes.push_back(size);
}

void translateFloor(glm::vec3 translation, struct Vertex* sphere) {
	for (int i = 0; i < size; i += 3) {
		GLdouble* pos1 = sphere[i].position;
		GLdouble* pos2 = sphere[i + 1].position;
		GLdouble* pos3 = sphere[i + 2].position;

		sphere[i].position[0] = pos1[0] + translation.x;
		sphere[i].position[1] = pos1[1] + translation.y;
		sphere[i].position[2] = pos1[2] + translation.z;

		sphere[i + 1].position[0] = pos2[0] + translation.x;
		sphere[i + 1].position[1] = pos2[1] + translation.y;
		sphere[i + 1].position[2] = pos2[2] + translation.z;

		sphere[i + 2].position[0] = pos3[0] + translation.x;
		sphere[i + 2].position[1] = pos3[1] + translation.y;
		sphere[i + 2].position[2] = pos3[2] + translation.z;

		GLdouble* norm = getNormal(pos1, pos2, pos3);

		sphere[i].normal[0] = norm[0];
		sphere[i].normal[1] = norm[1];
		sphere[i].normal[2] = norm[2];

		sphere[i + 1].normal[0] = norm[0];
		sphere[i + 1].normal[1] = norm[1];
		sphere[i + 1].normal[2] = norm[2];

		sphere[i + 2].normal[0] = norm[0];
		sphere[i + 2].normal[1] = norm[1];
		sphere[i + 2].normal[2] = norm[2];
	}
}