#include "World.h"

static GLchar *vertexsource, *geomsource, *fragmentsource;

static GLuint vertexshader, geomshader, fragmentshader;

static GLuint shaderprogram;
static GLuint vao, vao_cone, vbo[1], vbo_cone[1]; 

std::vector<GLuint> StaticBits;
std::vector<GLuint> StaticBitSizes;
std::vector<GLuint> Tank;
std::vector<GLuint> TankSize;
std::vector<GLuint> Zepplin;
std::vector<GLuint> ZepplinSize;

static int sphereSplits = 4;

GLfloat GetF3dVectorLength(glm::vec3 v)
{
	GLfloat tot = (v[0] * v[0]) + (v[1] * v[1]) + (v[2] * v[2]);

	return (GLfloat)(sqrt(tot) );
} 

glm::vec3 Normalize3dVector(glm::vec3 v)
{
	glm::vec3 res;
	float l = GetF3dVectorLength(v);
	if (l == 0.0f) return glm::vec3(0,0,0);
	res.x = v.x / l;
	res.y = v.y / l;
	res.z = v.z / l;
	return res;
}

glm::vec3 operator+ (glm::vec3 v, glm::vec3 u)
{
	glm::vec3 res;
	res.x = v.x + u.x;
	res.y = v.y + u.y;
	res.z = v.z + u.z;
	return res;
}
glm::vec3 operator- (glm::vec3 v, glm::vec3 u)
{
	glm::vec3 res;
	res.x = v.x - u.x;
	res.y = v.y - u.y;
	res.z = v.z - u.z;
	return res;
}


glm::vec3 operator* (glm::vec3 v, float r)
{
	glm::vec3 res;
	res.x = v.x*r;
	res.y = v.y*r;
	res.z = v.z*r;
	return res;
}

glm::vec3 CrossProduct(glm::vec3 * u, glm::vec3 * v)
{
	glm::vec3 resVector;
	resVector.x = u->y*v->z - u->z*v->y;
	resVector.y = u->z*v->x - u->x*v->z;
	resVector.z = u->x*v->y - u->y*v->x;

	return resVector;
}
float operator* (glm::vec3 v, glm::vec3 u)	//dot product
{
	return v.x*u.x + v.y*u.y + v.z*u.z;
}

