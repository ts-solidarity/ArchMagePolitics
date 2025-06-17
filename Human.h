#pragma once
#include "Character.h"

class Human : public Character
{
public:
	Human();

	std::shared_ptr<Human> GetThisHuman();

	enum class Gender
	{
		Female = 0, Male
	};

	int GetId() const;
	int GetAge() const;
	Gender GetGender() const;

	void SetId(const int& id);
	void SetAge(const int& age);
	void SetGender(const Gender& gender);

public:
	static int globalId;


private:
	int m_Id;
	int m_Age;
	Gender m_Gender;

};
