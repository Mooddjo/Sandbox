#include "StringUtils.h"

#include <fstream>
#include <iostream>
#include <string>

#include "SmartLogger.h"

using namespace sandbox;
using namespace std;

SString
StringUtils::parseFile(SString path)
{

	string line;
	string buffer;

	ifstream ifs(path.getCString());
	if (ifs.is_open())
	{
		while (getline(ifs, line))
		{
			line.append("\n");
			buffer.append(line);
		}
    }else {
        SMARTLOG("File not found", kInfo);
        //throw std::logic_error("File not found");
    }
	ifs.close();
	return SString(buffer.c_str());
}
