#include <iostream>
#include "Ideology.h"
#include "RNG.h"

// 0 = Capitalist Free Market,       100 = Communist State Market
// 0 = Libertarian,                  100 = Totalitarian
// 0 = Progressive,                  100 = Nationalist
// 0 = Populist,                     100 = Elitist
// 0 = Theocratic,                   100 = Secularist
// 0 = Isolationist,                 100 = Globalist
// 0 = Pacifist,                     100 = Militarist

// 0 - 25               26 - 50             51 - 75             76 - 100
// Capitalist           Free Market         State Controlled    Communist
// Libertarian          Liberal             Authoritarian       Totalitarian
// Progressive          Moderate            Traditionalist      Nationalist
// Populist             Democratic          Technocratic        Elitist
// Theocratic           Religious           Secular             Anticlerical
// Isolationist         Non-Interventionist Open                Globalist
// Pacifist             Defensive           Armed               Militarist 

Ideology::Ideology()
{
	for (int i = 0; i < static_cast<int>(Axis::Count); i++)
	{
		m_Values[i] = RNG::GetInstance().ProduceInteger(0, 100);
	}
	
	UpdateAllStates();
}

Ideology::Ideology(const int& value)
{
	m_Values.fill(value);
	UpdateAllStates();
}

Ideology::Ideology(std::array<int, static_cast<int>(Axis::Count)> values)
{
	m_Values = values;
	UpdateAllStates();
}


void Ideology::Print() const
{
	std::cout << "Economy: " << GetEconomyLabel() << ", Value: " << GetEconomyValue() << std::endl;
	std::cout << "Authority: " << GetAuthorityLabel() << ", Value: " << GetAuthorityValue() << std::endl;
	std::cout << "Culture: " << GetCultureLabel() << ", Value: " << GetCultureValue() << std::endl;
	std::cout << "GovernmentForm: " << GetGovernmentFormLabel() << ", Value: " << GetGovernmentFormValue() << std::endl;
	std::cout << "Secularism: " << GetSecularismLabel() << ", Value: " << GetSecularismValue() << std::endl;
	std::cout << "Globalism: " << GetGlobalismLabel() << ", Value: " << GetGlobalismValue() << std::endl;
	std::cout << "Militarism: " << GetMilitarismLabel() << ", Value: " << GetMilitarismValue() << std::endl;
	std::cout << "***********************" << std::endl;
}


std::string Ideology::GetLabel(const Axis& axis) const
{
	const int value = GetValue(axis);

	switch (axis)
	{

	default:
	{
		return "Unknown";
	}

	case Axis::Economy:
	{
		if (value <= 25)
			return "Capitalist";
		else if (value <= 50)
			return "Free Market";
		else if (value <= 75)
			return "State Controlled";
		else
			return "Communist";
	}

	case Axis::Authority:
	{
		if (value <= 25)
			return "Libertarian";
		else if (value <= 50)
			return "Liberal";
		else if (value <= 75)
			return "Authoritarian";
		else
			return "Totalitarian";
	}

	case Axis::Culture:
	{
		if (value <= 25)
			return "Progressive";
		else if (value <= 50)
			return "Moderate";
		else if (value <= 75)
			return "Traditionalist";
		else
			return "Nationalist";
	}

	case Axis::GovernmentForm:
	{
		if (value <= 25)
			return "Populist";
		else if (value <= 50)
			return "Democratic";
		else if (value <= 75)
			return "Technocratic";
		else
			return "Elitist";
	}

	case Axis::Secularism:
	{
		if (value <= 25)
			return "Theocratic";
		else if (value <= 50)
			return "Religious";
		else if (value <= 75)
			return "Secular";
		else
			return "Anticlerical";
	}

	case Axis::Globalism:
	{
		if (value <= 25)
			return "Isolationist";
		else if (value <= 50)
			return "Non-Interventionist";
		else if (value <= 75)
			return "Open";
		else
			return "Globalist";
	}

	case Axis::Militarism:
	{
		if (value <= 25)
			return "Pacifist";
		else if (value <= 50)
			return "Defensive";
		else if (value <= 75)
			return "Armed";
		else
			return "Militarist";
	}

	}
}

int Ideology::GetValue(const Axis& axis) const
{
	return m_Values.at(static_cast<int>(axis));
}

void Ideology::SetValue(const Axis& axis, const int& value)
{
	m_Values[(static_cast<int>(axis))] = value;
}

