#ifndef Sphere_H
#define Sphere_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stdlib.h>
#include "utils.h"

#include "../Vertex.h"

struct Vertex* makeSphere(int divisions, float radius);

#endif