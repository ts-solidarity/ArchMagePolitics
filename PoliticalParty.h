#pragma once
#include <memory>
#include <vector>
#include "Character.h"

class Voter;
class PoliticalParty;

typedef std::vector<std::shared_ptr<Voter>> VoterList;
typedef std::vector<std::shared_ptr<PoliticalParty>> PartyList;

class PoliticalParty : public Character
{
public:
	PoliticalParty();
	PoliticalParty(const std::shared_ptr<VoterList>& allVoters);
	PoliticalParty(const std::shared_ptr<VoterList>& allVoters, const std::shared_ptr<VoterList>& partyVoters);

	std::shared_ptr<PoliticalParty> GetThisParty();

	void SetAllVoters(const std::shared_ptr<VoterList>& allVoters);
	void SetPartyVoters(const std::shared_ptr<VoterList>& partyVoters);

	void MakePropaganda();
	void ScandalHappens();

	void AddVoter(std::shared_ptr<Voter> voter);
	void DeleteVoter(std::shared_ptr<Voter> voter);

	double CalculateVotePercentage() const;
	void Print() const;

private:
	std::shared_ptr<VoterList> m_PartyVoters = nullptr;
	std::shared_ptr<VoterList> m_AllVoters = nullptr;

};
