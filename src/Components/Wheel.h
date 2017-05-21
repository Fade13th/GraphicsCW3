#ifndef Wheel_H
#define Wheel_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stdlib.h>
#include "utils.h"

#include <vector>

#include "../Vertex.h"

struct Vertex* makeWheel(GLdouble radius, GLdouble height, glm::vec3 colour);

void addWheel(std::vector<GLuint>& vaoArr, std::vector<GLuint>& sizes, struct Vertex* cone);

void translateWheel(glm::vec3 translation, struct Vertex* sphere);

#endif