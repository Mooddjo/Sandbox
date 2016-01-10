#pragma once

#include "Platform.h"
#include "Singleton.h"
#include <map>
#include <list>

#include <SmartLogger.h>

#define EVENT_CALLBACK(function, object) std::bind(function, object, std::placeholders::_1)
#define REGISTER_FOR_EVENT(name, eventCallback) EventService::getInstance()->subscribeToEvent(name, eventCallback)

namespace sandbox
{

	class DLL_SPEC IEventData
	{

	};

	using EventCallback = std::function<void(IEventData*)>;

	class DLL_SPEC EventService : public Singleton<EventService>
	{
		friend class Singleton<EventService>;
	public:
		bool subscribeToEvent(std::string eventName, EventCallback eventCallback);
		bool unsubscribeToEvent(std::string eventName, void* object);
		void fireEvent(std::string name, IEventData* data);

	protected:
		EventService() {}

	private:

		std::map<std::string, std::list<EventCallback>> m_subscribers;
	};

	template<typename T>
	class DLL_SPEC EvFeatureCreated: public IEventData
	{
	public:
		EvFeatureCreated(T* feature):m_feature(feature){}
		T* getFeature() { return m_feature; }
	private:
		T* m_feature;
	};

	class DLL_SPEC EvStringMessage : public IEventData
	{
	public:
		EvStringMessage(std::string message):m_message(message){}
		std::string getMessage() { return m_message; }
	private:
		std::string m_message;
	};
}	