void Ideology::SetValues(const std::array<int, static_cast<int>(Axis::Count)> values)
{
	m_Values = values;
	UpdateAllStates();
}


int Ideology::GetEconomyValue() const
{
	return GetValue(Axis::Economy);
}

int Ideology::GetAuthorityValue() const
{
	return GetValue(Axis::Authority);

}

int Ideology::GetCultureValue() const
{
	return GetValue(Axis::Culture);

}

int Ideology::GetGovernmentFormValue() const
{
	return GetValue(Axis::GovernmentForm);

}

int Ideology::GetSecularismValue() const
{
	return GetValue(Axis::Secularism);

}

int Ideology::GetGlobalismValue() const
{
	return GetValue(Axis::Globalism);

}

int Ideology::GetMilitarismValue() const
{
	return GetValue(Axis::Militarism);
}

Ideology::Economy Ideology::GetEconomyState() const
{
	return m_Economy;
}

Ideology::Authority Ideology::GetAuthorityState() const
{
	return m_Authority;
}

Ideology::Culture Ideology::GetCultureState() const
{
	return m_Culture;
}

Ideology::GovernmentForm Ideology::GetGovernmentFormState() const
{
	return m_GovernmentForm;
}

Ideology::Secularism Ideology::GetSecularismState() const
{
	return m_Secularism;
}

Ideology::Globalism Ideology::GetGlobalismState() const
{
	return m_Globalism;
}

Ideology::Militarism Ideology::GetMilitarismState() const
{
	return m_Militarism;
}

void Ideology::SetEconomyState(const Economy& state)
{
	m_Economy = state;
	SetEconomyValue(static_cast<int>(state));
}

void Ideology::SetAuthorityState(const Authority& state)
{
	m_Authority = state;
	SetAuthorityValue(static_cast<int>(state));
}

void Ideology::SetCultureState(const Culture& state)
{
	m_Culture = state;
	SetCultureValue(static_cast<int>(state));
}

void Ideology::SetGovernmentFormState(const GovernmentForm& state)
{
	m_GovernmentForm = state;
	SetGovernmentFormValue(static_cast<int>(state));
}

void Ideology::SetSecularismState(const Secularism& state)
{
	m_Secularism = state;
	SetSecularismValue(static_cast<int>(state));
}

void Ideology::SetGlobalismState(const Globalism& state)
{
	m_Globalism = state;
	SetGlobalismValue(static_cast<int>(state));
}

void Ideology::SetMilitarismState(const Militarism& state)
{
	m_Militarism = state;
	SetMilitarismValue(static_cast<int>(state));
}

void Ideology::SetEconomyStateFromValue(const int& value)
{
	SetEconomyValue(value);
	UpdateEconomyState();
}

void Ideology::SetAuthorityStateFromValue(const int& value)
{
	SetAuthorityValue(value);
	UpdateAuthorityState();
}

void Ideology::SetCultureStateFromValue(const int& value)
{
	SetCultureValue(value);
	UpdateCultureState();
}

void Ideology::SetGovernmentFormStateFromValue(const int& value)
{
	SetGovernmentFormValue(value);
	UpdateGovernmentFormState();
}

void Ideology::SetSecularismStateFromValue(const int& value)
{
	SetSecularismValue(value);
	UpdateSecularismState();
}

void Ideology::SetGlobalismStateFromValue(const int& value)
{
	SetGlobalismValue(value);
	UpdateGlobalismState();
}

void Ideology::SetMilitarismStateFromValue(const int& value)
{
	SetMilitarismValue(value);
	UpdateMilitarismState();
}


void Ideology::SetEconomyValue(const int& value)
{
	SetValue(Axis::Economy, value);
}

void Ideology::SetAuthorityValue(const int& value)
{
	SetValue(Axis::Authority, value);

}

void Ideology::SetCultureValue(const int& value)
{
	SetValue(Axis::Culture, value);

}

void Ideology::SetGovernmentFormValue(const int& value)
{
	SetValue(Axis::GovernmentForm, value);
}

void Ideology::SetSecularismValue(const int& value)
{
	SetValue(Axis::Secularism, value);
}

void Ideology::SetGlobalismValue(const int& value)
{
	SetValue(Axis::Globalism, value);
}

void Ideology::SetMilitarismValue(const int& value)
{
	SetValue(Axis::Militarism, value);
}


