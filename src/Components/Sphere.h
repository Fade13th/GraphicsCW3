#ifndef Sphere_H
#define Sphere_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stdlib.h>
#include "utils.h"

#include <vector>

#include "../Vertex.h"

struct Vertex* makeSphere(int divisions, float radius, glm::vec3 colour);

void addSphere(std::vector<GLuint>& vaoArr, std::vector<GLuint>& sizes, struct Vertex* sphere);

void translateSphere(glm::vec3 translation, struct Vertex* sphere);

#endif