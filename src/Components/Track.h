#ifndef Track_H
#define Track_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stdlib.h>
#include "utils.h"

#include <vector>

#include "../Vertex.h"

struct Vertex* makeTrack(float innerSize, float outerSize, float height, glm::vec3 colour);

void addTrack(std::vector<GLuint>& vaoArr, std::vector<GLuint>& sizes, struct Vertex* colusseum);

void translateTrack(glm::vec3 translation, struct Vertex* colusseum);

#endif