#include "Application.h"
#include "utils/SmartLogger.h"
//#include "EventService.h"
//#include "SceneService.h"
//#include "RenderingService.h"
#include "utils/Timer.h"
//#include "InputService.h"
#include "glfw3.h"

using namespace smartray;
using namespace std;

Application::Application():
	m_mainWindow(nullptr)
{
	setStatus(onIdle);

}

bool
Application::initVideoSettings()
{
	if (getStatus() == onIdle)
	{
		setStatus(onInit);

		if (!glfwInit())
		{
			return false;
		}

		bool initWin = initWindow();

		return initWin;
	}
	return false;
}

void
Application::run()
{
	bool initSucceeded = initVideoSettings();
	SMARTLOG("-----SmartRay Started-----", kInfo);
	Timer t;
	if (initSucceeded)
	{
		//RenderingService::getInstance();
		//EventService::getInstance();
		engineReady();
		setStatus(onRun);

		t.start();
		while (getStatus() == onRun)
		{
			while (!glfwWindowShouldClose(m_glfwWindow))
			{
				//SceneService::getInstance()->update(t.eleapsed());

				//RenderingService::getInstance()->render();
				glfwSwapBuffers(m_glfwWindow);
				glfwPollEvents();
				t.end();
			}
			stop();
		}

		
	}

}

void
Application::stop()
{
	setStatus(onStop);
	glfwTerminate();
}

// static void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
// {
// 	InputService::getInstance()->registerCursorPosition((unsigned int)xpos, (unsigned int)ypos);
// }
// 
// static void mouseButtonPressedReleased(int action, MouseButton button)
// {
// 	if (action == GLFW_PRESS)
// 	{
// 		InputService::getInstance()->registerMouseButton(button, kPressed);
// 	}
// 	else if (action == GLFW_RELEASE)
// 	{
// 		InputService::getInstance()->registerMouseButton(button, kReleased);
// 	}
// }

static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT)
	{
		//mouseButtonPressedReleased(action, kLeftMouseButton);
	}
	if (button == GLFW_MOUSE_BUTTON_RIGHT)
	{
		//mouseButtonPressedReleased(action, kRightMouseButton);
	}
}

static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}

	if (action == GLFW_PRESS)
	{
		//InputService::getInstance()->registerKeyEvent(key, kPressed);
	}
	else if (action == GLFW_RELEASE)
	{
		//InputService::getInstance()->registerKeyEvent(key, kReleased);
	}
}

bool
Application::initWindow()
{
	if (m_glfwWindow)
	{
		//TODO delete old glfw win
	}

	if (m_mainWindow && getStatus() == onInit)
	{
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		m_glfwWindow = glfwCreateWindow(
			m_mainWindow->getWidth(), 
			m_mainWindow->getHeight(), 
			m_mainWindow->getName().getCString(), 
			nullptr, nullptr);

		if (!m_glfwWindow)
		{
			stop();
			return false;
		}

		glfwMakeContextCurrent(m_glfwWindow);

		//glfwSetKeyCallback(m_glfwWindow, keyCallback);
		//glfwSetMouseButtonCallback(m_glfwWindow, mouseButtonCallback);
		//glfwSetCursorPosCallback(m_glfwWindow, cursorPositionCallback);
		return true;
	}
	return false;
}

const Window*
Application::getWindow() const
{
	return m_mainWindow;
}


void
Application::setMainWindow(Window* win)
{
	if (m_status == onIdle)
	{
		m_mainWindow = win;
	}
}

void
Application::setStatus(ApplicationStatus status)
{
	m_status = status;
}
