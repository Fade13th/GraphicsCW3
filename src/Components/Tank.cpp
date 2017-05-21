#include "Tank.h"

static struct Vertex* body;
static struct Vertex* turret;

static struct Vertex* barrel1;
static struct Vertex* barrel2;
static struct Vertex* barrel3;

static struct Vertex* Ltrack;
static struct Vertex* Lwheel1;
static struct Vertex* Lwheel2;
static struct Vertex* Lwheel3;

static struct Vertex* Rtrack;
static struct Vertex* Rwheel1;
static struct Vertex* Rwheel2;
static struct Vertex* Rwheel3;

void makeTank(glm::vec3 colour) {
	body = makeTankBody(2, 1, 3, colour);
	translateTankBody(glm::vec3(0.5, 0, 0.5), body);

	turret = makeTurret(1.4, 0.4, 1.2, colour);
	translateTurret(glm::vec3(0.8, 0, 1.5), turret);


	barrel1 = makeBarrel(0.1,2, colour);
	translateBarrel(glm::vec3(-1.0, 0, 1.5), barrel1);

	barrel2 = makeBarrel(0.15, 0.1, colour);
	translateBarrel(glm::vec3(-1.0, 0, 1.5), barrel2);

	barrel3 = makeBarrel(0.14, 0.01, glm::vec3(0,0,0));
	translateBarrel(glm::vec3(-1.005, 0, 1.5), barrel3);


	Ltrack = makeTrack(0.45, 0.55, 0.5, glm::vec3(0.1f, 0.1f, 0.1f));
	translateTrack(glm::vec3(0, -1.5, 0.55), Ltrack);

	Lwheel1 = makeWheel(0.45, 0.3, glm::vec3(0.2f, 0.2f, 0.2f));
	translateWheel(glm::vec3(-0.8, -1.3, 0.55), Lwheel1);

	Lwheel2 = makeWheel(0.45, 0.3, glm::vec3(0.2f, 0.2f, 0.2f));
	translateWheel(glm::vec3(0.5, -1.3, 0.55), Lwheel2);

	Lwheel3 = makeWheel(0.45, 0.3, glm::vec3(0.2f, 0.2f, 0.2f));
	translateWheel(glm::vec3(1.8, -1.3, 0.55), Lwheel3);


	Rtrack = makeTrack(0.45, 0.55, 0.5, glm::vec3(0.1f, 0.1f, 0.1f));
	translateTrack(glm::vec3(0, 1.0, 0.55), Rtrack);

	Rwheel1 = makeWheel(0.45, 0.3, glm::vec3(0.2f, 0.2f, 0.2f));
	translateWheel(glm::vec3(-0.8, 1.0, 0.55), Rwheel1);

	Rwheel2 = makeWheel(0.45, 0.3, glm::vec3(0.2f, 0.2f, 0.2f));
	translateWheel(glm::vec3(0.5, 1.0, 0.55), Rwheel2);

	Rwheel3 = makeWheel(0.45, 0.3, glm::vec3(0.2f, 0.2f, 0.2f));
	translateWheel(glm::vec3(1.8, 1.0, 0.55), Rwheel3);
}

void addTank(std::vector<GLuint>& vaoArr, std::vector<GLuint>& sizes) {
	addTankBody(vaoArr, sizes, body);
	addTurret(vaoArr, sizes, turret);

	addBarrel(vaoArr, sizes, barrel1);
	addBarrel(vaoArr, sizes, barrel2);
	addBarrel(vaoArr, sizes, barrel3);

	addTrack(vaoArr, sizes, Ltrack);
	addWheel(vaoArr, sizes, Lwheel1);
	addWheel(vaoArr, sizes, Lwheel2);
	addWheel(vaoArr, sizes, Lwheel3);

	addTrack(vaoArr, sizes, Rtrack);
	addWheel(vaoArr, sizes, Rwheel1);
	addWheel(vaoArr, sizes, Rwheel2);
	addWheel(vaoArr, sizes, Rwheel3);
}

void translateTank(glm::vec3 translation) {
	translateTankBody(translation, body);
	translateTurret(translation, turret);

	translateBarrel(translation, barrel1);
	translateBarrel(translation, barrel2);
	translateBarrel(translation, barrel3);

	translateTrack(translation, Ltrack);
	translateWheel(translation, Lwheel1);
	translateWheel(translation, Lwheel2);
	translateWheel(translation, Lwheel3);

	translateTrack(translation, Rtrack);
	translateWheel(translation, Rwheel1);
	translateWheel(translation, Rwheel2);
	translateWheel(translation, Rwheel3);
}