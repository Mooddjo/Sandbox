#pragma once

#include <string>
#include "Platform.h"

#define DECLARE_FEATURE(className)\
public:\
static std::string name(){return #className;}\
virtual std::string getName(){return #className;}\
private:\

namespace sandbox
{
	class EEntity;
	class FRenderables;

	class DLL_SPEC FFeature
	{
		DECLARE_FEATURE(IFeature)

	public:
		FFeature(EEntity* owner);
		virtual void init() = 0;
		EEntity* getOwner() const { return m_owner; }
		bool isEnable() const { return m_isEnable; }
		void setEnable(bool val) { m_isEnable = val; }

	private:
		unsigned int m_id;
		EEntity* m_owner;
		bool m_isEnable;


		static unsigned int s_idCounter;
	};
}