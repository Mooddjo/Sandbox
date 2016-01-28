#pragma once

#include "Singleton.h"
#include <iostream>
#include <memory>
#include "SString.h"

#define SMARTLOG(message, level) sandbox::SmartLogger::getInstance()->write(message, level)

namespace sandbox
{
	enum
	{
		kWarning,
		kError,
		kInfo
	}typedef LogLevel;

	

	class ILogWriter
	{
	public:
		virtual void write(SString message, LogLevel level = kInfo)const  = 0;
	};

	class DLL_SPEC ConsoleLogWriter : public ILogWriter
	{
	public:
		virtual void write(SString message, LogLevel level) const override;
	private:
		SString formatForWarning(SString message) const;
		SString formatForError(SString message) const;
		SString formatForInfo(SString message) const;
	};
	class HtmlLogWriter : public ILogWriter
	{
	public:
		virtual void write(SString message, LogLevel level) const override;
	};


	class DLL_SPEC SmartLogger : public Singleton<SmartLogger>
	{
		friend class Singleton<SmartLogger>;

	public:
		void write(SString message, LogLevel level);

	private:
		SmartLogger();
		SmartLogger(const SmartLogger&) = delete;
		SmartLogger& operator= (SmartLogger) = delete;

		std::shared_ptr<ILogWriter> m_logWriter;
	};
}