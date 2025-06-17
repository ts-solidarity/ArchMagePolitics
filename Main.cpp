#include <iostream>
#include "Politics.h"

int main()
{
	Politics* politics = new Politics();

	auto party1 = politics->CreateParty();
	auto party2 = politics->CreateParty();
	politics->CreateVoters(1000);
	politics->PrintAllParties();

	

	delete politics;
}