void Ideology::UpdateAllStates()
{
	UpdateEconomyState();
	UpdateAuthorityState();
	UpdateCultureState();
	UpdateGovernmentFormState();
	UpdateSecularismState();
	UpdateGlobalismState();
	UpdateMilitarismState();
}


void Ideology::UpdateEconomyState()
{
	m_Economy = AssessEconomy();
}

void Ideology::UpdateAuthorityState()
{
	m_Authority = AssessAuthority();
}

void Ideology::UpdateCultureState()
{
	m_Culture = AssessCulture();
}

void Ideology::UpdateGovernmentFormState()
{
	m_GovernmentForm = AssessGovernmentForm();
}

void Ideology::UpdateSecularismState()
{
	m_Secularism = AssessSecularism();
}

void Ideology::UpdateGlobalismState()
{
	m_Globalism = AssessGlobalism();
}

void Ideology::UpdateMilitarismState()
{
	m_Militarism = AssessMilitarism();
}


bool Ideology::IsCapitalist() const
{
	return m_Economy == Economy::Capitalist;
}

bool Ideology::IsFreeMarket() const
{
	return m_Economy == Economy::FreeMarket;
}

bool Ideology::IsStateControlled() const
{
	return m_Economy == Economy::StateControlled;
}

bool Ideology::IsCommunist() const
{
	return m_Economy == Economy::Communist;
}


bool Ideology::IsLibertarian() const
{
	return m_Authority == Authority::Libertarian;
}

bool Ideology::IsLiberal() const
{
	return m_Authority == Authority::Liberal;
}

bool Ideology::IsAuthoritarian() const
{
	return m_Authority == Authority::Authoritarian;
}

bool Ideology::IsTotalitarian() const
{
	return m_Authority == Authority::Totalitarian;
}


bool Ideology::IsProgressive() const
{
	return m_Culture == Culture::Progressive;
}

bool Ideology::IsModerate() const
{
	return m_Culture == Culture::Moderate;
}

bool Ideology::IsTraditionalist() const
{
	return m_Culture == Culture::Traditionalist;
}

bool Ideology::IsNationalist() const
{
	return m_Culture == Culture::Nationalist;
}


bool Ideology::IsPopulist() const
{
	return m_GovernmentForm == GovernmentForm::Populist;
}

bool Ideology::IsDemocratic() const
{
	return m_GovernmentForm == GovernmentForm::Democratic;
}

bool Ideology::IsTechnocratic() const
{
	return m_GovernmentForm == GovernmentForm::Technocratic;
}

bool Ideology::IsElitist() const
{
	return m_GovernmentForm == GovernmentForm::Elitist;
}


bool Ideology::IsTheocratic() const
{
	return m_Secularism == Secularism::Theocratic;
}

bool Ideology::IsReligious() const
{
	return m_Secularism == Secularism::Religious;
}

bool Ideology::IsSecular() const
{
	return m_Secularism == Secularism::Secular;
}

bool Ideology::IsAnticlerical() const
{
	return m_Secularism == Secularism::Anticlerical;
}


bool Ideology::IsIsolationist() const
{
	return m_Globalism == Globalism::Isolationist;
}

bool Ideology::IsNonInterventionist() const
{
	return m_Globalism == Globalism::NonInterventionist;
}

bool Ideology::IsOpen() const
{
	return m_Globalism == Globalism::Open;
}

bool Ideology::IsGlobalist() const
{
	return m_Globalism == Globalism::Globalist;
}


bool Ideology::IsPacifist() const
{
	return m_Militarism == Militarism::Pacifist;
}

bool Ideology::IsDefensive() const
{
	return m_Militarism == Militarism::Defensive;
}

bool Ideology::IsArmed() const
{
	return m_Militarism == Militarism::Armed;
}

bool Ideology::IsMilitarist() const
{
	return m_Militarism == Militarism::Militarist;
}



void Ideology::ShiftTowards(const Economy& idea)
{
	int currentValue = GetEconomyValue();
	int targetValue = static_cast<int>(idea);
	int newValue = (currentValue + targetValue) / 2;
	SetEconomyValue(newValue);
	UpdateEconomyState();
}

void Ideology::ShiftTowards(const Authority& idea)
{
	int currentValue = GetAuthorityValue();
	int targetValue = static_cast<int>(idea);
	int newValue = (currentValue + targetValue) / 2;
	SetAuthorityValue(newValue);
	UpdateAuthorityState();
}

