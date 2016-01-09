#include "StringUtils.h"

#include <fstream>
#include <iostream>

using namespace smartray;
using namespace std;

string
StringUtils::parseFile(std::string path)
{

	string line;
	string buffer;

	ifstream ifs(path);
	if (ifs.is_open())
	{
		while (getline(ifs, line))
		{
			line.append("\n");
			buffer.append(line);
		}
	}
	ifs.close();
	return buffer;
}
