#include "Cone.h"

static GLdouble* rotateXY(GLdouble point[], float theta) {
	GLdouble* n = new GLdouble[3];
	n[0] = cos(theta) * point[0] - sin(theta) * point[1];
	n[1] = sin(theta) * point[0] + cos(theta) * point[1];
	n[2] = point[2];
	return n;
}

static int s = 0;

struct Vertex* makeWheel(GLdouble radius, GLdouble height, glm::vec3 colour) {
	int radials = 40;
	s = radials * 4 * 3;

	struct Vertex *current;
	current = new struct Vertex[s];

	GLfloat R = colour[0];
	GLfloat G = colour[1];
	GLfloat B = colour[2];

	int k = 0;
	GLdouble rotatePoint1[3] = { 0.0, radius, 0.0 };
	GLdouble rotatePoint2[3] = { 0.0, radius, height };

	current[0] = (Vertex) { { 0.0, 0.0, 0.0 }, { R,G,B } };

	for (int i = 0; i < radials; i++) {
		float theta1 = i * (2 * M_PI / radials);
		float theta2 = (i + 1) * (2 * M_PI / radials);
		
		GLdouble* a = rotateXY(rotatePoint1, theta1);
		GLdouble* b = rotateXY(rotatePoint1, theta2);
		GLdouble* c = rotateXY(rotatePoint2, theta1);
		GLdouble* d = rotateXY(rotatePoint2, theta2);

		GLdouble* norm1 = getNormal(new GLdouble[3]{ 0,0,0 }, a, b);
		GLdouble* norm2 = getNormal(new GLdouble[3]{ 0,0,0 }, c, d);

		current[k++] = (Vertex) { {b[0], b[1], 0.0}, { R,G,B }, { norm1[0], norm1[1], norm1[2] } };
		current[k++] = (Vertex) { { 0.0, 0.0, 0.0 }, { R,G,B }, {norm1[0], norm1[1], norm1[2]} };
		current[k++] = (Vertex) { {a[0], a[1], 0.0}, { R,G,B }, {norm1[0], norm1[1], norm1[2]} };

		current[k++] = (Vertex) { {b[0], b[1], height}, { R,G,B }, { norm2[0], norm2[1], norm2[2] } };
		current[k++] = (Vertex) { { 0.0, 0.0, height}, { R,G,B }, { norm2[0], norm2[1], norm2[2] } };
		current[k++] = (Vertex) { {a[0], a[1], height}, { R,G,B }, { norm2[0], norm2[1], norm2[2] } };

		GLdouble* norm3 = getNormal(b, c, a);
		GLdouble* norm4 = getNormal(b, d, c);

		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, {norm3[0], norm3[1], norm3[2]} };
		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm3[0], norm3[1], norm3[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm3[0], norm3[1], norm3[2] } };

		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm4[0], norm4[1], norm4[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm4[0], norm4[1], norm4[2] } };
		current[k++] = (Vertex) { {d[0], d[1], d[2]}, { R,G,B }, { norm4[0], norm4[1], norm4[2] } };
	}

	for (int i = 0; i < s; i++) {
		GLdouble x = current[i].position[0];
		GLdouble z = current[i].position[2];

		current[i].position[0] = z;
		current[i].position[2] = x;
	}

	return current;
}

void addWheel(std::vector<GLuint>& vaoArr, std::vector<GLuint>& sizes, struct Vertex* cone) {
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

void translateWheel(glm::vec3 translation, struct Vertex* sphere) {
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