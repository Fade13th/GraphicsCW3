#ifndef Turret_H
#define Turret_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stdlib.h>
#include "utils.h"

#include <vector>

#include "../Vertex.h"

struct Vertex* makeRectangle(GLdouble width, GLdouble height, GLdouble length, glm::vec3 colour);

void addRectangle(std::vector<GLuint>& vaoArr, std::vector<GLuint>& sizes, struct Vertex* cone);

void translateRectangle(glm::vec3 translation, struct Vertex* sphere);

#endif