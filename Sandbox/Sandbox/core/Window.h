#pragma once

#include "Platform.h"
#include "core/String.h"
#include <string>

namespace smartray
{
	class DLL_SPEC Window
	{
	public:
		Window(unsigned int x, unsigned int y, unsigned int width, unsigned int height, sandbox::String name = "untitled");


		unsigned int getWidth() const;
		void setWidth(unsigned int val);
		unsigned int getHeight() const;
		void setHeight(unsigned int val);
		unsigned int getX() const;
		void setX(unsigned int val);
		unsigned int getY() const;
		void setY(unsigned int val);
		sandbox::String getName() const;
		void setName(sandbox::String val);

	private:
		unsigned int m_width;
		unsigned int m_height;
		unsigned int m_x;
		unsigned int m_y;
		sandbox::String m_name;

		
	};



	
	

}