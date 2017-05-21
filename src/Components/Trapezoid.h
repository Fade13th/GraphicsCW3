#ifndef Trapezoid_H
#define Trapezoid_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stdlib.h>
#include "utils.h"

#include <vector>

#include "../Vertex.h"

struct Vertex* makeTrapezoid(GLdouble width, GLdouble height, GLdouble length, glm::vec3 colour);

void addTrapezoid(std::vector<GLuint>& vaoArr, std::vector<GLuint>& sizes, struct Vertex* cone);

void translateTrapezoid(glm::vec3 translation, struct Vertex* sphere);

#endif