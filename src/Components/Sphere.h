#ifndef Sphere_H
#define Sphere_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stdlib.h>
#include "utils.h"

#include <vector>

#include "../Vertex.h"

struct Vertex* makeSphere(int divisions, float radius);

void addSphere(std::vector<GLuint>& vaoArr, struct Vertex* sphere);

void translateSphere(glm::vec3 translation, struct Vertex* sphere);

#endif