#include "SString.h"
#include <iostream>

using namespace sandbox;
using namespace std;

struct SString::StringPImpl {
	StringPImpl(const char* str) : internalStringImpl(str){

	}
	std::string internalStringImpl;
};

SString::SString(const char* str)
{
	m_stringPImpl = new StringPImpl(str);
}

const char* 
SString::getCString()
{
	return m_stringPImpl->internalStringImpl.c_str();
}
