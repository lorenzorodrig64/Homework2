#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include "Sensor.h"
#include "SensorFactory.h"
#include "AerospaceControlSystem.h"
#include <thread>
#include <chrono>
#include <mutex>

std::mutex output; 
// this mutex variable is used throughtout questions 2 and 3 in order to prevent simultaneous outputs to be printed at the same time.
std::mutex tools[5];
// this mutex variable represents the 5 tools in between the 5 robots (question 2)

void robot_task(int robot_number) // this function takes in the number of the robot and performs its task (question 2)
{
	int leftTool = robot_number;
	int rightTool = (robot_number + 1) % 5;
	// the calculation for the number of the right tool makes sure it is never adjacent to the left tool

	if (leftTool > rightTool) std::swap(leftTool, rightTool);
	// this will prevent deadlocking by making sure the lower-index tool gets locked first

	std::this_thread::sleep_for(std::chrono::seconds(1));
	// time each robot takes to reach for tools

	std::lock(tools[leftTool], tools[rightTool]); 
	// robot acquires adjacent tools. Locking mutexes of adjacent tools to robot prevents adjacent robots to work at the same time

	std::lock_guard<std::mutex> lockLeft(tools[leftTool], std::adopt_lock);
	std::lock_guard<std::mutex> lockRight(tools[rightTool], std::adopt_lock);
	// take possession of locks of corresponding tools to make sure that the tools are unlocked after end of thread execution

	output.lock(); // locking to make sure outputs do not get mixed for simulataneous tasks
	std::cout << "Robot " << robot_number << " is collection data." << std::endl;
	output.unlock(); // unlocking so following task can display output
	output.lock();
	std::cout << "Robot " << robot_number << " acquired tools and starts performing a task." << std::endl;
	output.unlock();
	std::this_thread::sleep_for(std::chrono::seconds(5)); // takes robot 5 seconds to perform task and return tools.
	output.lock();
	std::cout << "Robot " << robot_number << " finished the task and has returned tools." << std::endl;
	output.unlock();
}

std::mutex atcCommLock; // mutex for locking ATC communications
std::condition_variable wakeUp; // condition variable used to wake up ATC
std::atomic<int> aircraftInPattern(0); // counts aircrafts currently inside traffic pattern

void attemptToLand(int aircraftNum) 
{
	output.lock(); // output lock to make sure that only one airplane can request to land at the time
	std::cout << "Aircraft #" << aircraftNum << " requesting to land." << std::endl; // initial request to land
	output.unlock();

	std::unique_lock<std::mutex> lock(atcCommLock); // lock for ATC communication

	if (aircraftInPattern >= 3) // if statement which redirects aircraft to another airport if traffic pattern full
	{
		output.lock();
		std::cout << "Traffic pattern full. Aircraft #" << aircraftNum << " redirected to another airport." << std::endl;
		output.unlock();
		return; // thread exits function since it is redirected to another airport
	}

	if (aircraftInPattern == 0)	// if statement which initially wakes up ATC
	{
		wakeUp.notify_one(); // wake up ATC
		output.lock();
		std::cout << "Aircraft " << aircraftNum << " is waking up the ATC." << std::endl;
		output.unlock();
		output.lock();
		std::cout << "Aircraft #" << aircraftNum << " in traffic pattern." << std::endl;
		output.unlock();
	}
	else 
	{
		output.lock();
		std::cout << "Aircraft #" << aircraftNum << " in traffic pattern." << std::endl;
		output.unlock();
	}

	aircraftInPattern++; // increments planes in traffic pattern
	lock.unlock(); // unlock ATC lock to allow other pilots to communicate

	std::this_thread::sleep_for(std::chrono::seconds(1)); // time for planes to land

	lock.lock(); // re-use ATC lock to ensure proper landing by planes
	aircraftInPattern--;
	std::cout << "Aircraft #" << aircraftNum << " has landed." << std::endl;
	if (aircraftInPattern == 0) 
	{
		std::cout << "ATC goes back to sleep." << std::endl; // last aircraft has landed so ATC can go back to sleep
	}
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

	auto startTimeQ2 = std::chrono::high_resolution_clock::now(); // starting time of question

	std::thread robot1(robot_task, 0);
	std::thread robot3(robot_task, 1);
	std::thread robot2(robot_task, 2);
	std::thread robot4(robot_task, 3);
	std::thread robot5(robot_task, 4);
	// declaration of threads representing each robot with their task and number
	// numbering starts at zero in order for tool locking to work

	robot1.join();
	robot2.join();
	robot3.join();
	robot4.join(); 
	robot5.join();
	// robot threads join main thread

	auto stopTimeQ2 = std::chrono::high_resolution_clock::now(); // stopping time of querstion
	auto durationQ2 = std::chrono::duration_cast<std::chrono::seconds>(stopTimeQ2 - startTimeQ2); // calculation of duration
	std::cout << "duration : " << durationQ2.count() << " seconds" << std::endl; // displaying duration

	std::cout << std::endl;
	std::cout << "########## END OF QUESTION 2 ##########" << std::endl;
	std::cout << std::endl;

	// end of question 2

	// start of question 3

	std::cout << "########## START OF QUESTION 3 ##########" << std::endl;
	std::cout << std::endl;

	auto startTimeQ3 = std::chrono::high_resolution_clock::now(); // starting time of question
	
	std::vector<std::thread> airplanes; // vector to contain airplane threads

	for (int i = 1; i <= 10; ++i) {
		airplanes.emplace_back(attemptToLand, i); // adds 10 different threads to vector
	}

	for (auto& t : airplanes) {
		t.join(); // executes all the threads inside the vector
	}

	auto stopTimeQ3 = std::chrono::high_resolution_clock::now(); // stopping time of querstion
	auto durationQ3 = std::chrono::duration_cast<std::chrono::seconds>(stopTimeQ3 - startTimeQ3); // calculation of duration
	std::cout << "duration : " << durationQ3.count() << " seconds" << std::endl; // displaying duration

	std::cout << std::endl;
	std::cout << "########## END OF QUESTION 3 ##########" << std::endl;
	std::cout << std::endl;

	// end of question 3

	// start of question 4

	std::cout << "########## START OF QUESTION 4 ##########" << std::endl;
	std::cout << std::endl;

	std::cout << "A section of the simple harmonic motion equation will be displayed in a new window. " << std::endl;

	if (!glfwInit()) {
		std::cerr << "Failed to initialize GLFW" << std::endl;
		return -1;
	}

	GLFWwindow* window = glfwCreateWindow(500, 500, "Sine Curve using OpenGL with GLEW and GLFW", NULL, NULL);
	if (!window) {
		std::cerr << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK) {
		std::cerr << "Failed to initialize GLEW" << std::endl;
		return -1;
	}

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_LINES);
		// Draw X and Y axis
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(-1.0, 0.0);
		glVertex2f(1.0, 0.0);
		glVertex2f(0.0, 1.0);
		glVertex2f(0.0, -1.0);

		// Draw part of simple harmonic motion equation
		glColor3f(0.0, 1.0, 0.0);
		for (float i = 0; i < 2 * 3.14159; i += 0.001) {
			float x = (2 * i - 3.14159) / 3.14159;
			float y = sin(i);
			glVertex2f(x, y - 0.001);
			glVertex2f(x, y);
		}
		glEnd();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();

	std::cout << std::endl;
	std::cout << "########## END OF QUESTION 4 ##########" << std::endl;

	// end of question 4

	return 0;
}