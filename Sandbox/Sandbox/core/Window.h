#pragma once

#include "Platform.h"
#include "SString.h"

namespace sandbox
{
	/// @brief	Class representing a window for a sandbox application
	class DLL_SPEC Window
	{
	public:
		/// @brief	Constructor.
		/// @param x	 	The x pixel coordinate of the window.
		/// @param y	 	The y pixel coordinate of the window.
		/// @param width 	The width of the window.
		/// @param height	The height of the window.
		/// @param name  	The name of the window.
		Window(unsigned int x, unsigned int y, unsigned int width, unsigned int height, sandbox::SString name = "untitled");
		/// @brief	Gets the width.
		/// @return	The width.
		unsigned int getWidth() const;
		/// @brief	Sets a width.
		/// @param val	The value.
		void setWidth(unsigned int val);
		/// @brief	Gets the height.
		/// @return	The height.
		unsigned int getHeight() const;
		/// @brief	Sets a height.
		/// @param val	The value.
		void setHeight(unsigned int val);
		/// @brief	Get x coordinate.
		/// @return	The x coordinate.
		unsigned int getX() const;
		/// @brief	Sets an x coordinate.
		/// @param val	The value.
		void setX(unsigned int val);
		/// @brief	Get y coordinate.
		/// @return	The y coordinate.
		unsigned int getY() const;
		/// @brief	Sets a y coordinate.
		/// @param val	The value.
		void setY(unsigned int val);
		/// @brief	Gets the name.
		/// @return	The name.
		SString getName() const;
		/// @brief	Sets a name.
		/// @param val	The value.
		void setName(SString val);

	private:
		unsigned int m_width;
		unsigned int m_height;
		unsigned int m_x;
		unsigned int m_y;
		sandbox::SString m_name;
	};
}