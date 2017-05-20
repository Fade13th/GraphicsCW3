#include "Triangle.h"

struct Vertex* makeTri() {
	GLfloat R = 1.0f;
	GLfloat G = 1.0f;
	GLfloat B = 1.0f;

	struct Vertex *current;

	GLdouble* norm = getNormal(glm::vec3(1, 0, 0), glm::vec3(0, 0, 1), glm::vec3(0, 1, 0));

	current = new Vertex[3]{
		{ { 1.0, 0.0, 0.0 },{ R,  G,B }, {0, 0, -1} },
		{ { 0.0, 1.0, 0.0 },{ R,  G,B },{ 0, 0, -1 } },
		{ { -1.0, .0, 0.0 },{ R,  G,B },{ 0, 0, -1 } },
	};

	print((float)norm[0]); print((float)norm[1]); print((float)norm[2]);

	return current;
}

void addTri(std::vector<GLuint>& vaoArr, std::vector<GLuint>& sizes, struct Vertex* tri) {
	GLuint vao, vbo[1];

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);

	glBufferData(GL_ARRAY_BUFFER, 3 * sizeof(struct Vertex), tri, GL_STATIC_DRAW);

	glVertexAttribPointer((GLuint)0, 3, GL_DOUBLE, GL_FALSE, sizeof(struct Vertex), (const GLvoid*)offsetof(struct Vertex, position));
	glEnableVertexAttribArray(0);

	glVertexAttribPointer((GLuint)1, 3, GL_FLOAT, GL_FALSE, sizeof(struct Vertex), (const GLvoid*)offsetof(struct Vertex, color));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer((GLuint)2, 3, GL_FLOAT, GL_FALSE, sizeof(struct Vertex), (const GLvoid*)offsetof(struct Vertex, normal));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0);

	vaoArr.push_back(vao);
	sizes.push_back(3);
}