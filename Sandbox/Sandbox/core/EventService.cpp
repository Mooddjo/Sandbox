#include "EventService.h"

using namespace sandbox;

void 
EventService::fireEvent(std::string eventName, IEventData* data)
{
	auto it = m_subscribers.find(eventName);
	if (it != m_subscribers.end())
	{
		for (auto caller : it->second)
		{
			caller(data);
		}
	}
}

bool
EventService::subscribeToEvent(std::string eventName, EventCallback eventCallback)
{
	if (eventCallback)
	{
		auto it = m_subscribers.find(eventName);
		if (it == m_subscribers.end())
		{
			m_subscribers[eventName].push_back(eventCallback);
		}
		else
		{
			it->second.push_back(eventCallback);
		}

		return true;
	}

	return false;

}

bool
EventService::unsubscribeToEvent(std::string eventName, void* object)
{
	return false;
}
