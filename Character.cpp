#include "Character.h"


Ideology Character::GetIdeology() const
{
	// Read only
	return m_Ideology;
}

Ideology& Character::GetIdeology()
{
	// Modifiable
	return m_Ideology;
}

void Character::SetIdeology(const Ideology& ideology)
{
	m_Ideology = ideology;
}

