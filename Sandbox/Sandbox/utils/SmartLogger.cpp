#include "SmartLogger.h"

#include <iostream>

using namespace sandbox;
using namespace std;



void
HtmlLogWriter::write(SString message, LogLevel level) const
{
	throw std::logic_error("The method or operation is not implemented.");
}

void
ConsoleLogWriter::write(SString message, LogLevel level) const
{
	SString log = "";
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
	cout << log.getCString() << endl;
}


SString
ConsoleLogWriter::formatForWarning(SString message) const
{
	SString formatedMessage("WARNING: ");
	formatedMessage.append(message.getCString());
	formatedMessage.append("\0");

	return formatedMessage;
}

SString
ConsoleLogWriter::formatForError(SString message) const
{
	SString formatedMessage("ERROR: ");
	formatedMessage.append(message);
	formatedMessage.append("\0");

	return formatedMessage;
}

SString
ConsoleLogWriter::formatForInfo(SString message) const
{
	SString formatedMessage("INFO: ");
	formatedMessage.append(message);
	formatedMessage.append("\0");

	return formatedMessage;
}


SmartLogger::SmartLogger()
{
	m_logWriter = make_shared<ConsoleLogWriter>();
}

void
SmartLogger::write(SString message, LogLevel level)
{
	m_logWriter->write(message, level);
}