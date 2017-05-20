#include "World.h"

static GLchar *vertexsource, *geomsource, *fragmentsource;

static GLuint vertexshader, geomshader, fragmentshader;

static GLuint shaderprogram;
static GLuint vao, vao_cone, vbo[1], vbo_cone[1]; 

std::vector<GLuint> StaticBits;
std::vector<GLuint> StaticBitSizes;

static int sphereSplits = 4;

void SetupGeometry() {
	struct Vertex* sphere = makeSphere(4, 1);
	translateSphere(glm::vec3(0.0f, 0.0f, 3.0f), sphere);
	addSphere(StaticBits, StaticBitSizes, sphere);

	//struct Vertex* tri = makeTri();
	//addTri(StaticBits, StaticBitSizes, tri);

	//sphere = makeSphere(4, 1);
	//translateSphere(glm::vec3(0.0f, -5.0f, 0.0f), sphere);
	//addSphere(StaticBits, StaticBitSizes, sphere);
	
	struct Vertex* cone = makeCone();
	//translateCone(glm::vec3(1.8f, 0.0f, -2.0f), cone);
	addCone(StaticBits, StaticBitSizes, cone);
/*
	cone = makeCone();
	translateCone(glm::vec3(1.8f, 0.0f, 2.0f), cone);
	addCone(StaticBits, StaticBitSizes, cone);
	
	makeColusseum(35.0f, 40.0f, 25.0f);
	addColusseum(StaticBits, StaticBitSizes);*/
}

void SetupShaders(void) {
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	vertexsource = filetobuf("./World.vert");
	geomsource = filetobuf("./World.geom");
	fragmentsource = filetobuf("./World.frag");

	vertexshader = glCreateShader(GL_VERTEX_SHADER);
	geomshader = glCreateShader(GL_GEOMETRY_SHADER);
	fragmentshader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vertexshader, 1, (const GLchar**)&vertexsource, 0);
	glShaderSource(geomshader, 1, (const GLchar**)&geomsource, 0);
	glShaderSource(fragmentshader, 1, (const GLchar**)&fragmentsource, 0);

	glCompileShader(vertexshader);
	glCompileShader(geomshader);
	glCompileShader(fragmentshader);

	shaderprogram = glCreateProgram();
	glAttachShader(shaderprogram, vertexshader);
	glAttachShader(shaderprogram, geomshader);
	glAttachShader(shaderprogram, fragmentshader);

	glBindAttribLocation(shaderprogram, 0, "in_Position"); 
	glBindAttribLocation(shaderprogram, 1, "in_Color");
	glBindAttribLocation(shaderprogram, 2, "in_Normal");

	glLinkProgram(shaderprogram);
	glUseProgram(shaderprogram);
}

static int time = 0;

glm::mat4 View = glm::mat4(1.);

void Move(glm::vec3 translation) {
	View = glm::translate(View, translation);
}

void Rotate(GLfloat angle, glm::vec3 axis) {
	View = glm::rotate(View, angle * -1.0f, axis);
}

void Render(int i) {
	
	if (time > 500)
		time = 0;

	glm::vec3 light = glm::vec3(0.0f, 0.0f, 10.0f);
	GLfloat angle;
	glm::mat4 Projection = glm::perspective(45.0f, 1.0f, 0.1f, 100.0f);
	float t = glfwGetTime();
	float p = 1000.;
	t = fmod(t, p);
	angle = t * 360. / p;
	//glm::mat4 View = glm::mat4(1.);
	//View = glm::translate(View, glm::vec3(0.0f, 0.0f, -10.0f));
	//View = glm::translate(View, glm::vec3(time*0.05f, time*0.05f, 0.0f));
	//View = glm::rotate(View, angle * -1.0f, glm::vec3(1.f, 0.f, 0.f));
	glm::mat4 Model = glm::mat4(1.0);
	glm::mat4 MVP = Projection * View * Model;

	glm::vec4 V = glm::vec4(1, 1, 1, 0) * View;

	glUniformMatrix4fv(glGetUniformLocation(shaderprogram, "mvpmatrix"), 1, GL_FALSE, glm::value_ptr(MVP));
	glUniform3fv(glGetUniformLocation(shaderprogram, "lightPos"), 1, glm::value_ptr(light));
	glUniform3fv(glGetUniformLocation(shaderprogram, "viewPos"), 1, glm::value_ptr(V));
	glUniform1f(glGetUniformLocation(shaderprogram, "blinn"), 1);

	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (int i = 0; i < StaticBits.size(); i++) {
		GLuint v = StaticBits.at(i);
		glBindVertexArray(v);
		glDrawArrays(GL_TRIANGLES, 0, StaticBitSizes.at(i));
		glBindVertexArray(0);
	}

	time++;
}