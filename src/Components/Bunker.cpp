#include "Bunker.h"

static struct Vertex* base1;
static struct Vertex* base2;
static struct Vertex* base3;
static struct Vertex* base4;
static struct Vertex* base5;
static struct Vertex* base6;
static struct Vertex* base7;

static struct Vertex* roof;

void makeBunker(float innerSize, float outerSize, float height, glm::vec3 colour) {
	base1 = makeRectangle(3, 0.8, 0.2, colour);
	translateRectangle(glm::vec3(-1.3, 0, 0), base1);

	base2 = makeRectangle(3, 0.3, 0.2, colour);
	translateRectangle(glm::vec3(-1.3, 0, 1.2), base2);

	base3 = makeRectangle(0.2, 1.5, 1.5, colour);
	translateRectangle(glm::vec3(0, 2.8, 0), base3);

	base4 = makeRectangle(0.2, 1.5, 1.5, colour);
	translateRectangle(glm::vec3(0, -2.8, 0), base4);

	base5 = makeRectangle(1.5, 1.5, 0.2, colour);
	translateRectangle(glm::vec3(1.3, 1.2, 0), base5);

	base6 = makeRectangle(1.2, 1.5, 0.2, colour);
	translateRectangle(glm::vec3(1.3, -0.75, 0), base6);

	base7 = makeRectangle(3, 0.3, 0.2, colour);
	translateRectangle(glm::vec3(1.3, 0, 1.2), base7);


	roof = makeTrapezoid(3, 0.5, 1.5, colour);
	translateTrapezoid(glm::vec3(0, 0, 1.5), roof);
}

void addBunker(std::vector<GLuint>& vaoArr, std::vector<GLuint>& sizes) {
	addRectangle(vaoArr, sizes, base1);
	addRectangle(vaoArr, sizes, base2);
	addRectangle(vaoArr, sizes, base3);
	addRectangle(vaoArr, sizes, base4);
	addRectangle(vaoArr, sizes, base5);
	addRectangle(vaoArr, sizes, base6);
	addRectangle(vaoArr, sizes, base7);

	addTrapezoid(vaoArr, sizes, roof);
}

void translateBunker(glm::vec3 translation) {
	translateRectangle(translation, base1);
	translateRectangle(translation, base2);
	translateRectangle(translation, base3);
	translateRectangle(translation, base4);
	translateRectangle(translation, base5);
	translateRectangle(translation, base6);
	translateRectangle(translation, base7);

	translateTrapezoid(translation, roof);
}