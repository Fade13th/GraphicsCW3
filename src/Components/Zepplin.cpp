#include "Zepplin.h"

static struct Vertex* balloon;
static struct Vertex* cockpit;
static struct Vertex* fin1;
static struct Vertex* fin2;

void makeZepplin(glm::vec3 colour) {
	balloon = makeBalloon(4, 1, 2, glm::vec3(0.6, 0.6, 0.6));

	cockpit = makeTankBody(0.8, 0.6, 1, colour);
	translateTankBody(glm::vec3(0, 0, -1.4), cockpit);

	fin1 = makeRectangle(1, 0.1, 1, colour);
	translateRectangle(glm::vec3(0.7, 0, 0), fin1);

	fin2 = makeRectangle(0.1, 2, 0.7, colour);
	translateRectangle(glm::vec3(1, 0, -1), fin2);

}

void addZepplin(std::vector<GLuint>& vaoArr, std::vector<GLuint>& sizes) {
	addBalloon(vaoArr, sizes, balloon);
	addTankBody(vaoArr, sizes, cockpit);
	addRectangle(vaoArr, sizes, fin1);
	addRectangle(vaoArr, sizes, fin2);
}

void translateZepplin(glm::vec3 translation) {
	translateBalloon(translation, balloon);
	translateTankBody(translation, cockpit);
	translateRectangle(translation, fin1);
	translateRectangle(translation, fin2);
}