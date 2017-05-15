#include "World.h"

static GLchar *vertexsource, *fragmentsource;

static GLuint vertexshader, fragmentshader;

static GLuint shaderprogram;
static GLuint vao, vao_cone, vbo[1], vbo_cone[1]; 

std::vector<GLuint> StaticBits;

static int sphereSplits = 4;

void SetupGeometry() {
	struct Vertex* sphere = makeSphere(4, 1);
	translateSphere(glm::vec3(0.0f, 5.0f, 0.0f), sphere);
	addSphere(StaticBits, sphere);

	sphere = makeSphere(4, 1);
	translateSphere(glm::vec3(0.0f, -5.0f, 0.0f), sphere);
	addSphere(StaticBits, sphere);

	struct Vertex* cone = makeCone();
	translateCone(glm::vec3(1.8f, 0.0f, -2.0f), cone);
	addCone(StaticBits, cone);
}

void SetupShaders(void) {
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	vertexsource = filetobuf("./World.vert");
	fragmentsource = filetobuf("./World.frag");

	vertexshader = glCreateShader(GL_VERTEX_SHADER);
	fragmentshader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vertexshader, 1, (const GLchar**)&vertexsource, 0);
	glShaderSource(fragmentshader, 1, (const GLchar**)&fragmentsource, 0);

	glCompileShader(vertexshader);
	glCompileShader(fragmentshader);

	shaderprogram = glCreateProgram();
	glAttachShader(shaderprogram, vertexshader);
	glAttachShader(shaderprogram, fragmentshader);
	glBindAttribLocation(shaderprogram, 0, "in_Position"); 
	glBindAttribLocation(shaderprogram, 1, "in_Color");
	glLinkProgram(shaderprogram);
	glUseProgram(shaderprogram);
}

static int time = 0;
void Render(int i) {
	
	if (time > 500)
		time = 0;

	GLfloat angle;
	glm::mat4 Projection = glm::perspective(45.0f, 1.0f, 0.1f, 100.0f);
	float t = glfwGetTime();
	float p = 400.;
	t = fmod(t, p);
	angle = t * 360. / p;
	glm::mat4 View = glm::mat4(1.);
	View = glm::translate(View, glm::vec3(-5.0f, -5.0f, -8.0f));
	View = glm::translate(View, glm::vec3(time*0.05f, time*0.05f, 0.0f));
	View = glm::rotate(View, angle * -1.0f, glm::vec3(1.f, 0.f, 0.f));
	glm::mat4 Model = glm::mat4(1.0);
	glm::mat4 MVP = Projection * View * Model;
	glUniformMatrix4fv(glGetUniformLocation(shaderprogram, "mvpmatrix"), 1, GL_FALSE, glm::value_ptr(MVP));

	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (int i = 0; i < StaticBits.size(); i++) {
		GLuint v = StaticBits.at(i);
		glBindVertexArray(v);
		glDrawArrays(GL_TRIANGLES, 0, 24 * pow(4, sphereSplits));
		glBindVertexArray(0);
	}

	time++;
}