void SetupGeometry() {	
	makeColusseum(35.0f, 50.0f, 25.0f, glm::vec3(0.15f,0.17f,0.15f));
	addColusseum(StaticBits, StaticBitSizes);
	{
		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-20, 20, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-28, 0, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(0, 28, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-5, 5, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-21, 18, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-19, 17, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-7, 15, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-6, 13, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-3, 11, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-4, 8, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-26, 4, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-26.5, 1.5, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-24.5, 1, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-24, 4, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-24.5, 8, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-23, 12, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-23, 2, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-22, 7, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-23.5, 10, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-22, 0, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-22, 9, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-21, 2, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-21, 14, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-21, 18, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-20, 5, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-20, 9, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-18, 14, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-19, 21, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-17, 5, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-17, 8, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-17, 19, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-17, 24, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-15, 7, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-15, 10, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-15, 16, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-15, 19, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-15, 23, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-15, 26, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-13, 8, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-13, 11, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-13, 15, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-13, 19, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-13, 22, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-13, 27, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-11, 5, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-11, 7, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-11, 10, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-11, 13, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-11, 16, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-11, 19, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-11, 22, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
translateTree(glm::vec3(-8, 2, 0));
addTree(StaticBits, StaticBitSizes);

makeTree(glm::vec3(0, 0.4, 0.05));
translateTree(glm::vec3(-8, 6, 0));
addTree(StaticBits, StaticBitSizes);

makeTree(glm::vec3(0, 0.4, 0.05));
translateTree(glm::vec3(-9, 10, 0));
addTree(StaticBits, StaticBitSizes);

makeTree(glm::vec3(0, 0.4, 0.05));
translateTree(glm::vec3(-8, 14, 0));
addTree(StaticBits, StaticBitSizes);

makeTree(glm::vec3(0, 0.4, 0.05));
translateTree(glm::vec3(-9, 17, 0));
addTree(StaticBits, StaticBitSizes);

makeTree(glm::vec3(0, 0.4, 0.05));
translateTree(glm::vec3(-8, 20, 0));
addTree(StaticBits, StaticBitSizes);

makeTree(glm::vec3(0, 0.4, 0.05));
translateTree(glm::vec3(-8, 24, 0));
addTree(StaticBits, StaticBitSizes);

makeTree(glm::vec3(0, 0.4, 0.05));
translateTree(glm::vec3(-2, 6, 0));
addTree(StaticBits, StaticBitSizes);

makeTree(glm::vec3(0, 0.4, 0.05));
translateTree(glm::vec3(-3, 17, 0));
addTree(StaticBits, StaticBitSizes);

makeTree(glm::vec3(0, 0.4, 0.05));
translateTree(glm::vec3(-2, 14, 0));
addTree(StaticBits, StaticBitSizes);

makeTree(glm::vec3(0, 0.4, 0.05));
translateTree(glm::vec3(-2, 19, 0));
addTree(StaticBits, StaticBitSizes);

makeTree(glm::vec3(0, 0.4, 0.05));
translateTree(glm::vec3(-3, 24, 0));
addTree(StaticBits, StaticBitSizes);

makeTree(glm::vec3(0, 0.4, 0.05));
translateTree(glm::vec3(0, 5, 0));
addTree(StaticBits, StaticBitSizes);

makeTree(glm::vec3(0, 0.4, 0.05));
translateTree(glm::vec3(0, 9, 0));
addTree(StaticBits, StaticBitSizes);

makeTree(glm::vec3(0, 0.4, 0.05));
translateTree(glm::vec3(1, 13, 0));
addTree(StaticBits, StaticBitSizes);

makeTree(glm::vec3(0, 0.4, 0.05));
translateTree(glm::vec3(1, 17, 0));
addTree(StaticBits, StaticBitSizes);

makeTree(glm::vec3(0, 0.4, 0.05));
translateTree(glm::vec3(1, 20, 0));
addTree(StaticBits, StaticBitSizes);

makeTree(glm::vec3(0, 0.4, 0.05));
translateTree(glm::vec3(0, 24, 0));
addTree(StaticBits, StaticBitSizes);

makeTree(glm::vec3(0, 0.4, 0.05));
translateTree(glm::vec3(3, 8, 0));
addTree(StaticBits, StaticBitSizes);

makeTree(glm::vec3(0, 0.4, 0.05));
translateTree(glm::vec3(4, 12, 0));
addTree(StaticBits, StaticBitSizes);

makeTree(glm::vec3(0, 0.4, 0.05));
translateTree(glm::vec3(4, 17, 0));
addTree(StaticBits, StaticBitSizes);

makeTree(glm::vec3(0, 0.4, 0.05));
translateTree(glm::vec3(3, 21, 0));
addTree(StaticBits, StaticBitSizes);

makeTree(glm::vec3(0, 0.4, 0.05));
translateTree(glm::vec3(4, 25, 0));
addTree(StaticBits, StaticBitSizes);

makeTree(glm::vec3(0, 0.4, 0.05));
translateTree(glm::vec3(-5, 17, 0));
addTree(StaticBits, StaticBitSizes);

makeTree(glm::vec3(0, 0.4, 0.05));
translateTree(glm::vec3(-5, 21, 0));
addTree(StaticBits, StaticBitSizes);

	}

	{
		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(0, -8, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(0, -12, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(1, -15, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(0, -18, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-1, -22, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(4, -10, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(4, -14, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(3, -18, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(4, -21, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(7, -9, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(8, -13, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(8, -17, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(10, -12, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(9, -16, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-3, -9, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-4, -13, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-3, -16, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-3, -20, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-7, -11, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-7, -15, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-7, -19, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-10, -13, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-10, -17, 0));
		addTree(StaticBits, StaticBitSizes);
	}
	{
		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(20, -15, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(19, 25, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(22, 13, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(-24, -10, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(28, 5, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(27, 13, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(24, -3, 0));
		addTree(StaticBits, StaticBitSizes);

		makeTree(glm::vec3(0, 0.4, 0.05));
		translateTree(glm::vec3(28, -12, 0));
		addTree(StaticBits, StaticBitSizes);

	}
	{
		struct Vertex* rock = makeRockLarge(glm::vec3(0.2f, 0.1f, 0.0f));
		translateRockLarge(glm::vec3(-20.0f, -12.0f, 0.0f), rock);
		addRockLarge(StaticBits, StaticBitSizes, rock);

		rock = makeRockLarge(glm::vec3(0.2f, 0.1f, 0.0f));
		translateRockLarge(glm::vec3(18.0f, 18.0f, 0.0f), rock);
		addRockLarge(StaticBits, StaticBitSizes, rock);

		rock = makeRockLarge(glm::vec3(0.2f, 0.1f, 0.0f));
		translateRockLarge(glm::vec3(-29.0f, 6.0f, 0.0f), rock);
		addRockLarge(StaticBits, StaticBitSizes, rock);

		rock = makeRockLarge(glm::vec3(0.2f, 0.1f, 0.0f));
		translateRockLarge(glm::vec3(-19.0f, 0.0f, 0.0f), rock);
		addRockLarge(StaticBits, StaticBitSizes, rock);

		rock = makeRockLarge(glm::vec3(0.2f, 0.1f, 0.0f));
		translateRockLarge(glm::vec3(-30.0f, -6.0f, 0.0f), rock);
		addRockLarge(StaticBits, StaticBitSizes, rock);

		rock = makeRockLarge(glm::vec3(0.2f, 0.1f, 0.0f));
		translateRockLarge(glm::vec3(22.0f, -17.0f, 0.0f), rock);
		addRockLarge(StaticBits, StaticBitSizes, rock);

		rock = makeRockLarge(glm::vec3(0.2f, 0.1f, 0.0f));
		translateRockLarge(glm::vec3(25.0f, 8.0f, 0.0f), rock);
		addRockLarge(StaticBits, StaticBitSizes, rock);

		rock = makeRockLarge(glm::vec3(0.2f, 0.1f, 0.0f));
		translateRockLarge(glm::vec3(20.0f, -7.0f, 0.0f), rock);
		addRockLarge(StaticBits, StaticBitSizes, rock);

		rock = makeRockLarge(glm::vec3(0.2f, 0.1f, 0.0f));
		translateRockLarge(glm::vec3(5.0f, -22.0f, 0.0f), rock);
		addRockLarge(StaticBits, StaticBitSizes, rock);

	}

	makeBunker(2.0f, 2.05f, 1.3f, glm::vec3(0.3f, 0.3f, 0.3f));
	translateBunker(glm::vec3(20.0f, 3.0f, 0.0f));
	addBunker(StaticBits, StaticBitSizes);

	makeTank(glm::vec3(0.0f, 1.0f, 0.0f));
	translateTank(glm::vec3(0.0f, -2.0f, 0.0f));
	addTank(Tank, TankSize);

	makeZepplin(glm::vec3(0.3, 0.3, 0.5));
	//translateZepplin(glm::vec3(0, 25, 25));
	addZepplin(Zepplin, ZepplinSize);
}

void SetupShaders(void) {
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	vertexsource = filetobuf("./World.vert");
	geomsource = filetobuf("./World.geom");
	fragmentsource = filetobuf("./World.frag");

	vertexshader = glCreateShader(GL_VERTEX_SHADER);
	geomshader = glCreateShader(GL_GEOMETRY_SHADER);
	fragmentshader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vertexshader, 1, (const GLchar**)&vertexsource, 0);
	glShaderSource(geomshader, 1, (const GLchar**)&geomsource, 0);
	glShaderSource(fragmentshader, 1, (const GLchar**)&fragmentsource, 0);

	glCompileShader(vertexshader);
	glCompileShader(geomshader);
	glCompileShader(fragmentshader);

	shaderprogram = glCreateProgram();
	glAttachShader(shaderprogram, vertexshader);
	glAttachShader(shaderprogram, geomshader);
	glAttachShader(shaderprogram, fragmentshader);

	glBindAttribLocation(shaderprogram, 0, "in_Position"); 
	glBindAttribLocation(shaderprogram, 1, "in_Color");
	glBindAttribLocation(shaderprogram, 2, "in_Normal");

	glLinkProgram(shaderprogram);
	glUseProgram(shaderprogram);
}

static int time = 0;

glm::vec3 Position = glm::vec3(0, 0, 0);
glm::vec3 ViewDir = glm::vec3(0, 0, -1);
glm::vec3 RightVector = glm::vec3(1, 0, 0);
glm::vec3 UpVector = glm::vec3(0, 1, 0);

GLfloat RotX = 0.0f, RotY = 0.0f, RotZ = 0.0f;

glm::mat4 View = glm::mat4(1.);

GLfloat speed = 0;
GLfloat speedIncrement = 0.005;

void IncreaseSpeed() {
	speed += speedIncrement;
}

void DecreaseSpeed() {
	//if (speed > 0) {
		speed -= speedIncrement;
	//}
}

void RotateX(GLfloat angle) {
	RotX += angle;

	ViewDir = Normalize3dVector(ViewDir*cos(angle*(M_PI / 180)) + UpVector*sin(angle*(M_PI/180)));

	UpVector = CrossProduct(&ViewDir, &RightVector)*-1;
}

void RotateY(GLfloat angle) {
	RotY += angle;

	ViewDir = Normalize3dVector(ViewDir*cos(angle*(M_PI / 180)) - RightVector*sin(angle*(M_PI / 180)));

	RightVector = CrossProduct(&ViewDir, &UpVector);
}

void RotateZ(GLfloat angle) {
	RotZ += angle;

	RightVector = Normalize3dVector(RightVector*cos(angle*(M_PI / 180))	+ UpVector*sin(angle*(M_PI / 180)));

	UpVector = CrossProduct(&ViewDir, &RightVector)*-1;
}

void MoveToPos(glm::vec3 pos) {
	Position = pos;
}

void SetForward(glm::vec3 target) {
	ViewDir = target;
	RightVector = glm::vec3(1, 0, 0);
	UpVector = glm::vec3(0, 1, 0);
}

void Info() {
	print(Position);
	print(ViewDir);
	print("");
}

void StopMove() {
	speed = 0;
}

void Move(glm::vec3 Direction) {
	Position = Position + (Direction * speed);
}

static void MoveCamera() {
	glm::vec3 target = Position + ViewDir;

	glm::vec3 forward = glm::vec3(0, 0, -1);

	View = glm::lookAt(Position,
		target,
		UpVector);

	Move(ViewDir);
}

void Render(int i) {
	
	if (time > 360)
		time = 0;

	glm::vec3 light = glm::vec3(5.0f, 5.0f, 30.0f);
	GLfloat angle;
	glm::mat4 Projection = glm::perspective(45.0f, 1.0f, 0.1f, 100.0f);
	float t = glfwGetTime();
	float p = 1000.;
	t = fmod(t, p);
	angle = t * 360. / p;
	
	MoveCamera();

	glm::mat4 Model = glm::mat4(1.0);
	glm::mat4 MVP = Projection * View * Model;

	glm::vec4 V = glm::vec4(1, 1, 1, 0) * View;

	glUniform3fv(glGetUniformLocation(shaderprogram, "rotCenter"), 1, glm::value_ptr(glm::vec3(0, 0, 0)));
	glUniform1f(glGetUniformLocation(shaderprogram, "angle"), 1);
	glUniform1f(glGetUniformLocation(shaderprogram, "move"), 0);

	glUniformMatrix4fv(glGetUniformLocation(shaderprogram, "mvpmatrix"), 1, GL_FALSE, glm::value_ptr(MVP));
	glUniform3fv(glGetUniformLocation(shaderprogram, "lightPos"), 1, glm::value_ptr(light));
	glUniform3fv(glGetUniformLocation(shaderprogram, "viewPos"), 1, glm::value_ptr(V));
	glUniform1f(glGetUniformLocation(shaderprogram, "blinn"), 1);

	glClearColor(0.0, 0.5, 0.65, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (int i = 0; i < StaticBits.size(); i++) {
		GLuint v = StaticBits.at(i);
		glBindVertexArray(v);
		glDrawArrays(GL_TRIANGLES, 0, StaticBitSizes.at(i));
		glBindVertexArray(0);
	}

	for (int i = 0; i < Tank.size(); i++) {
		glUniform3fv(glGetUniformLocation(shaderprogram, "rotCenter"), 1, glm::value_ptr(glm::vec3(0, -15.0, 0)));
		glUniform1f(glGetUniformLocation(shaderprogram, "angle"), angle);
		glUniform1f(glGetUniformLocation(shaderprogram, "move"), 1);

		glBindVertexArray(Tank.at(i));
		glDrawArrays(GL_TRIANGLES, 0, TankSize.at(i));
		glBindVertexArray(0);
	}

	for (int i = 0; i < Zepplin.size(); i++) {
		glUniform3fv(glGetUniformLocation(shaderprogram, "rotCenter"), 1, glm::value_ptr(glm::vec3(0, 0, 0)));
		glUniform1f(glGetUniformLocation(shaderprogram, "angle"), angle/4);
		glUniform1f(glGetUniformLocation(shaderprogram, "move"), 1);

		glBindVertexArray(Zepplin.at(i));
		glDrawArrays(GL_TRIANGLES, 0, ZepplinSize.at(i));
		glBindVertexArray(0);
	}

	time++;
}