#pragma once

#include "Platform.h"

namespace sandbox
{
	/* Application status enum, 
	OnIdle: application is not launch
	OnInit: application is in initialization, allocating all systems
	OnRun: application is running
	OnStop: application shutdown and destroy all data*/
	enum
	{
		onIdle,
		onInit,
		onRun,
		onStop
	}typedef ApplicationStatus;

	class Window;

	/// Class representing a Sandbox application, you have to derived this to create a new app
	class DLL_SPEC Application
	{
	public:

		/// @brief	Default constructor. constructor set application status to OnIdle state.
		Application();
		/// @brief	Destructor.
		~Application();
		/// @brief	Starts the application update loop.
		void run();
		/// @brief	Stops and destroy all window instance and 3D context.
		void stop();
		/// @brief	Gets application window.
		/// @return	null if it fails, else the application window.
		const Window* getApplicationWindow() const;
		/// @brief	Gets the current application status.
		/// @return	The current status.
		ApplicationStatus getStatus() const;
		/// @brief	Sets application window.
		/// @param [in,out] win	If non-null, the window.
		void setApplicationWindow(Window* win);
	
	protected:
		/// Engine is ready, All systems(Render, Scene manager, Physics,...) has been created.
		virtual void engineReady() {};

	private:
		struct ApplicationPImpl;
		ApplicationPImpl* m_pImpl;

		
	};
}