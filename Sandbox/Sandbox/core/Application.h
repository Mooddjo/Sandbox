#pragma once


#include "Window.h"
#include "utils/Singleton.h"
#include "gl/glew.h"
#include "glfw3.h"
#include "math/Math.h"
#include <memory>

namespace smartray
{
	DLL_SPEC enum
	{
		onIdle,
		onInit,
		onRun,
		onStop
	}typedef ApplicationStatus;

	class DLL_SPEC Application
	{
	public:

		Application();	
		void run();
		void stop();
		const Window* getWindow() const;
		ApplicationStatus getStatus() { return m_status; }
		void setMainWindow(Window* win);
	
	private:
		virtual void engineReady() {};
		bool initVideoSettings();
		bool initWindow();
		void setStatus(ApplicationStatus status);

		ApplicationStatus m_status;
		GLFWwindow* m_glfwWindow;
		Window* m_mainWindow;
		sandbox::vec2 m_cursorPosition;
	};
}