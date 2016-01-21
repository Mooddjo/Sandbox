#include "FFeature.h"
#include "EEntity.h"

using namespace sandbox;



unsigned int FFeature::s_idCounter = 0;

FFeature::FFeature(EEntity* owner):
	m_id(s_idCounter),
	m_owner(owner),
	m_isEnable(true)
{
	s_idCounter++;
}
