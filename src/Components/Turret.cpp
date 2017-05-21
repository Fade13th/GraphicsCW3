#include "Turret.h"


static int s = 0;

struct Vertex* makeTurret(GLdouble width, GLdouble height, GLdouble length, glm::vec3 colour) {
	s = 12 * 3;

	struct Vertex *current;
	current = new struct Vertex[s];

	GLfloat R = colour[0];
	GLfloat G = colour[1];
	GLfloat B = colour[2];

	int k = 0;

	GLdouble* a;
	GLdouble* b;
	GLdouble* c;

	GLdouble w = width / 2;
	GLdouble h = height;
	GLdouble l = length / 2;

	GLdouble* norm;

	{
		a = new GLdouble[3]{ -l, -w, 0 };
		b = new GLdouble[3]{ l, -w, 0 };
		c = new GLdouble[3]{ -l, w, 0 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ -l, w, 0 };
		b = new GLdouble[3]{ l, -w, 0 };
		c = new GLdouble[3]{ l, w, 0 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ -l, -w, 0 };
		b = new GLdouble[3]{ l, -w, 0 };
		c = new GLdouble[3]{ -l, -2*w/3, h };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ -l, -2*w/3, h };
		b = new GLdouble[3]{ l, -w, 0 };
		c = new GLdouble[3]{ l / 2, -2*w/3, h };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ -l, w, 0 };
		b = new GLdouble[3]{ l, w, 0 };
		c = new GLdouble[3]{ -l, 2 * w / 3, h };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ -l, 2 * w / 3, h };
		b = new GLdouble[3]{ l, w, 0 };
		c = new GLdouble[3]{ l / 2, 2 * w / 3, h };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ l, -w, 0 };
		b = new GLdouble[3]{ l, w, 0 };
		c = new GLdouble[3]{ l/2, -2 * w / 3, h };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ l/2, -2 * w / 3, h };
		b = new GLdouble[3]{ l, w, 0 };
		c = new GLdouble[3]{ l / 2, 2 * w / 3, h };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ -l, w, 0 };
		b = new GLdouble[3]{ -l, -w, 0 };
		c = new GLdouble[3]{ -l, 2 * w / 3, h };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ -l, 2 * w / 3, h };
		b = new GLdouble[3]{ -l, -w, 0 };
		c = new GLdouble[3]{ -l, -2 * w / 3, h };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ -l, -2 *w/3, h };
		b = new GLdouble[3]{ l/2, -2 * w/3, h };
		c = new GLdouble[3]{ -l, 2 * w / 3, h };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ -l, 2 * w / 3, h };
		b = new GLdouble[3]{ l/2, -2 * w/3, h };
		c = new GLdouble[3]{ l / 2, 2 * w / 3, h };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
	}

	return current;
}

void addTurret(std::vector<GLuint>& vaoArr, std::vector<GLuint>& sizes, struct Vertex* cone) {
	GLuint vao, vbo[1];

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	print((float)s);

	glBufferData(GL_ARRAY_BUFFER, (s) * sizeof(struct Vertex), cone, GL_STATIC_DRAW);

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

void translateTurret(glm::vec3 translation, struct Vertex* sphere) {
	for (int i = 0; i < s; i+=3) {
		GLdouble* pos1 = sphere[i].position;
		GLdouble* pos2 = sphere[i+1].position;
		GLdouble* pos3 = sphere[i+2].position;

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