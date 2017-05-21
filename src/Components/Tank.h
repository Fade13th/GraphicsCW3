#ifndef Tank_H
#define Tank_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stdlib.h>
#include "utils.h"

#include "../Vertex.h"
#include "TankBody.h"
#include "Wheel.h"
#include "Track.h"
#include "Turret.h"
#include "Barrel.h"

void makeTank(glm::vec3 colour);

void addTank(std::vector<GLuint>& vaoArr, std::vector<GLuint>& sizes);

void translateTank(glm::vec3 translation);

#endif