#include "SmartLogger.h"

#include <iostream>

using namespace sandbox;
using namespace std;



void
HtmlLogWriter::write(std::string message, LogLevel level) const
{
	throw std::logic_error("The method or operation is not implemented.");
}

void
ConsoleLogWriter::write(std::string message, LogLevel level) const
{
	string log = "";
	switch (level)
	{
	case kWarning:
		log = formatForWarning(message);
		break;
	case kError:
		log = formatForError(message);
		break;
	case kInfo:
		log = formatForInfo(message);
		break;
	default:
		break;
	}
	cout << log << endl;
}


string
ConsoleLogWriter::formatForWarning(string message) const
{
	string formatedMessage("WARNING: ");
	formatedMessage.append(message);
	formatedMessage.append("\0");

	return formatedMessage;
}

string
ConsoleLogWriter::formatForError(string message) const
{
	string formatedMessage("ERROR: ");
	formatedMessage.append(message);
	formatedMessage.append("\0");

	return formatedMessage;
}

string
ConsoleLogWriter::formatForInfo(string message) const
{
	string formatedMessage("INFO: ");
	formatedMessage.append(message);
	formatedMessage.append("\0");

	return formatedMessage;
}


SmartLogger::SmartLogger()
{
	m_logWriter = make_shared<ConsoleLogWriter>();
}

void
SmartLogger::write(std::string message, LogLevel level)
{
	m_logWriter->write(message, level);
}