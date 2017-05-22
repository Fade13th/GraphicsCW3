#include "Colusseum.h"

static struct Vertex* base;
static struct Vertex* wall;
static struct Vertex* roof;
static struct Vertex* ground;

static struct Vertex* step1;
static struct Vertex* step2;
static struct Vertex* step3;
static struct Vertex* step4;
static struct Vertex* step5;
static struct Vertex* step6;


void makeColusseum(float innerSize, float outerSize, float height, glm::vec3 colour) {
	GLdouble diff = (outerSize - 1.0f) - innerSize;
	GLdouble x = outerSize - 1.0f;

	base = makeColusseumBase(innerSize, outerSize, 0.45f * height, colour);

	wall = makeColusseumBase(x, outerSize, 0.5f * height, colour);
	translateColusseumBase(glm::vec3(0, 0, 0.45f*height), wall);

	roof = makeColusseumBase(innerSize, outerSize, 0.05f * height, colour);
	translateColusseumBase(glm::vec3(0, 0, 0.95f*height), roof);

	ground = makeFloor(outerSize, glm::vec3(0.2, 0.17, 0.05));

	step1 = makeColusseumBase(innerSize + (1 * diff / 10), x, 0.03f*height, glm::vec3(0.2, 0.17, 0.1));
	translateColusseumBase(glm::vec3(0, 0, 0.45f *height), step1);
	step2 = makeColusseumBase(innerSize + (2 * diff / 10), x, 0.03f*height, glm::vec3(0.2, 0.17, 0.1));
	translateColusseumBase(glm::vec3(0, 0, 0.48f *height), step2);
	step3 = makeColusseumBase(innerSize + (3 * diff / 10), x, 0.03f*height, glm::vec3(0.2, 0.17, 0.1));
	translateColusseumBase(glm::vec3(0, 0, 0.51f *height), step3);

	step4 = makeColusseumBase(innerSize + (7 * diff / 10), x, 0.03f*height, glm::vec3(0.2, 0.17, 0.1));
	translateColusseumBase(glm::vec3(0, 0, 0.54f *height), step4);
	step5 = makeColusseumBase(innerSize + (8 * diff / 10), x, 0.03f*height, glm::vec3(0.2, 0.17, 0.1));
	translateColusseumBase(glm::vec3(0, 0, 0.57f *height), step5);
	step6 = makeColusseumBase(innerSize + (9 * diff / 10), x, 0.03f*height, glm::vec3(0.2, 0.17, 0.1));
	translateColusseumBase(glm::vec3(0, 0, 0.6f *height), step6);
}

void addColusseum(std::vector<GLuint>& vaoArr, std::vector<GLuint>& sizes) {
	addColusseumBase(vaoArr, sizes, base);
	addColusseumBase(vaoArr, sizes, wall);
	addColusseumBase(vaoArr, sizes, roof);
	addFloor(vaoArr, sizes, ground);

	addColusseumBase(vaoArr, sizes, step1);
	addColusseumBase(vaoArr, sizes, step2);
	addColusseumBase(vaoArr, sizes, step3);
	addColusseumBase(vaoArr, sizes, step4);
	addColusseumBase(vaoArr, sizes, step5);
	addColusseumBase(vaoArr, sizes, step6);
}

void translateColusseum(glm::vec3 translation) {
	translateColusseumBase(translation, base);
	translateColusseumBase(translation, wall);
	translateColusseumBase(translation, roof);
	translateFloor(translation, ground);

	translateColusseumBase(translation, step1);
	translateColusseumBase(translation, step2);
	translateColusseumBase(translation, step3);
	translateColusseumBase(translation, step4);
	translateColusseumBase(translation, step5);
	translateColusseumBase(translation, step6);
}