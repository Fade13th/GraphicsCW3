#ifndef Bunker_H
#define Bunker_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stdlib.h>
#include "utils.h"

#include "../Vertex.h"
#include "Rectangle.h"
#include "Trapezoid.h"

void makeBunker(float innerSize, float outerSize, float height, glm::vec3 colour);

void addBunker(std::vector<GLuint>& vaoArr, std::vector<GLuint>& sizes);

void translateBunker(glm::vec3 translation);

#endif