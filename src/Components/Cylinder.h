#ifndef Cylinder_H
#define Cylinder_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stdlib.h>
#include "utils.h"

#include <vector>

#include "../Vertex.h"

struct Vertex* makeCylinder(GLdouble radius, GLdouble height, glm::vec3 colour);

void addCylinder(std::vector<GLuint>& vaoArr, std::vector<GLuint>& sizes, struct Vertex* cone);

void translateCylinder(glm::vec3 translation, struct Vertex* sphere);

#endif