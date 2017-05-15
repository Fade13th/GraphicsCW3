#ifndef Cone_H
#define Cone_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stdlib.h>
#include "utils.h"

#include "../Vertex.h"

struct Vertex* makeCone();

void addCone(std::vector<GLuint>& vao, struct Vertex* cone);

void translateCone(glm::vec3 translation, struct Vertex* sphere);

#endif