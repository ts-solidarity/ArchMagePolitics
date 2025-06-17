#pragma once

#include <vector>
#include "PoliticalParty.h"
#include "Voter.h"


class Politics
{
public:
	Politics();
	Politics(const int& population, const int& partyCount);

	void Init(const int& population, const int& partyCount);

	std::shared_ptr<Voter> CreateVoter();
	std::shared_ptr<PoliticalParty> CreateParty();

	void CreateVoters(const int& population);

	void CloseParty(const std::shared_ptr<PoliticalParty>& party);

	void PrintAllVoters() const;
	void PrintAllParties() const;

	void UpdateAllVoters();


private:
	std::shared_ptr<PartyList> m_Parties{};
	std::shared_ptr<VoterList> m_Voters{};

};

