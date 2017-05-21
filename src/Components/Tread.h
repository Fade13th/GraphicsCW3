#ifndef Tread_H
#define Tread_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stdlib.h>
#include "utils.h"

#include "../Vertex.h"
#include "Wheel.h"
#include "Track.h"

void makeTread(glm::vec3 colour);

void addTread(std::vector<GLuint>& vaoArr, std::vector<GLuint>& sizes);

void translateTread(glm::vec3 translation);

#endif