void Ideology::ShiftTowards(const Culture& idea)
{
	int currentValue = GetCultureValue();
	int targetValue = static_cast<int>(idea);
	int newValue = (currentValue + targetValue) / 2;
	SetCultureValue(newValue);
	UpdateCultureState();
}

void Ideology::ShiftTowards(const GovernmentForm& idea)
{
	int currentValue = GetGovernmentFormValue();
	int targetValue = static_cast<int>(idea);
	int newValue = (currentValue + targetValue) / 2;
	SetGovernmentFormValue(newValue);
	UpdateGovernmentFormState();
}

void Ideology::ShiftTowards(const Secularism& idea)
{
	int currentValue = GetSecularismValue();
	int targetValue = static_cast<int>(idea);
	int newValue = (currentValue + targetValue) / 2;
	SetSecularismValue(newValue);
	UpdateSecularismState();
}

void Ideology::ShiftTowards(const Globalism& idea)
{
	int currentValue = GetGlobalismValue();
	int targetValue = static_cast<int>(idea);
	int newValue = (currentValue + targetValue) / 2;
	SetGlobalismValue(newValue);
	UpdateGlobalismState();
}

void Ideology::ShiftTowards(const Militarism& idea)
{
	int currentValue = GetMilitarismValue();
	int targetValue = static_cast<int>(idea);
	int newValue = (currentValue + targetValue) / 2;
	SetMilitarismValue(newValue);
	UpdateMilitarismState();
}


void Ideology::ShiftTowardsIdeology(const Ideology& other)
{
	ShiftTowards(other.GetEconomyState());
	ShiftTowards(other.GetAuthorityState());
	ShiftTowards(other.GetCultureState());
	ShiftTowards(other.GetGovernmentFormState());
	ShiftTowards(other.GetSecularismState());
	ShiftTowards(other.GetGlobalismState());
	ShiftTowards(other.GetMilitarismState());
}



void Ideology::RepelFrom(const Economy& idea)
{
	int currentValue = GetEconomyValue();
	int targetValue = static_cast<int>(idea);
	int antiTargetValue = 100 - targetValue;
	int newValue = (currentValue + antiTargetValue) / 2;

	SetEconomyValue(newValue);
	UpdateEconomyState();
}

void Ideology::RepelFrom(const Authority& idea)
{
	int currentValue = GetAuthorityValue();
	int targetValue = static_cast<int>(idea);
	int antiTargetValue = 100 - targetValue;
	int newValue = (currentValue + antiTargetValue) / 2;

	SetAuthorityValue(newValue);
	UpdateAuthorityState();
}

void Ideology::RepelFrom(const Culture& idea)
{
	int currentValue = GetCultureValue();
	int targetValue = static_cast<int>(idea);
	int antiTargetValue = 100 - targetValue;
	int newValue = (currentValue + antiTargetValue) / 2;

	SetCultureValue(newValue);
	UpdateCultureState();
}

void Ideology::RepelFrom(const GovernmentForm& idea)
{
	int currentValue = GetGovernmentFormValue();
	int targetValue = static_cast<int>(idea);
	int antiTargetValue = 100 - targetValue;
	int newValue = (currentValue + antiTargetValue) / 2;

	SetGovernmentFormValue(newValue);
	UpdateGovernmentFormState();
}

void Ideology::RepelFrom(const Secularism& idea)
{
	int currentValue = GetSecularismValue();
	int targetValue = static_cast<int>(idea);
	int antiTargetValue = 100 - targetValue;
	int newValue = (currentValue + antiTargetValue) / 2;

	SetSecularismValue(newValue);
	UpdateSecularismState();
}

void Ideology::RepelFrom(const Globalism& idea)
{
	int currentValue = GetGlobalismValue();
	int targetValue = static_cast<int>(idea);
	int antiTargetValue = 100 - targetValue;
	int newValue = (currentValue + antiTargetValue) / 2;

	SetGlobalismValue(newValue);
	UpdateGlobalismState();
}

void Ideology::RepelFrom(const Militarism& idea)
{
	int currentValue = GetMilitarismValue();
	int targetValue = static_cast<int>(idea);
	int antiTargetValue = 100 - targetValue;
	int newValue = (currentValue + antiTargetValue) / 2;

	SetMilitarismValue(newValue);
	UpdateMilitarismState();
}


