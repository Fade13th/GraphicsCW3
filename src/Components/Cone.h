#ifndef Cone_H
#define Cone_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stdlib.h>
#include "utils.h"

#include <vector>

#include "../Vertex.h"

struct Vertex* makeCone(GLdouble radius, GLdouble height, glm::vec3 colour);

void addCone(std::vector<GLuint>& vaoArr, std::vector<GLuint>& sizes, struct Vertex* cone);

void translateCone(glm::vec3 translation, struct Vertex* sphere);

#endif