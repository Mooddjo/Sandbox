#pragma once
#include "Timer.h"

namespace sandbox
{
	class AbstractRenderer
	{
	public:
		virtual bool init() = 0;
		virtual void process() = 0;

	protected:
		unsigned short m_fpsCounter;
		Timer m_timer;
	};
}