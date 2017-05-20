#ifndef Tree_H
#define Tree_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stdlib.h>
#include "utils.h"

#include "../Vertex.h"
#include "Cone.h"
#include "Cylinder.h"

void makeTree(glm::vec3 colour);

void addTree(std::vector<GLuint>& vaoArr, std::vector<GLuint>& sizes);

void translateTree(glm::vec3 translation);

#endif