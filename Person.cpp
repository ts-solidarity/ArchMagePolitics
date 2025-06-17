#include "Person.h"
#include "RNG.h"


Person::Person(const Ideology& ideology, const int& relationship)
	: m_Relationship(relationship)
{
	this->SetIdeology(ideology);
}

Person::Person()
{
	// Ideology is already determined randomly by default
	// Relationship is set to 0 by default
}


std::shared_ptr<Person> Person::GetThisPerson()
{
	return std::static_pointer_cast<Person>(shared_from_this());
}


int Person::GetRelationship() const
{
	return m_Relationship;
}

std::shared_ptr<PoliticalParty> Person::GetAffiliatedParty() const
{
	if (auto affiliatedParty = m_AffiliatedParty.lock())
		return affiliatedParty;
	return nullptr;
}

void Person::SetRelationship(const int& relationship)
{
	m_Relationship = relationship;
}

void Person::IncreaseRelationship(const int& increaseAmount)
{
	m_Relationship += increaseAmount;
}

void Person::DecreaseRelationship(const int& decreaseAmount)
{
	m_Relationship -= decreaseAmount;
}

void Person::IncreaseRelationship()
{
	int base = 10;
	int relationship = (m_Relationship > 0) ? m_Relationship : -m_Relationship;
	int max = base + relationship / 3;

	int increaseAmount = RNG::GetInstance().ProduceInteger(0, max);
	IncreaseRelationship(increaseAmount);
}

void Person::DecreaseRelationship()
{
	int base = 10;
	int relationship = (m_Relationship > 0) ? m_Relationship : -m_Relationship;
	int max = base + relationship / 3;

	int decreaseAmount = RNG::GetInstance().ProduceInteger(0, max);
	DecreaseRelationship(decreaseAmount);
}

void Person::SetAffiliatedParty(const std::shared_ptr<PoliticalParty>& affiliatedParty)
{
	m_AffiliatedParty = affiliatedParty;
}
