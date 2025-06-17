#include "PoliticalParty.h"
#include "Voter.h"
#include <iostream>

Voter::Voter()
{
}

Voter::Voter(const std::shared_ptr<PartyList>& allParties)
	: m_AllParties(allParties)
{
}

std::shared_ptr<Voter> Voter::GetThisVoter()
{
	return std::static_pointer_cast<Voter>(shared_from_this());
}

std::shared_ptr<PoliticalParty> Voter::GetVotingParty() const
{
	if (auto votingParty = m_VotingParty.lock())
		return votingParty;
	return nullptr;
}

std::shared_ptr<PartyList> Voter::GetAllParties() const
{
	if (auto allParties = m_AllParties.lock())
		return allParties;
	return nullptr;
}

void Voter::SetAllParties(std::shared_ptr<PartyList> allParties)
{
	m_AllParties = allParties;
}

void Voter::SetVotingParty(std::shared_ptr<PoliticalParty> newVotingParty)
{
	if (!newVotingParty)
		return;

	std::shared_ptr<PoliticalParty> oldVotingParty = GetVotingParty();

	if (!oldVotingParty)
	{
		m_VotingParty = newVotingParty;
		newVotingParty->AddVoter(GetThisVoter());
		return;
	}

	if (oldVotingParty == newVotingParty)
		return;
	
	m_VotingParty = newVotingParty;
	oldVotingParty->DeleteVoter(GetThisVoter());
	newVotingParty->AddVoter(GetThisVoter());
}


void Voter::Update()
{
	UpdateVotingParty();
}



void Voter::Print() const
{
	std::string gender = (GetGender() == Human::Gender::Male) ? "Male" : "Female";

	std::cout << "ID: " << GetId() << std::endl;
	std::cout << "Voter Ideology: " << std::endl;
	GetIdeology().Print();
	std::cout << "Age: " << GetAge() << std::endl;
	std::cout << "Gender: " << gender << std::endl;
	std::cout << "***********************" << std::endl;

}

void Voter::UpdateVotingParty()
{
	SetVotingParty(FindIdeologicallyClosestParty());
}

std::shared_ptr<PoliticalParty> Voter::FindIdeologicallyClosestParty() const
{
	const auto& allParties = *GetAllParties();

	if (allParties.size() == 0)
		return nullptr;

	std::vector<int> ideologicalDifferences;
	ideologicalDifferences.reserve(allParties.size());

	std::shared_ptr<PoliticalParty> selectedParty = nullptr;

	for (const auto& party : allParties)
	{
		ideologicalDifferences.push_back(GetIdeology().CalculateIdeologicalDifference(party->GetIdeology()));
	}

	int difference = ideologicalDifferences.at(0);

	for (int i = 0; i < ideologicalDifferences.size(); i++)
	{
		int currentDifference = ideologicalDifferences.at(i);

		if (currentDifference <= difference)
		{
			selectedParty = allParties.at(i);
			difference = currentDifference;
		}
	}
	
	return selectedParty;
}
