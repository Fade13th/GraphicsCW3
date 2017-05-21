#ifndef World_H
#define World_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stddef.h> /* must include for the offsetof macro */
/*
*
* Include files for Windows, Linux and OSX
* __APPLE is defined if OSX, otherwise Windows and Linux.
*
*/

#ifdef __APPLE__
#define GLFW_INCLUDE_GLCOREARB 1
#include <GLFW/glfw3.h>
#else
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#endif

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stdlib.h>
#include "utils.h"

#include "Vertex.h"

#include "Tour.h"

#include "Components\Sphere.h"
#include "Components\Cone.h"
#include "Components\Colusseum.h"
#include "Components\Triangle.h"
#include "Components\Cylinder.h"
#include "Components\Tree.h"
#include "Components\RockLarge.h"
#include "Components\Tank.h"
#include "Components\Bunker.h"
#include "Components\Zepplin.h"

void SetupGeometry();

void SetupShaders(void);

void IncreaseSpeed();

void DecreaseSpeed();

void RotateX(GLfloat angle);

void RotateY(GLfloat angle);

void RotateZ(GLfloat angle);

void MoveToPos(glm::vec3 pos);

void SetForward(glm::vec3 target);

void Info();

void StopMove();

void Render(int i);
#endif