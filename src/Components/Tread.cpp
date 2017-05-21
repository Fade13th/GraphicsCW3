#include "Tread.h"

static struct Vertex* track;
static struct Vertex* wheel1;
static struct Vertex* wheel2;
static struct Vertex* wheel3;

void makeTread(glm::vec3 colour) {
	track = makeTrack(0.3, 0.35, 0.2, glm::vec3(0.2f, 0.2f, 0.2f));
	translateTrack(glm::vec3(0, 0, 0.5), track);

	wheel1 = makeWheel(0.3, 0.2, colour);
	translateWheel(glm::vec3(-0.5,0, 0.5), wheel1);

	wheel2 = makeWheel(0.3, 0.2, colour);
	translateWheel(glm::vec3(0.5, 0, 0.5), wheel2);

	wheel3 = makeWheel(0.3, 0.2, colour);
	translateWheel(glm::vec3(1.5, 0, 0.5), wheel3);
}

void addTread(std::vector<GLuint>& vaoArr, std::vector<GLuint>& sizes) {
	addTrack(vaoArr, sizes, track);
	addWheel(vaoArr, sizes, wheel1);
	addWheel(vaoArr, sizes, wheel2);
	addWheel(vaoArr, sizes, wheel3);
}

void translateTread(glm::vec3 translation) {
	translateTrack(translation, track);
	translateWheel(translation, wheel1);
	translateWheel(translation, wheel2);
	translateWheel(translation, wheel3);
}