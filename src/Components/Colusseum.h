#ifndef Colusseum_H
#define Colusseum_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stdlib.h>
#include "utils.h"

#include "../Vertex.h"
#include "ColusseumBase.h"
#include "Floor.h"

void makeColusseum(float innerSize, float outerSize, float height, glm::vec3 colour);

void addColusseum(std::vector<GLuint>& vaoArr, std::vector<GLuint>& sizes);

void translateColusseum(glm::vec3 translation);

#endif