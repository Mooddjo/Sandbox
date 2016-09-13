#include "Application.h"
#include "SmartLogger.h"
#include "gl/glew.h"
#include "glfw3.h"
#include "MathUtils.h"
#include "Window.h"
#include "EventService.h"
#include "SceneService.h"
#include "GraphicsService.h"
#include "Timer.h"
//#include "InputService.h"

using namespace sandbox;
using namespace std;


struct Application::ApplicationPImpl
{
	ApplicationPImpl(Application* app):m_application(app){}
	/// @brief	Initializes the video settings.
	/// @return	true if it succeeds, false if it fails.
	bool initVideoSettings();
	/// @brief	Initializes the window.
	/// @return	true if it succeeds, false if it fails.
	bool initWindow();
	/// @brief	Sets the application status.
	/// @param status	The new application status.
	void setStatus(ApplicationStatus status);

	ApplicationStatus m_status;
	GLFWwindow* m_glfwWindow;
	Window* m_window;
	sandbox::vec2 m_cursorPosition;
	Application* m_application;
};

Application::Application() :
	m_pImpl(new ApplicationPImpl(this))
{
	m_pImpl->setStatus(onIdle);
}

Application::~Application()
{
	delete m_pImpl;
}

void
Application::ApplicationPImpl::setStatus(ApplicationStatus status)
{
	m_status = status;
}

ApplicationStatus
Application::getStatus() const
{
	return m_pImpl->m_status;
}

bool
Application::ApplicationPImpl::initVideoSettings()
{
	if (m_application->getStatus() == onIdle)
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
	bool initSucceeded = m_pImpl->initVideoSettings();
	SMARTLOG("-----Sandbox Started-----", kInfo);
	Timer t;
	if (initSucceeded)
	{
		GraphicsService* graphicsService = GraphicsService::getInstance();
		EventService::getInstance();
		engineReady();
		m_pImpl->setStatus(onRun);

		t.start();
		while (getStatus() == onRun)
		{
			while (!glfwWindowShouldClose(m_pImpl->m_glfwWindow))
			{
				SceneService::getInstance()->update(t.eleapsed());
				t.start();
				graphicsService->render();
				glfwSwapBuffers(m_pImpl->m_glfwWindow);
				glfwPollEvents();
			}
			stop();
		}


	}

}

void
Application::stop()
{
	//TODO delete all relevant data
	m_pImpl->setStatus(onStop);
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
Application::ApplicationPImpl::initWindow()
{
	if (m_glfwWindow)
	{
		//TODO delete old glfw win
	}

	if (m_window && m_application->getStatus() == onInit)
	{
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		m_glfwWindow = glfwCreateWindow(
			m_window->getWidth(),
			m_window->getHeight(),
			SString("Sandbox Platformer").getCString(),
			nullptr, nullptr);

		glfwSetWindowPos(m_glfwWindow, m_window->getX(), m_window->getY());
		if (!m_glfwWindow)
		{
			m_application->stop();
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
Application::getApplicationWindow() const
{
	return m_pImpl->m_window;
}


void
Application::setApplicationWindow(Window* win)
{
	if (getStatus() == onIdle)
	{
		m_pImpl->m_window = win;
	}
}



