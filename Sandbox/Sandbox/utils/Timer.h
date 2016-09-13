#pragma once

#include <chrono>

namespace sandbox
{
	class Timer
	{
	public:
		void start();
		void end();
		double eleapsed();

	private:
		std::chrono::time_point<std::chrono::system_clock> m_start;
		std::chrono::time_point<std::chrono::system_clock> m_end;
	};
}