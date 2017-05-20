#include "Tree.h"

static struct Vertex* trunk;
static struct Vertex* cone1;
static struct Vertex* cone2;
static struct Vertex* cone3;

void makeTree(glm::vec3 colour) {
	trunk = makeCylinder(0.2, 1.5, glm::vec3(0.2, 0.15, 0.01));

	cone1 = makeCone(0.8, 1.4, colour);
	translateCone(glm::vec3(0,0,1.5), cone1);

	cone2 = makeCone(0.65, 1.5, colour);
	translateCone(glm::vec3(0, 0, 2.1), cone2);

	cone3 = makeCone(0.5, 2, colour);
	translateCone(glm::vec3(0, 0, 2.7), cone3);
}

void addTree(std::vector<GLuint>& vaoArr, std::vector<GLuint>& sizes) {
	addCylinder(vaoArr, sizes, trunk);
	addCone(vaoArr, sizes, cone1);
	addCone(vaoArr, sizes, cone2);
	addCone(vaoArr, sizes, cone3);
}

void translateTree(glm::vec3 translation) {
	translateCylinder(translation, trunk);
	translateCone(translation, cone1);
	translateCone(translation, cone2);
	translateCone(translation, cone3);
}