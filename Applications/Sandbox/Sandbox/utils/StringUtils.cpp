#include "StringUtils.h"

#include <fstream>
#include <iostream>
#include <string>

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
	}
	ifs.close();
	return SString(buffer.c_str());
}
