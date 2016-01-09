#pragma once

#include "Singleton.h"
#include <iostream>
#include <memory>
#include <string>

#define SMARTLOG(message, level) smartray::SmartLogger::getInstance()->write(message, level)

namespace smartray
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
		virtual void write(std::string message, LogLevel level = kInfo)const  = 0;
	};

	class ConsoleLogWriter : public ILogWriter
	{
	public:
		virtual void write(std::string message, LogLevel level) const override;
	private:
		std::string formatForWarning(std::string message) const;
		std::string formatForError(std::string message) const;
		std::string formatForInfo(std::string message) const;
	};
	class HtmlLogWriter : public ILogWriter
	{
	public:
		virtual void write(std::string message, LogLevel level) const override;
	};


	class SmartLogger : public Singleton<SmartLogger>
	{
		friend class Singleton<SmartLogger>;

	public:
		void write(std::string message, LogLevel level);

	private:
		SmartLogger();
		SmartLogger(const SmartLogger&) = delete;
		SmartLogger& operator= (SmartLogger) = delete;

		std::shared_ptr<ILogWriter> m_logWriter;
	};
}