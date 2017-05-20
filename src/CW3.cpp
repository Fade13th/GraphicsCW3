#include "CW3.h"

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if ((key == GLFW_KEY_ESCAPE || key == GLFW_KEY_Q) && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

int main(void) {
	int k = 0;
	GLFWwindow* window;
	if (!glfwInit()) {
		printf("Failed to start GLFW\n");
		exit(EXIT_FAILURE);
	}

#ifdef __APPLE__
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif

	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window) {
		glfwTerminate();
		printf("GLFW Failed to start\n");
		return -1;
	}
	glfwMakeContextCurrent(window);

#ifndef __APPLE__
	glewExperimental = GL_TRUE;
	int err = glewInit();
	if (GLEW_OK != err) {
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
	}
#endif

	glfwSetKeyCallback(window, key_callback);
	fprintf(stderr, "GL INFO %s\n", glGetString(GL_VERSION));
	glEnable(GL_DEPTH_TEST);


	SetupGeometry();
	SetupShaders();
	
	Check("Load Scene");

	Move(glm::vec3(0.0f, 0.0f, -10.0f));
	Rotate(0.40f, glm::vec3(1.0f, 0.0f, 0.0f));

	while (!glfwWindowShouldClose(window)) {
		Render(k);

		k++;
		glfwSwapBuffers(window);
		glfwPollEvents();

	}
	glfwTerminate();
	exit(EXIT_SUCCESS);
}
