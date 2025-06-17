#pragma once
#include "Human.h"
#include <memory>
#include <vector>


class PoliticalParty;
typedef std::vector<std::shared_ptr<PoliticalParty>> PartyList;


class Voter : public Human
{

public:
	Voter();
	Voter(const std::shared_ptr<PartyList>& allParties);

	std::shared_ptr<Voter> GetThisVoter();
	std::shared_ptr<PoliticalParty> GetVotingParty() const;
	std::shared_ptr<PartyList> GetAllParties() const;
	
	void SetAllParties(std::shared_ptr<PartyList> allParties);
	void SetVotingParty(std::shared_ptr<PoliticalParty> newVotingParty);

	void Update();

	void Print() const;

private:
	std::shared_ptr<PoliticalParty> FindIdeologicallyClosestParty() const;
	void UpdateVotingParty();

private:
	std::weak_ptr<PoliticalParty> m_VotingParty;
	std::weak_ptr<PartyList> m_AllParties;

};

