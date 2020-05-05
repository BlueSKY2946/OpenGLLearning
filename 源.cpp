#define GLEW_STATIC

#include<iostream>
#include<GL/glew.h>
#include<GLFW/glfw3.h>


using namespace std;
/*
float vertices[] = {
	-0.5f, -0.5f, 0.0f,
	0.5f, -0.5f, 0.0f,
	0.0f, 0.5f, 0.0f
};
*/

void processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

void draw()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(3.0f);
	glBegin(GL_POINTS);

	// 点
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-0.8f, 0.8f);
	glEnd();

	// 线
	glLineWidth(2);//设置线段宽度
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-0.5f, 0.8f); //定点坐标范围
	glVertex2f(-0.3f, 0.4f);
	glEnd();

	// 多线段
	glBegin(GL_LINE_STRIP);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0.0f, 0.4f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0.3f, 0.4f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0.1f, 0.6f);
	glEnd();

	// 循环线
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0.4f, 0.6f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0.7f, 0.6f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0.475f, 0.4f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0.55f, 0.8f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0.625f, 0.4f);
	glEnd();

	// 三角形
	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0);    // Red
	glVertex3f(-0.8, 0.0, 0.0);
	glColor3f(0.0, 1.0, 0.0);    // Green
	glVertex3f(-0.6, -0.8, 0.0);
	glColor3f(0.0, 0.0, 1.0);    // Blue
	glVertex3f(-0.4, 0.0, 0.0);
	glEnd();

	// 三角形条带
	glBegin(GL_TRIANGLE_STRIP);
	for (int i = 0; i < 10; i++) {
		glColor3f(0.1 + (i % 3) * 0.3, 0.9 - (i % 3) * 0.3, 0.1 + (i % 3) * 0.3);
		glVertex3f(-0.2 + i * 0.1, -0.4 + pow(-1 , i) * 0.1, 0.0);
	}

	glEnd();
	glFlush();
}


int main() {
	glfwInit();
	// glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	// glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_PROFILE);


	// Open GLFW Window
	GLFWwindow* window = glfwCreateWindow(800, 600, "My OpenGl Game",NULL, NULL);
	if (window == NULL) {
		cout << "Open Window Failed" << endl;
		glfwTerminate();

		return -1;
	}
	glfwMakeContextCurrent(window);


	// Init GLEW
	glewExperimental = true;
	if (glewInit() != GLEW_OK)
	{
		cout << "Init GLEW Failed" << endl;
		glfwTerminate();

		return -1;
	}

	glViewport(0, 0, 800, 600);
/*
	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	*/


	while (!glfwWindowShouldClose(window)) {
		// input 
		processInput(window);


		// rendering
		// glClearColor(0.1f, 0.1f, 0.3f, 1.0f);
		// glClear(GL_COLOR_BUFFER_BIT);

		draw();
		// check and call events and swap the buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}