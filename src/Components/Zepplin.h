#ifndef Zepplin_H
#define Zepplin_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stdlib.h>
#include "utils.h"

#include "../Vertex.h"
#include "Balloon.h"
#include "TankBody.h"
#include "Rectangle.h"

void makeZepplin(glm::vec3 colour);

void addZepplin(std::vector<GLuint>& vaoArr, std::vector<GLuint>& sizes);

void translateZepplin(glm::vec3 translation);

#endif