#include <iostream>
// #include <GL/glew.h>
// #include <GLFW/glfw3.h>
#include <cmath>
#include "Sensor.h"
#include "SensorFactory.h"
#include "AerospaceControlSystem.h"
#include <thread>
#include <chrono>
#include <mutex>

std::mutex robotOrder; 
// this mutex variable makes sure that the output for simultaneous tasks in question 2 do not get mixed

void robot_task(int robot_number) // this function takes in the number of the robot and performs its task
{
	robotOrder.lock(); // locking to make sure outputs do not get mixed for simulataneous tasks
	std::cout << "Robot " << robot_number << " is collection data." << std::endl;
	robotOrder.unlock(); // unlocking so following task can display output
	std::this_thread::sleep_for(std::chrono::seconds(1)); // takes robot 1 second to grab tools.
	robotOrder.lock();
	std::cout << "Robot " << robot_number << " acquired tools and starts performing a task." << std::endl;
	robotOrder.unlock();
	std::this_thread::sleep_for(std::chrono::seconds(5)); // takes robot 5 seconds to perform task and return tools.
	robotOrder.lock();
	std::cout << "Robot " << robot_number << " finished the task and has returned tools." << std::endl;
	robotOrder.unlock();
}

int main()
{
	// start of question 1

	std::cout << "########## START OF QUESTION 1 ##########" << std::endl;
	std::cout << std::endl;

	AerospaceControlSystem ctrlSys; // creation of AerospaceControlSystem object

	ctrlSys.addSensor(SensorFactory::createSensor("temperature"));
	ctrlSys.addSensor(SensorFactory::createSensor("pressure"));
	ctrlSys.addSensor(SensorFactory::createSensor("altitude")); 
	// static function in SensorFactory library is used to input pointer into addSensor() of object

	ctrlSys.monitorAndAdjust(); // output

	std::cout << std::endl;
	std::cout << "########## END OF QUESTION 1 ##########" << std::endl;
	std::cout << std::endl;

	// end of question 1

	// start of question 2

	std::cout << "########## START OF QUESTION 2 ##########" << std::endl;
	std::cout << std::endl;

	/*
	This problem asks to create a code which recreates the fastest time for the robots to finish their tasks given
	the conditions stated in the problem. The shortest time possible for the robots to finish the tasks is 18
	seconds. This is because given that there are 5 robots in a circle and they each have a tool in between them
	and they need two tools to perform ther task, this means that only two robots who are not adjacent to each 
	other can be working on the task simultaneously. If we label the robots 1 to 5 around the circle, this would
	mean that for the most optimal time to finish all the tasks, robots 1 and 3 would work first simultaneously,
	then 2 and 4, and finally robot 5. Since each task takes 6 seconds total (including getting and returning 
	tools). This would mean that the total time would be 6 seconds + 6 seconds + 6 seconds = 18 seconds.
	*/

	auto startTime = std::chrono::high_resolution_clock::now(); // starting time of question

	std::thread robot1(robot_task, 1); // creation of task for robot 1
	std::thread robot3(robot_task, 3); // creation of task for robot 3

	robot1.join(); // end of task for robot 1
	robot3.join(); // end of task for robot 3

	std::thread robot2(robot_task, 2); // creation of task for robot 2
	std::thread robot4(robot_task, 4); // creation of task for robot 4

	robot2.join(); // end of task for robot 2
	robot4.join(); // end of task for robot 4

	std::thread robot5(robot_task, 5); // creation of task for robot 5

	robot5.join(); // end of task for robot 5

	auto stopTime = std::chrono::high_resolution_clock::now(); // stopping time of querstion
	auto duration = std::chrono::duration_cast<std::chrono::seconds>(stopTime - startTime); // calculation of duration
	std::cout << "duration : " << duration.count() << " seconds" << std::endl; // displaying duration

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

	return 0;
}