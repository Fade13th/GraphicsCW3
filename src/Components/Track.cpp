#include "ColusseumBase.h"

static int size = 0;
static int sectors = 64;

static GLdouble* rotateXY(GLdouble point[], float theta) {
	GLdouble* n = new GLdouble[3];
	n[0] = cos(theta) * point[0] - sin(theta) * point[1];
	n[1] = sin(theta) * point[0] + cos(theta) * point[1];
	n[2] = point[2];
	return n;
}

struct Vertex* makeTrack(float innerSize, float outerSize, float height, glm::vec3 colour) {
	float innerRing[sectors + 2][2];
	float outerRing[sectors + 2][2];

	GLfloat R = colour[0];
	GLfloat G = colour[1];
	GLfloat B = colour[2];

	GLdouble rotatePointInner[2] = { 0.0, innerSize };
	GLdouble rotatePointOuter[2] = { 0.0, outerSize };

	int i = 0;
	GLdouble modifier = -0.5;

	for (int j = 0; j < sectors + 2; j++) {
		if (j == (((sectors + 2) / 2))) {
			innerRing[j][0] = innerRing[j - 1][0] + 1;
			innerRing[j][1] = innerRing[j - 1][1];

			outerRing[j][0] = outerRing[j - 1][0] + 1;
			outerRing[j][1] = outerRing[j - 1][1];

			modifier = 1.5;

			continue;
		}
		else if (j == (sectors + 2)) {
			innerRing[j][0] = innerRing[j - 1][0] - 1;
			innerRing[j][1] = innerRing[j - 1][1];

			outerRing[j][0] = outerRing[j - 1][0] - 1;
			outerRing[j][1] = outerRing[j - 1][1];

			modifier = -0.5;

			continue;
		}

		float theta1 = i * (2 * M_PI / sectors);

		GLdouble* a = rotateXY(rotatePointInner, theta1);
		innerRing[j][0] = a[0] + modifier;
		innerRing[j][1] = a[1];

		GLdouble* b = rotateXY(rotatePointOuter, theta1);
		outerRing[j][0] = b[0] + modifier;
		outerRing[j][1] = b[1];

		i++;
	}

	size = (sectors + 2) * 3 * 8;

	struct Vertex *current;
	current = new struct Vertex[size];

	int k = 0;

	for (int i = 0; i < sectors + 2; i++) {
		int j = i + 1;

		if (j == sectors + 2) j = 0;

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
		current[k++] = (Vertex) { { innerRing[j][0], innerRing[j][1], 0.0 }, { R, G, B } };
		current[k++] = (Vertex) { { innerRing[i][0], innerRing[i][1], height }, { R, G, B } };

		current[k++] = (Vertex) { { innerRing[j][0], innerRing[j][1], height }, { R, G, B } };
		current[k++] = (Vertex) { { innerRing[i][0], innerRing[i][1], height }, { R, G, B } };
		current[k++] = (Vertex) { { innerRing[j][0], innerRing[j][1], 0.0 }, { R, G, B } };


		current[k++] = (Vertex) { { outerRing[i][0], outerRing[i][1], 0.0 }, { R, G, B } };
		current[k++] = (Vertex) { { outerRing[j][0], outerRing[j][1], 0.0 }, { R, G, B } };
		current[k++] = (Vertex) { { outerRing[i][0], outerRing[i][1], height }, { R, G, B } };

		current[k++] = (Vertex) { { outerRing[j][0], outerRing[j][1], height }, { R, G, B } };
		current[k++] = (Vertex) { { outerRing[i][0], outerRing[i][1], height }, { R, G, B } };
		current[k++] = (Vertex) { { outerRing[j][0], outerRing[j][1], 0.0 }, { R, G, B } };
	}

	return current;
}

void addTrack(std::vector<GLuint>& vaoArr, std::vector<GLuint>& sizes, struct Vertex* colusseum) {
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

void translateTrack(glm::vec3 translation, struct Vertex* sphere) {
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