#include "World.h"

static GLchar *vertexsource, *geomsource, *fragmentsource;

static GLuint vertexshader, geomshader, fragmentshader;

static GLuint shaderprogram;
static GLuint vao, vao_cone, vbo[1], vbo_cone[1]; 

std::vector<GLuint> StaticBits;
std::vector<GLuint> StaticBitSizes;

static int sphereSplits = 4;

GLfloat GetF3dVectorLength(glm::vec3 v)
{
	GLfloat tot = (v[0] * v[0]) + (v[1] * v[1]) + (v[2] * v[2]);

	return (GLfloat)(sqrt(tot) );
} 

glm::vec3 Normalize3dVector(glm::vec3 v)
{
	glm::vec3 res;
	float l = GetF3dVectorLength(v);
	if (l == 0.0f) return glm::vec3(0,0,0);
	res.x = v.x / l;
	res.y = v.y / l;
	res.z = v.z / l;
	return res;
}

glm::vec3 operator+ (glm::vec3 v, glm::vec3 u)
{
	glm::vec3 res;
	res.x = v.x + u.x;
	res.y = v.y + u.y;
	res.z = v.z + u.z;
	return res;
}
glm::vec3 operator- (glm::vec3 v, glm::vec3 u)
{
	glm::vec3 res;
	res.x = v.x - u.x;
	res.y = v.y - u.y;
	res.z = v.z - u.z;
	return res;
}


glm::vec3 operator* (glm::vec3 v, float r)
{
	glm::vec3 res;
	res.x = v.x*r;
	res.y = v.y*r;
	res.z = v.z*r;
	return res;
}

glm::vec3 CrossProduct(glm::vec3 * u, glm::vec3 * v)
{
	glm::vec3 resVector;
	resVector.x = u->y*v->z - u->z*v->y;
	resVector.y = u->z*v->x - u->x*v->z;
	resVector.z = u->x*v->y - u->y*v->x;

	return resVector;
}
float operator* (glm::vec3 v, glm::vec3 u)	//dot product
{
	return v.x*u.x + v.y*u.y + v.z*u.z;
}

void SetupGeometry() {
	//struct Vertex* sphere = makeSphere(4, 1, glm::vec3(1,1,0));
	//translateSphere(glm::vec3(0.0f, 3.0f, 3.0f), sphere);
	//addSphere(StaticBits, StaticBitSizes, sphere);

	//struct Vertex* tri = makeTri();
	//addTri(StaticBits, StaticBitSizes, tri);

	//sphere = makeSphere(4, 1);
	//translateSphere(glm::vec3(0.0f, -5.0f, 0.0f), sphere);
	//addSphere(StaticBits, StaticBitSizes, sphere);
	
	//struct Vertex* cone = makeCone(1, 3, glm::vec3(0,1,0));
	//translateCone(glm::vec3(1.8f, 0.0f, -2.0f), cone);
	//addCone(StaticBits, StaticBitSizes, cone);

	//cone = makeCone(1, 2, glm::vec3(0,1,0));
	//translateCone(glm::vec3(1.8f, 0.0f, 2.0f), cone);
	//addCone(StaticBits, StaticBitSizes, cone);
	
	//makeTree(glm::vec3(0, 0.4, 0.05));
	//addTree(StaticBits, StaticBitSizes);

	makeColusseum(35.0f, 40.0f, 25.0f, glm::vec3(0.2f,0.3f,0.2f));
	addColusseum(StaticBits, StaticBitSizes);

	struct Vertex* rock = makeRockLarge(glm::vec3(0.2f, 0.1f, 0.0f));
	translateRockLarge(glm::vec3(2.0f, 0.0f, 0.0f), rock);
	addRockLarge(StaticBits, StaticBitSizes, rock);

	makeTank(glm::vec3(0.0f, 1.0f, 0.0f));
	translateTank(glm::vec3(0.0f, -2.0f, 0.0f));
	addTank(StaticBits, StaticBitSizes);
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

glm::vec3 Position = glm::vec3(0, 0, 0);
glm::vec3 ViewDir = glm::vec3(0, 0, -1);
glm::vec3 RightVector = glm::vec3(1, 0, 0);
glm::vec3 UpVector = glm::vec3(0, 1, 0);

GLfloat RotX = 0.0f, RotY = 0.0f, RotZ = 0.0f;

glm::mat4 View = glm::mat4(1.);

GLfloat speed = 0;
GLfloat speedIncrement = 0.005;

void IncreaseSpeed() {
	speed += speedIncrement;
}

void DecreaseSpeed() {
	if (speed > 0) {
		speed -= speedIncrement;
	}
}

void RotateX(GLfloat angle) {
	RotX += angle;

	ViewDir = Normalize3dVector(ViewDir*cos(angle*(M_PI / 180)) + UpVector*sin(angle*(M_PI/180)));

	UpVector = CrossProduct(&ViewDir, &RightVector)*-1;
}

void RotateY(GLfloat angle) {
	RotY += angle;

	ViewDir = Normalize3dVector(ViewDir*cos(angle*(M_PI / 180)) - RightVector*sin(angle*(M_PI / 180)));

	RightVector = CrossProduct(&ViewDir, &UpVector);
}

void RotateZ(GLfloat angle) {
	RotZ += angle;

	RightVector = Normalize3dVector(RightVector*cos(angle*(M_PI / 180))	+ UpVector*sin(angle*(M_PI / 180)));

	UpVector = CrossProduct(&ViewDir, &RightVector)*-1;
}

void MoveToPos(glm::vec3 pos) {

}

void Move(glm::vec3 Direction) {
	Position = Position + (Direction * speed);
}

static void MoveCamera() {
	glm::vec3 target = Position + ViewDir;

	glm::vec3 forward = glm::vec3(0, 0, -1);

	View = glm::lookAt(Position,
		target,
		UpVector);

	Move(ViewDir);
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
	
	MoveCamera();

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