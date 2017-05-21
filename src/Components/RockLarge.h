#ifndef Rock_Large_H
#define Rock_Large_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stdlib.h>
#include "utils.h"

#include <vector>

#include "../Vertex.h"

struct Vertex* makeRockLarge(glm::vec3 colour);

void addRockLarge(std::vector<GLuint>& vaoArr, std::vector<GLuint>& sizes, struct Vertex* cone);

void translateRockLarge(glm::vec3 translation, struct Vertex* sphere);

#endif