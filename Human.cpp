#include "Human.h"
#include "RNG.h"

int Human::globalId = 0;

Human::Human()
{
	m_Id = ++Human::globalId;
	m_Age = RNG::GetInstance().ProduceInteger(18, 85);
	m_Gender = static_cast<Gender>(RNG::GetInstance().ProduceInteger(0, 1));
}


std::shared_ptr<Human> Human::GetThisHuman()
{
	return std::static_pointer_cast<Human>(shared_from_this());
}


int Human::GetId() const
{
	return m_Id;
}

int Human::GetAge() const
{
	return m_Age;
}

Human::Gender Human::GetGender() const
{
	return m_Gender;
}


void Human::SetId(const int& id)
{
	m_Id = id;
}

void Human::SetAge(const int& age)
{
	m_Age = age;
}

void Human::SetGender(const Gender& gender)
{
	m_Gender = gender;
}
