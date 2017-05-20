#ifndef ColusseumBase_H
#define ColusseumBase_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stdlib.h>
#include "utils.h"

#include <vector>

#include "../Vertex.h"

struct Vertex* makeColusseumBase(float innerSize, float outerSize, float height);

void addColusseumBase(std::vector<GLuint>& vaoArr, std::vector<GLuint>& sizes, struct Vertex* colusseum);

void translateColusseumBase(glm::vec3 translation, struct Vertex* colusseum);

#endif