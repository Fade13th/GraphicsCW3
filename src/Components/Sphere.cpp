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

static int s = 0;

struct Vertex* makeSphere(int divisions, float radius, glm::vec3 colour) {
	int size = 24;
	s = size;

	GLfloat R = colour[0];
	GLfloat G = colour[1];
	GLfloat B = colour[2];

	struct Vertex *current;

	current = new Vertex[size]{
		{ { 1.0, 0.0, 0.0 },{ R,  0.0f,  0.0f } },
		{ { 0.0, 1.0, 0.0 },{ R,  0.0f,  0.0f } },
		{ { 0.0, 0.0, 1.0 },{ R,  0.0f,  0.0f } },

		{ { -1.0, 0.0, 0.0 },{ 1.0f,  0.0f,  0.0f } },
		{ { 0.0, 0.0, 1.0 },{ 1.0f,  0.0f,  0.0f } },
		{ { 0.0, 1.0, 0.0 },{ 1.0f,  0.0f,  0.0f } },

		{ { 1.0, 0.0, 0.0 },{ 1.0f,  0.0f,  0.0f } },
		{ { 0.0, 0.0, 1.0 },{ 1.0f,  0.0f,  0.0f } },
		{ { 0.0, -1.0, 0.0 },{ 1.0f,  0.0f,  0.0f } },

		{ { -1.0, 0.0, 0.0 },{ 1.0f,  0.0f,  0.0f } },
		{ { 0.0, -1.0, 0.0 },{ 1.0f,  0.0f,  0.0f } },
		{ { 0.0, 0.0, 1.0 },{ 1.0f,  0.0f,  0.0f } },

		{ { 1.0, 0.0, 0.0 },{ 1.0f,  0.0f,  0.0f } },
		{ { 0.0, 0.0, -1.0 },{ 1.0f,  0.0f,  0.0f } },
		{ { 0.0, 1.0, 0.0 },{ 1.0f,  0.0f,  0.0f } },

		{ { -1.0, 0.0, 0.0 },{ 1.0f,  0.0f,  0.0f } },
		{ { 0.0, 1.0, 0.0 },{ 1.0f,  0.0f,  0.0f } },
		{ { 0.0, 0.0, -1.0 },{ 1.0f,  0.0f,  0.0f } },

		{ { 1.0, 0.0, 0.0 },{ 1.0f,  0.0f,  0.0f } },
		{ { 0.0, -1.0, 0.0 },{ 1.0f,  0.0f,  0.0f } },
		{ { 0.0, 0.0, -1.0 },{ 1.0f,  0.0f,  0.0f } },

		{ { -1.0, 0.0, 0.0 },{ 1.0f,  0.0f,  0.0f } },
		{ { 0.0, 0.0, -1.0 },{ 1.0f,  0.0f,  0.0f } },
		{ { 0.0, -1.0, 0.0 },{ 1.0f,  0.0f,  0.0f } }
	};

	for (int i = 0; i < divisions; i++) {
		s = size * 16;
		struct Vertex next[s];

		int k = 0;

		for (int j = 0; j < (size)-2; j += 3) {
			Vertex a = current[j];
			Vertex b = current[j + 1];
			Vertex c = current[j + 2];

			GLdouble *PosA1 = toBoundary(a.position, radius);
			GLdouble *PosB1 = toBoundary(a.position, b.position, radius);
			GLdouble *PosC1 = toBoundary(a.position, c.position, radius);

			GLdouble* norm1 = getNormal(PosB1, PosA1, PosC1);

			next[k++] = (Vertex) { { PosA1[0], PosA1[1], PosA1[2] }, { R, G, B }, {norm1[0], norm1[1], norm1[2]} };
			next[k++] = (Vertex) { { PosB1[0], PosB1[1], PosB1[2] }, { R, G, B }, {norm1[0], norm1[1], norm1[2]} };
			next[k++] = (Vertex) { { PosC1[0], PosC1[1], PosC1[2] }, { R, G, B }, {norm1[0], norm1[1], norm1[2]} };

			GLdouble *PosA2 = toBoundary(b.position, radius);
			GLdouble *PosB2 = toBoundary(b.position, c.position, radius);
			GLdouble *PosC2 = toBoundary(a.position, b.position, radius);

			GLdouble* norm2 = getNormal(PosA2, PosB2, PosC2);

			next[k++] = (Vertex) { { PosA2[0], PosA2[1], PosA2[2] }, { R, G, B }, {norm2[0], norm2[1], norm2[2]} };
			next[k++] = (Vertex) { { PosB2[0], PosB2[1], PosB2[2] }, { R, G, B }, {norm2[0], norm2[1], norm2[2]} };
			next[k++] = (Vertex) { { PosC2[0], PosC2[1], PosC2[2] }, { R, G, B }, {norm2[0], norm2[1], norm2[2]} };

			GLdouble *PosA3 = toBoundary(c.position, radius);
			GLdouble *PosB3 = toBoundary(a.position, c.position, radius);
			GLdouble *PosC3 = toBoundary(b.position, c.position, radius);

			GLdouble* norm3 = getNormal(PosA3, PosB3, PosC3);

			next[k++] = (Vertex) { { PosA3[0], PosA3[1], PosA3[2] }, { R, G, B }, {norm3[0], norm3[1], norm3[2]} };
			next[k++] = (Vertex) { { PosB3[0], PosB3[1], PosB3[2] }, { R, G, B }, {norm3[0], norm3[1], norm3[2]} };
			next[k++] = (Vertex) { { PosC3[0], PosC3[1], PosC3[2] }, { R, G, B }, {norm3[0], norm3[1], norm3[2]} };

			GLdouble *PosA4 = toBoundary(a.position, b.position, radius);
			GLdouble *PosB4 = toBoundary(b.position, c.position, radius);
			GLdouble *PosC4 = toBoundary(a.position, c.position, radius);

			GLdouble* norm4 = getNormal(PosA4, PosB4, PosC4);

			next[k++] = (Vertex) { { PosA4[0], PosA4[1], PosA4[2] }, { R, G, B }, {norm4[0], norm4[1], norm4[2]} };
			next[k++] = (Vertex) { { PosB4[0], PosB4[1], PosB4[2] }, { R, G, B }, {norm4[0], norm4[1], norm4[2]} };
			next[k++] = (Vertex) { { PosC4[0], PosC4[1], PosC4[2] }, { R, G, B }, {norm4[0], norm4[1], norm4[2]} };
		}
		size *= 4;
		current = next;
	}

	return current;
}

void addSphere(std::vector<GLuint>& vaoArr, std::vector<GLuint>& sizes, struct Vertex* sphere) {
	GLuint vao, vbo[1];

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);

	glBufferData(GL_ARRAY_BUFFER, s * sizeof(struct Vertex), sphere, GL_STATIC_DRAW);

	glVertexAttribPointer((GLuint)0, 3, GL_DOUBLE, GL_FALSE, sizeof(struct Vertex), (const GLvoid*)offsetof(struct Vertex, position));
	glEnableVertexAttribArray(0);

	glVertexAttribPointer((GLuint)1, 3, GL_FLOAT, GL_FALSE, sizeof(struct Vertex), (const GLvoid*)offsetof(struct Vertex, color));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer((GLuint)2, 3, GL_FLOAT, GL_FALSE, sizeof(struct Vertex), (const GLvoid*)offsetof(struct Vertex, normal));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0);

	vaoArr.push_back(vao);
	sizes.push_back(s);
}

void translateSphere(glm::vec3 translation, struct Vertex* sphere) {
	for (int i = 0; i < s; i += 3) {
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