void Ideology::RepelFromIdeology(const Ideology& other)
{
	RepelFrom(other.GetEconomyState());
	RepelFrom(other.GetAuthorityState());
	RepelFrom(other.GetCultureState());
	RepelFrom(other.GetGovernmentFormState());
	RepelFrom(other.GetSecularismState());
	RepelFrom(other.GetGlobalismState());
	RepelFrom(other.GetMilitarismState());
}

int Ideology::CalculateIdeologicalDifference(const Ideology& other) const
{
	int totalDifference = 0;

	int economyDifference = GetEconomyValue() - other.GetEconomyValue();
	int authorityDifference = GetAuthorityValue() - other.GetAuthorityValue();
	int cultureDifference = GetCultureValue() - other.GetCultureValue();
	int governmentFormDifference = GetGovernmentFormValue() - other.GetGovernmentFormValue();
	int secularismDifference = GetSecularismValue() - other.GetSecularismValue();
	int globalismDifference = GetGlobalismValue() - other.GetGlobalismValue();
	int militarismDifference = GetMilitarismValue() - other.GetMilitarismValue();

	std::array<int, 7> values{economyDifference, authorityDifference, cultureDifference, governmentFormDifference, secularismDifference, globalismDifference, militarismDifference};

	for (int i = 0; i < 7; i++)
	{
		totalDifference += std::abs(values.at(i));
	}

	return totalDifference;
}



Ideology::Economy Ideology::AssessEconomy() const
{
	const int value = GetEconomyValue();

	if (value <= 25)
		return Economy::Capitalist;
	else if (value <= 50)
		return Economy::FreeMarket;
	else if (value <= 75)
		return Economy::StateControlled;
	else
		return Economy::Communist;
}

Ideology::Authority Ideology::AssessAuthority() const
{
	const int value = GetAuthorityValue();

	if (value <= 25)
		return Authority::Libertarian;
	else if (value <= 50)
		return Authority::Liberal;
	else if (value <= 75)
		return Authority::Authoritarian;
	else
		return Authority::Totalitarian;
}

Ideology::Culture Ideology::AssessCulture() const
{
	const int value = GetCultureValue();

	if (value <= 25)
		return Culture::Progressive;
	else if (value <= 50)
		return Culture::Moderate;
	else if (value <= 75)
		return Culture::Traditionalist;
	else
		return Culture::Nationalist;
}

Ideology::GovernmentForm Ideology::AssessGovernmentForm() const
{
	const int value = GetGovernmentFormValue();

	if (value <= 25)
		return GovernmentForm::Populist;
	else if (value <= 50)
		return GovernmentForm::Democratic;
	else if (value <= 75)
		return GovernmentForm::Technocratic;
	else
		return GovernmentForm::Elitist;
}

Ideology::Secularism Ideology::AssessSecularism() const
{
	const int value = GetSecularismValue();

	if (value <= 25)
		return Secularism::Theocratic;
	else if (value <= 50)
		return Secularism::Religious;
	else if (value <= 75)
		return Secularism::Secular;
	else
		return Secularism::Anticlerical;
}

Ideology::Globalism Ideology::AssessGlobalism() const
{
	const int value = GetGlobalismValue();

	if (value <= 25)
		return Globalism::Isolationist;
	else if (value <= 50)
		return Globalism::NonInterventionist;
	else if (value <= 75)
		return Globalism::Open;
	else
		return Globalism::Globalist;
}

Ideology::Militarism Ideology::AssessMilitarism() const
{
	const int value = GetMilitarismValue();

	if (value <= 25)
		return Militarism::Pacifist;
	else if (value <= 50)
		return Militarism::Defensive;
	else if (value <= 75)
		return Militarism::Armed;
	else
		return Militarism::Militarist;
}



std::string Ideology::GetEconomyLabel() const
{
	return GetLabel(Axis::Economy);
}

std::string Ideology::GetAuthorityLabel() const
{
	return GetLabel(Axis::Authority);
}

std::string Ideology::GetCultureLabel() const
{
	return GetLabel(Axis::Culture);
}

std::string Ideology::GetGovernmentFormLabel() const
{
	return GetLabel(Axis::GovernmentForm);
}

std::string Ideology::GetSecularismLabel() const
{
	return GetLabel(Axis::Secularism);
}

std::string Ideology::GetGlobalismLabel() const
{
	return GetLabel(Axis::Globalism);
}

std::string Ideology::GetMilitarismLabel() const
{
	return GetLabel(Axis::Militarism);
}
