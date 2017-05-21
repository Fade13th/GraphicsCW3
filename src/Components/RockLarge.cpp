#include "RockLarge.h"

static int s = 0;

struct Vertex* makeRockLarge(glm::vec3 colour) {
	struct Vertex *current;

	int size = 3 * 46;
	s = size;

	GLfloat R = colour[0];
	GLfloat G = colour[1];
	GLfloat B = colour[2];

	current = new struct Vertex[s];

	GLdouble* a;
	GLdouble* b;
	GLdouble* c;

	GLdouble* norm;

	int k = 0;
	{
		a = new GLdouble[3]{ -0.65, 0.35, 0 };
		b = new GLdouble[3]{ -0.7, -0.1, 0 };
		c = new GLdouble[3]{ -0.3, 0.4, 0 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ -0.7, -0.1, 0 };
		b = new GLdouble[3]{ -0.3, -0.3, 0 };
		c = new GLdouble[3]{ -0.3, 0.4, 0 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ -0.3, 0.4, 0 };
		b = new GLdouble[3]{ -0.3, -0.3, 0 };
		c = new GLdouble[3]{ 0.3, -0.1, 0 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ -0.3, 0.4, 0 };
		b = new GLdouble[3]{ 0.3, -0.1, 0 };
		c = new GLdouble[3]{ 0.5, 0, 0 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ -0.3, 0.4, 0 };
		b = new GLdouble[3]{ 0.5, 0, 0 };
		c = new GLdouble[3]{ 0.45, 0.45, 0 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ -0.3, 0.4, 0 };
		b = new GLdouble[3]{ 0.45, 0.45, 0 };
		c = new GLdouble[3]{ 0, 0.5, 0 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ 0.3, -0.1, 0 };
		b = new GLdouble[3]{ -0.3, -0.3, 0 };
		c = new GLdouble[3]{ 0.4, -0.2, 0 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ 0.4, -0.2, 0 };
		b = new GLdouble[3]{ -0.3, -0.3, 0 };
		c = new GLdouble[3]{ 0.2, -0.5, 0 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ 0.2, -0.5, 0 };
		b = new GLdouble[3]{ -0.3, -0.3, 0 };
		c = new GLdouble[3]{ -0.25, -0.5, 0 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
	}
	{
		GLdouble* a = new GLdouble[3]{ -0.55, 0.25, 0.4 };
		GLdouble* b = new GLdouble[3]{ -0.6, 0, 0.4 };
		GLdouble* c = new GLdouble[3]{ -0.2, 0.3, 0.4 };
		GLdouble* norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ -0.6, 0, 0.4 };
		b = new GLdouble[3]{ -0.2, -0.2, 0.4 };
		c = new GLdouble[3]{ -0.2, 0.3, 0.4 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };

		a = new GLdouble[3]{ -0.2, 0.3, 0.4 };
		b = new GLdouble[3]{ 0.2, 0, 0.4 };
		c = new GLdouble[3]{ 0.4, 0, 0.4 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ -0.2, 0.3, 0.4 };
		b = new GLdouble[3]{ 0.4, 0, 0.4 };
		c = new GLdouble[3]{ 0.35, 0.35, 0.4 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ -0.2, 0.3, 0.4 };
		b = new GLdouble[3]{ 0.35, 0.35, 0.4 };
		c = new GLdouble[3]{ 0, 0.4, 0.4 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ 0.2, 0, 0.4 };
		b = new GLdouble[3]{ -0.2, -0.2, 0.4 };
		c = new GLdouble[3]{ 0.3, -0.1, 0.4 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ 0.3, -0.1, 0.4 };
		b = new GLdouble[3]{ -0.2, -0.2, 0.4 };
		c = new GLdouble[3]{ 0.1, -0.4, 0.4 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ 0.1, -0.4, 0.4 };
		b = new GLdouble[3]{ -0.2, -0.2, 0.4 };
		c = new GLdouble[3]{ -0.15, -0.4, 0.4 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
	}
	{
		a = new GLdouble[3]{ -0.15, 0.25, 0.7 };
		b = new GLdouble[3]{ -0.15, -0.15, 0.7 };
		c = new GLdouble[3]{ 0.15, 0, 0.7 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
	}
	{
		a = new GLdouble[3]{ -0.65, 0.35, 0 };
		b = new GLdouble[3]{ -0.7, -0.1, 0 };
		c = new GLdouble[3]{ -0.55, 0.25, 0.4 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ -0.55, 0.25, 0.4 };
		b = new GLdouble[3]{ -0.7, -0.1, 0 };
		c = new GLdouble[3]{ -0.6, 0, 0.4 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ -0.7, -0.1, 0 };
		b = new GLdouble[3]{ -0.3, -0.3, 0 };
		c = new GLdouble[3]{ -0.6, 0, 0.4 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ -0.6, 0, 0.4 };
		b = new GLdouble[3]{ -0.3, -0.3, 0 };
		c = new GLdouble[3]{ -0.2, -0.2, 0.4 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ -0.3, -0.3, 0 };
		b = new GLdouble[3]{ -0.25, -0.5, 0 };
		c = new GLdouble[3]{ -0.2, -0.2, 0.4 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ -0.2, -0.2, 0.4 };
		b = new GLdouble[3]{ -0.25, -0.5, 0 };
		c = new GLdouble[3]{ -0.15, -0.4, 0.4 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ -0.25, -0.5, 0 };
		b = new GLdouble[3]{ 0.2, -0.5, 0 };
		c = new GLdouble[3]{ -0.15, -0.4, 0.4 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ -0.15, -0.4, 0.4 };
		b = new GLdouble[3]{ 0.2, -0.5, 0 };
		c = new GLdouble[3]{ 0.1, -0.4, 0.4 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ 0.2, -0.5, 0 };
		b = new GLdouble[3]{ 0.4, -0.2, 0 };
		c = new GLdouble[3]{ 0.1, -0.4, 0.4 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ 0.1, -0.4, 0.4 };
		b = new GLdouble[3]{ 0.4, -0.2, 0 };
		c = new GLdouble[3]{ 0.3, -0.1, 0.4 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ 0.4, -0.2, 0 };
		b = new GLdouble[3]{ 0.3, -0.1, 0 };
		c = new GLdouble[3]{ 0.3, -0.1, 0.4 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ 0.3, -0.1, 0.4 };
		b = new GLdouble[3]{ 0.3, -0.1, 0 };
		c = new GLdouble[3]{ 0.2, 0, 0.4 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ 0.3, -0.1, 0 };
		b = new GLdouble[3]{ 0.5, 0, 0 };
		c = new GLdouble[3]{ 0.2, 0, 0.4 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ 0.2, 0, 0.4 };
		b = new GLdouble[3]{ 0.5, 0, 0 };
		c = new GLdouble[3]{ 0.4, 0, 0.4 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ 0.5, 0, 0 };
		b = new GLdouble[3]{ 0.45, 0.45, 0 };
		c = new GLdouble[3]{ 0.4, 0, 0.4 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ 0.4, 0, 0.4 };
		b = new GLdouble[3]{ 0.45, 0.45, 0 };
		c = new GLdouble[3]{ 0.35, 0.35, 0.4 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ 0.45, 0.45, 0 };
		b = new GLdouble[3]{ 0, 0.5, 0 };
		c = new GLdouble[3]{ 0.35, 0.35, 0.4 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ 0.35, 0.35, 0.4 };
		b = new GLdouble[3]{ 0, 0.5, 0 };
		c = new GLdouble[3]{ 0, 0.4, 0.4 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ 0, 0.5, 0 };
		b = new GLdouble[3]{ -0.3, 0.4, 0 };
		c = new GLdouble[3]{ 0, 0.4, 0.4 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ 0, 0.4, 0.4 };
		b = new GLdouble[3]{ -0.3, 0.4, 0 };
		c = new GLdouble[3]{ -0.2, 0.3, 0.4 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ -0.3, 0.4, 0 };
		b = new GLdouble[3]{ -0.65, 0.35, 0 };
		c = new GLdouble[3]{ -0.2, 0.3, 0.4 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ -0.2, 0.3, 0.4 };
		b = new GLdouble[3]{ -0.65, 0.35, 0 };
		c = new GLdouble[3]{ -0.55, 0.25, 0.4 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };

	}
	{
		a = new GLdouble[3]{ -0.2, 0.3, 0.4 };
		b = new GLdouble[3]{ -0.2, -0.2, 0.4 };
		c = new GLdouble[3]{ -0.15, 0.25, 0.7 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ -0.15, 0.25, 0.7 };
		b = new GLdouble[3]{ -0.2, -0.2, 0.4 };
		c = new GLdouble[3]{ -0.15, -0.15, 0.7 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ -0.2, -0.2, 0.4 };
		b = new GLdouble[3]{ 0.2, 0, 0.4 };
		c = new GLdouble[3]{ -0.15, -0.15, 0.7 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ -0.15, -0.15, 0.7 };
		b = new GLdouble[3]{ 0.2, 0, 0.4 };
		c = new GLdouble[3]{ 0.15, 0, 0.7 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		

		a = new GLdouble[3]{ 0.2, 0, 0.4 };
		b = new GLdouble[3]{ -0.2, 0.3, 0.4 };
		c = new GLdouble[3]{ 0.15, 0, 0.7 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };


		a = new GLdouble[3]{ 0.15, 0, 0.7 };
		b = new GLdouble[3]{ -0.2, 0.3, 0.4 };
		c = new GLdouble[3]{ -0.15, 0.25, 0.7 };
		norm = getNormal(a, b, c);

		current[k++] = (Vertex) { {a[0], a[1], a[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {b[0], b[1], b[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
		current[k++] = (Vertex) { {c[0], c[1], c[2]}, { R,G,B }, { norm[0], norm[1], norm[2] } };
	}

	return current;
}

void addRockLarge(std::vector<GLuint>& vaoArr, std::vector<GLuint>& sizes, struct Vertex* cone) {
	GLuint vao, vbo[1];

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	print((float)s);

	glBufferData(GL_ARRAY_BUFFER, (s) * sizeof(struct Vertex), cone, GL_STATIC_DRAW);

	glVertexAttribPointer((GLuint)0, 3, GL_DOUBLE, GL_FALSE, sizeof(struct Vertex), (const GLvoid*)offsetof(struct Vertex, position));
	glEnableVertexAttribArray(0);

	glVertexAttribPointer((GLuint)1, 3, GL_FLOAT, GL_FALSE, sizeof(struct Vertex), (const GLvoid*)offsetof(struct Vertex, color));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer((GLuint)2, 3, GL_FLOAT, GL_FALSE, sizeof(struct Vertex), (const GLvoid*)offsetof(struct Vertex, normal));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0);

	vaoArr.push_back(vao);
	sizes.push_back(s);
}

void translateRockLarge(glm::vec3 translation, struct Vertex* sphere) {
	for (int i = 0; i < s; i+=3) {
		GLdouble* pos1 = sphere[i].position;
		GLdouble* pos2 = sphere[i+1].position;
		GLdouble* pos3 = sphere[i+2].position;

		sphere[i].position[0] = pos1[0] + translation.x;
		sphere[i].position[1] = pos1[1] + translation.y;
		sphere[i].position[2] = pos1[2] + translation.z;

		sphere[i + 1].position[0] = pos2[0] + translation.x;
		sphere[i + 1].position[1] = pos2[1] + translation.y;
		sphere[i + 1].position[2] = pos2[2] + translation.z;

		sphere[i + 2].position[0] = pos3[0] + translation.x;
		sphere[i + 2].position[1] = pos3[1] + translation.y;
		sphere[i + 2].position[2] = pos3[2] + translation.z;

		GLdouble* norm = getNormal(pos1, pos2, pos3);

		sphere[i].normal[0] = norm[0];
		sphere[i].normal[1] = norm[1];
		sphere[i].normal[2] = norm[2];

		sphere[i + 1].normal[0] = norm[0];
		sphere[i + 1].normal[1] = norm[1];
		sphere[i + 1].normal[2] = norm[2];

		sphere[i + 2].normal[0] = norm[0];
		sphere[i + 2].normal[1] = norm[1];
		sphere[i + 2].normal[2] = norm[2];
	}
}