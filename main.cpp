#include <iostream>
// #include <GL/glew.h>
// #include <GLFW/glfw3.h>
#include <cmath>
#include "Sensor.h"
#include "SensorFactory.h"
#include "AerospaceControlSystem.h"

int main()
{
	// start of question 1

	std::cout << "########## START OF QUESTION 1 ##########" << std::endl;
	std::cout << std::endl;

	AerospaceControlSystem ctrlSys; // creation of object specified in class

	ctrlSys.addSensor(SensorFactory::createSensor("temperature"));
	ctrlSys.addSensor(SensorFactory::createSensor("pressure"));
	ctrlSys.addSensor(SensorFactory::createSensor("altitude")); // static function in SensorFactory library is used to input pointer into addSensor() of object

	ctrlSys.monitorAndAdjust(); // output

	std::cout << std::endl;
	std::cout << "########## END OF QUESTION 1 ##########" << std::endl;
	std::cout << std::endl;

	// end of question 1

	// start of question 2

	std::cout << "########## START OF QUESTION 2 ##########" << std::endl;
	std::cout << std::endl;



	std::cout << std::endl;
	std::cout << "########## END OF QUESTION 2 ##########" << std::endl;
	std::cout << std::endl;

	// end of question 2

	// start of question 3

	std::cout << "########## START OF QUESTION 3 ##########" << std::endl;
	std::cout << std::endl;



	std::cout << std::endl;
	std::cout << "########## END OF QUESTION 3 ##########" << std::endl;
	std::cout << std::endl;

	// end of question 3

	// start of question 4

	std::cout << "########## START OF QUESTION 4 ##########" << std::endl;
	std::cout << std::endl;

	//if (!glfwInit()) {
	//	std::cerr << "Failed to initialize GLFW" << std::endl;
	//	return -1;
	//}

	//GLFWwindow* window = glfwCreateWindow(500, 500, "Sine Curve using OpenGL with GLEW and GLFW", NULL, NULL);
	//if (!window) {
	//	std::cerr << "Failed to create GLFW window" << std::endl;
	//	glfwTerminate();
	//	return -1;
	//}

	//glfwMakeContextCurrent(window);

	//if (glewInit() != GLEW_OK) {
	//	std::cerr << "Failed to initialize GLEW" << std::endl;
	//	return -1;
	//}

	//glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	//while (!glfwWindowShouldClose(window)) {
	//	glClear(GL_COLOR_BUFFER_BIT);

	//	glBegin(GL_LINES);
	//	// Draw X and Y axis
	//	glColor3f(1.0, 1.0, 1.0);
	//	glVertex2f(-1.0, 0.0);
	//	glVertex2f(1.0, 0.0);
	//	glVertex2f(0.0, 1.0);
	//	glVertex2f(0.0, -1.0);

	//	// Plot sine curve
	//	glColor3f(0.0, 1.0, 0.0);
	//	for (float i = 0; i < 2 * 3.14159; i += 0.001) {
	//		float x = (2 * i - 3.14159) / 3.14159;
	//		float y = sin(i);
	//		glVertex2f(x, y - 0.001);
	//		glVertex2f(x, y);
	//	}
	//	glEnd();

	//	glfwSwapBuffers(window);
	//	glfwPollEvents();
	//}

	//glfwTerminate();

	std::cout << std::endl;
	std::cout << "########## END OF QUESTION 4 ##########" << std::endl;
	std::cout << std::endl;

	// end of question 4

	// start of question 5

	std::cout << "########## START OF QUESTION 5 ##########" << std::endl;
	std::cout << std::endl;



	std::cout << std::endl;
	std::cout << "########## END OF QUESTION 5 ##########" << std::endl;
	std::cout << std::endl;

	// end of question 5

	// start of question 6

	std::cout << "########## START OF QUESTION 6 ##########" << std::endl;
	std::cout << std::endl;



	std::cout << std::endl;
	std::cout << "########## END OF QUESTION 6 ##########" << std::endl;
	std::cout << std::endl;

	// end of question 6

	return 0;
}