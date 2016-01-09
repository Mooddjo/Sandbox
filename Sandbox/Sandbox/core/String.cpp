#include "String.h"
#include <iostream>

using namespace sandbox;
using namespace std;

struct String::StringPImpl {
	std::string internalStringImpl;
};

String::String(const char* str)
{
	m_stringPImpl = new StringPImpl();
	//m_stringPImpl->internalStringImpl = str;
}

const char* 
String::getCString()
{
	//return m_stringPImpl->internalStringImpl.c_str();
	return nullptr;
}
