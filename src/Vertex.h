#ifndef Vertex_H
#define Vertex_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stdlib.h>
#include "utils.h"

struct Vertex {
	GLdouble position[3];
	GLfloat color[3];
	GLdouble normal[3];
};

GLdouble* getNormal(glm::vec3 A, glm::vec3 B, glm::vec3 C);

GLdouble* getNormal(GLdouble A[], GLdouble B[], GLdouble C[]);

#endif