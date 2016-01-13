#include "SString.h"
#include <string>
#include <iostream>

using namespace sandbox;
using namespace std;

namespace sandbox
{



	struct SString::StringPImpl {
	public:
		StringPImpl(const char* str) : internalStringImpl(str) {

		}
		std::string internalStringImpl;
	};

	SString::~SString()
	{
		delete m_stringPImpl;
	}

	SString::SString(const char* str)
	{
		m_stringPImpl = new StringPImpl(str);
	}

	SString::SString(const SString& str)
	{
		m_stringPImpl = new StringPImpl(str.getCString());
	}

	const SString&
		SString::operator=(const SString& str)
	{
		m_stringPImpl->internalStringImpl = str.m_stringPImpl->internalStringImpl;
		return *this;
	}

	const char*
		SString::getCString() const
	{
		return m_stringPImpl->internalStringImpl.c_str();
	}

	unsigned int
		SString::length()
	{
		return m_stringPImpl->internalStringImpl.length();
	}

	bool
		operator<(const SString& str, const SString& str2)
	{
		return std::string(str.getCString()) < std::string(str2.getCString());
	}

	SString
		operator+(const SString& str, const SString& str2)
	{
		string s = std::string(str.getCString());
		string s2 = std::string(str2.getCString());

		SString sstr = SString((s + s2).c_str());

		return sstr;
	}

	void
		SString::append(const SString& str)
	{
		m_stringPImpl->internalStringImpl.append(str.m_stringPImpl->internalStringImpl);
	}

	void
		SString::copy(char* buffer, unsigned int length)
	{
		m_stringPImpl->internalStringImpl.copy(buffer, length);
	}

}