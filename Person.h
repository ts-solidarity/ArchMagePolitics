#pragma once
#include "Voter.h"
#include <memory>

class PoliticalParty;

class Person : public Voter
{
public:

	Person(const Ideology& ideology, const int& relationship);
	Person();

	std::shared_ptr<Person> GetThisPerson();


	int GetRelationship() const;
	std::shared_ptr<PoliticalParty> GetAffiliatedParty() const;

	void SetRelationship(const int& relationship);
	void IncreaseRelationship(const int& increaseAmount);
	void DecreaseRelationship(const int& decreaseAmount);
	void IncreaseRelationship();
	void DecreaseRelationship();

	void SetAffiliatedParty(const std::shared_ptr<PoliticalParty>& affiliatedParty);

private:
	int m_Relationship = 0;
	std::weak_ptr<PoliticalParty> m_AffiliatedParty;

};
