#include "Timer.h"

#include <ctime>

using namespace sandbox;

void
Timer::start()
{
	m_start = std::chrono::system_clock::now();
	
}

void
Timer::end()
{
	m_end = std::chrono::system_clock::now();
}

double
Timer::eleapsed()
{
	end();
	int elapsedNs = (int)std::chrono::duration_cast<std::chrono::nanoseconds>(m_end - m_start).count();

	double elapsedMs = elapsedNs / 1000000.0;

	return elapsedMs;
}
