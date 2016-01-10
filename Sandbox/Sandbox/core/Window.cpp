#include "Window.h"

using namespace sandbox;

Window::Window(unsigned int x, unsigned int y, unsigned int width, unsigned int height, sandbox::SString name /*= "untitled"*/):
	m_width(width),
	m_height(height),
	m_x(x),
	m_y(y),
	m_name(name)
{

}

unsigned int Window::getWidth() const { return m_width; }
void Window::setWidth(unsigned int val) { m_width = val; }
unsigned int Window::getHeight() const { return m_height; }
void Window::setHeight(unsigned int val) { m_height = val; }
unsigned int Window::getX() const { return m_x; }
void Window::setX(unsigned int val) { m_x = val; }
unsigned int Window::getY() const { return m_y; }
void Window::setY(unsigned int val) { m_y = val; }
sandbox::SString Window::getName() const { return m_name; }
void Window::setName(sandbox::SString val) { m_name = val; }
