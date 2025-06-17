#pragma once
#include <memory>
#include "Ideology.h"


class Character : public std::enable_shared_from_this<Character>
{
public:

	Ideology GetIdeology() const;
	Ideology& GetIdeology();
	void SetIdeology(const Ideology& ideology);


private:
	
	Ideology m_Ideology;

};


