#include "Politics.h"

Politics::Politics()
{
	m_Voters = std::make_shared<VoterList>();
	m_Parties = std::make_shared<PartyList>();
}

Politics::Politics(const int& population, const int& partyCount)
{
	Init(population, partyCount);
}

void Politics::Init(const int& population, const int& partyCount)
{
	m_Voters = std::make_shared<VoterList>();
	m_Parties = std::make_shared<PartyList>();

	for (int i = 0; i < population; i++)
		CreateVoter();
	for (int i = 0; i < partyCount; i++)
		CreateParty();
}

std::shared_ptr<Voter> Politics::CreateVoter()
{
	std::shared_ptr<Voter> newVoter = std::make_shared<Voter>(m_Parties);
	m_Voters->push_back(newVoter);
	return newVoter;
}

std::shared_ptr<PoliticalParty> Politics::CreateParty()
{
	std::shared_ptr<PoliticalParty> newParty = std::make_shared<PoliticalParty>();
	std::shared_ptr<VoterList> partyVoters = std::make_shared<VoterList>();
	newParty->SetPartyVoters(partyVoters);
	newParty->SetAllVoters(m_Voters);
	m_Parties->push_back(newParty);
	UpdateAllVoters();
	return newParty;
}


void Politics::CreateVoters(const int& population)
{
	for (int i = 0; i < population; i++)
	{
		auto newVoter = CreateVoter();
		newVoter->Update();
	}
}

void Politics::CloseParty(const std::shared_ptr<PoliticalParty>& party)
{
	auto removedParty = std::find(m_Parties->begin(), m_Parties->end(), party);
	if (removedParty != m_Parties->end())
	{
		m_Parties->erase(removedParty);
	}
}

void Politics::PrintAllVoters() const
{
	for (const auto& voter : *m_Voters)
	{
		voter->Print();
	}
}

void Politics::PrintAllParties() const
{
	for (const auto& party : *m_Parties)
	{
		party->Print();
	}
}

void Politics::UpdateAllVoters()
{
	for (auto& voter : *m_Voters)
	{
		voter->Update();
	}
}
