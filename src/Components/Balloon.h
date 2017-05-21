#ifndef Balloon_H
#define Balloon_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stdlib.h>
#include "utils.h"

#include <vector>

#include "../Vertex.h"

struct Vertex* makeBalloon(int divisions, float radius, float length, glm::vec3 colour);

void addBalloon(std::vector<GLuint>& vaoArr, std::vector<GLuint>& sizes, struct Vertex* sphere);

void translateBalloon(glm::vec3 translation, struct Vertex* sphere);

#endif