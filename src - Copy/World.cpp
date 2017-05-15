#include "World.h"

static GLchar *vertexsource, *fragmentsource;

static GLuint vertexshader, fragmentshader;

static GLuint shaderprogram;
static GLuint vao, vao_cone, vbo[1], vbo_cone[1]; 

std::vector<GLuint*> StaticBitsVAO;
std::vector<GLuint*> StaticBitsVBO[1];

static int sphereSplits = 4;

void SetupGeometry() {
	struct Vertex *tetrahedron = makeSphere(sphereSplits, 1);

	struct Vertex *cone = makeCone();

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);

	glBufferData(GL_ARRAY_BUFFER, 24 * pow(4, sphereSplits) * sizeof(struct Vertex), tetrahedron, GL_STATIC_DRAW);

	glVertexAttribPointer((GLuint)0, 3, GL_DOUBLE, GL_FALSE, sizeof(struct Vertex), (const GLvoid*)offsetof(struct Vertex, position));
	glEnableVertexAttribArray(0);

	glVertexAttribPointer((GLuint)1, 3, GL_FLOAT, GL_FALSE, sizeof(struct Vertex), (const GLvoid*)offsetof(struct Vertex, color)); 

	glEnableVertexAttribArray(1);
	glBindVertexArray(0);

	//Now set up cone
	glGenVertexArrays(1, &vao_cone);
	glBindVertexArray(vao_cone);

	glGenBuffers(1, vbo_cone);

	glBindBuffer(GL_ARRAY_BUFFER, vbo_cone[0]);

	glBufferData(GL_ARRAY_BUFFER, 240 * sizeof(struct Vertex), cone, GL_STATIC_DRAW);

	glVertexAttribPointer((GLuint)0, 3, GL_DOUBLE, GL_FALSE, sizeof(struct Vertex), (const GLvoid*)offsetof(struct Vertex, position));
	glEnableVertexAttribArray(0);

	glVertexAttribPointer((GLuint)1, 3, GL_FLOAT, GL_FALSE, sizeof(struct Vertex), (const GLvoid*)offsetof(struct Vertex, color)); 

	glEnableVertexAttribArray(1);
	glBindVertexArray(0);
}

void SetupShaders(void) {
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

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
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 24 * pow(4, sphereSplits));
	glBindVertexArray(0);


	View = glm::mat4(1.);
	View = glm::translate(View, glm::vec3(-8.0f, 5.0f, -9.0f));
	View = glm::translate(View, glm::vec3(time*0.02f, time*-0.03f, 0.0f));
	View = glm::rotate(View, angle * -1.0f, glm::vec3(1.f, 0.f, 0.f));
	Model = glm::mat4(1.0);
	MVP = Projection * View * Model;
	glUniformMatrix4fv(glGetUniformLocation(shaderprogram, "mvpmatrix"), 1, GL_FALSE, glm::value_ptr(MVP));
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 24 * pow(4, sphereSplits));
	glBindVertexArray(0);

	View = glm::mat4(1.);
	View = glm::translate(View, glm::vec3(8.0f, 0.0f, -9.0f));
	View = glm::translate(View, glm::vec3(time*-0.08f, 0.0f, 0.0f));
	View = glm::rotate(View, angle * -1.0f, glm::vec3(1.f, 0.f, 0.f));
	Model = glm::mat4(1.0);
	MVP = Projection * View * Model;
	glUniformMatrix4fv(glGetUniformLocation(shaderprogram, "mvpmatrix"), 1, GL_FALSE, glm::value_ptr(MVP));
	glBindVertexArray(vao_cone);
	glDrawArrays(GL_TRIANGLES, 0, 240);
	glBindVertexArray(0);

	View = glm::mat4(1.);
	View = glm::translate(View, glm::vec3(3.0f, 8.0f, -12.0f));
	View = glm::translate(View, glm::vec3(-0.002f *time, -0.03f*time, 0.0f));
	View = glm::rotate(View, angle * 0.5f, glm::vec3(0.f, 0.f, 1.f));
	Model = glm::mat4(1.0);
	MVP = Projection * View * Model;
	glUniformMatrix4fv(glGetUniformLocation(shaderprogram, "mvpmatrix"), 1, GL_FALSE, glm::value_ptr(MVP));
	glBindVertexArray(vao_cone);
	glDrawArrays(GL_TRIANGLES, 0, 240);
	glBindVertexArray(0);

	time++;
}