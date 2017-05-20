#ifndef Floor_H
#define Floor_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stdlib.h>
#include "utils.h"

#include <vector>

#include "../Vertex.h"

struct Vertex* makeFloor(float radius, glm::vec3 colour);

void addFloor(std::vector<GLuint>& vaoArr, std::vector<GLuint>& sizes, struct Vertex* colusseum);

void translateFloor(glm::vec3 translation, struct Vertex* colusseum);

#endif