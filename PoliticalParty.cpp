#include <iostream>
#include "PoliticalParty.h"
#include "Voter.h"


PoliticalParty::PoliticalParty()
{
}

PoliticalParty::PoliticalParty(const std::shared_ptr<VoterList>& allVoters)
	: m_AllVoters(allVoters)
{
}

PoliticalParty::PoliticalParty(const std::shared_ptr<VoterList>& allVoters, const std::shared_ptr<VoterList>& partyVoters)
	: m_AllVoters(allVoters), m_PartyVoters(partyVoters)
{
}


std::shared_ptr<PoliticalParty> PoliticalParty::GetThisParty()
{
	return std::static_pointer_cast<PoliticalParty>(shared_from_this());
}

void PoliticalParty::SetAllVoters(const std::shared_ptr<VoterList>& allVoters)
{
	m_AllVoters = allVoters;
}

void PoliticalParty::SetPartyVoters(const std::shared_ptr<VoterList>& partyVoters)
{
	m_PartyVoters = partyVoters;
}


double PoliticalParty::CalculateVotePercentage() const
{
	double votePercentage = (double)m_PartyVoters->size() / (double)m_AllVoters->size();
	return votePercentage * 100;
}

void PoliticalParty::Print() const
{
	std::cout << "Party Ideology: " << std::endl;
	this->GetIdeology().Print();
	std::cout << "Party supporters: " << m_PartyVoters->size() << std::endl;
	std::cout << "Vote percentage: %" << CalculateVotePercentage() << std::endl;
	std::cout << "***********************" << std::endl;
}


void PoliticalParty::MakePropaganda()
{
	for (auto& voter : *m_AllVoters)
	{
		voter->GetIdeology().ShiftTowardsIdeology(this->GetIdeology());
	}
}

void PoliticalParty::ScandalHappens()
{
	for (auto& voter : *m_AllVoters)
	{
		voter->GetIdeology().RepelFromIdeology(this->GetIdeology());
	}
}

void PoliticalParty::AddVoter(std::shared_ptr<Voter> voter)
{
	m_PartyVoters->push_back(voter);
}

void PoliticalParty::DeleteVoter(std::shared_ptr<Voter> voter)
{
	auto removedVoter = std::find(m_PartyVoters->begin(), m_PartyVoters->end(), voter);
	if (removedVoter != m_PartyVoters->end())
	{
		m_PartyVoters->erase(removedVoter);
	}
}



