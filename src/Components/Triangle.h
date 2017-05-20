#ifndef Triangle_H
#define Triangle_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stdlib.h>
#include "utils.h"

#include <vector>

#include "../Vertex.h"

struct Vertex* makeTri();

void addTri(std::vector<GLuint>& vaoArr, std::vector<GLuint>& sizes, struct Vertex* tri);

#endif