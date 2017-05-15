#include "Colusseum.h"

static struct Vertex* base;
static struct Vertex* wall;
static struct Vertex* roof;

void makeColusseum(float innerSize, float outerSize, float height) {
	base = makeColusseumBase(innerSize, outerSize, 0.45f * height);

	wall = makeColusseumBase(outerSize - 1.0f, outerSize, 0.5f * height);
	translateColusseumBase(glm::vec3(0, 0, 0.45f*height), wall);

	roof = makeColusseumBase(innerSize, outerSize, 0.05f * height);
	translateColusseumBase(glm::vec3(0, 0, 0.95f*height), roof);
}

void addColusseum(std::vector<GLuint>& vaoArr) {
	addColusseumBase(vaoArr, base);
	addColusseumBase(vaoArr, wall);
	addColusseumBase(vaoArr, roof);
}

void translateColusseum(glm::vec3 translation) {
	translateColusseumBase(translation, base);
	translateColusseumBase(translation, wall);
	translateColusseumBase(translation, roof);
}