#include "Colusseum.h"

static struct Vertex* base;
static struct Vertex* wall;
static struct Vertex* roof;
static struct Vertex* ground;

void makeColusseum(float innerSize, float outerSize, float height, glm::vec3 colour) {
	base = makeColusseumBase(innerSize, outerSize, 0.45f * height, colour);

	wall = makeColusseumBase(outerSize - 1.0f, outerSize, 0.5f * height, colour);
	translateColusseumBase(glm::vec3(0, 0, 0.45f*height), wall);

	roof = makeColusseumBase(innerSize, outerSize, 0.05f * height, colour);
	translateColusseumBase(glm::vec3(0, 0, 0.95f*height), roof);

	ground = makeFloor(outerSize, glm::vec3(0.4, 0.3, 0.2));
}

void addColusseum(std::vector<GLuint>& vaoArr, std::vector<GLuint>& sizes) {
	addColusseumBase(vaoArr, sizes, base);
	addColusseumBase(vaoArr, sizes, wall);
	addColusseumBase(vaoArr, sizes, roof);
	addFloor(vaoArr, sizes, ground);
}

void translateColusseum(glm::vec3 translation) {
	translateColusseumBase(translation, base);
	translateColusseumBase(translation, wall);
	translateColusseumBase(translation, roof);
	translateFloor(translation, ground);
}