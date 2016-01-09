#pragma once

#include <mutex>

namespace smartray
{
	template<typename T> class Singleton
	{
	public:
		static T* getInstance();
	private:
		static T* s_instance;
		static std::mutex s_mutex;

	};

	template<typename T> T* Singleton<T>::s_instance = nullptr;
	template<typename T> std::mutex Singleton<T>::s_mutex;

	template<typename T>
	T* smartray::Singleton<T>::getInstance()
	{
		if (!s_instance)
		{
			s_mutex.lock();
			if (!s_instance)
			{
				s_instance = new T();
			}
			s_mutex.unlock();
		}

		return s_instance;
	}

}