#pragma once
#include <array>
#include <string>


class Ideology
{

    // 0 = Capitalist Free Market,                      100 = Communist State Market
    // 0 = Libertarian,                                 100 = Totalitarian
    // 0 = Progressive,                                 100 = Nationalist
    // 0 = Populist,                                    100 = Elitist
    // 0 = Theocratic,                                  100 = Secularist
    // 0 = Isolationist,                                100 = Globalist
    // 0 = Pacifist,                                    100 = Militarist

    // 0 - 25               26 - 50             51 - 75             76 - 100
    // Capitalist           Free Market         State Controlled    Communist       : Economy
    // Libertarian          Liberal             Authoritarian       Totalitarian    : Authority
    // Progressive          Moderate            Traditionalist      Nationalist     : Culture
    // Populist             Democratic          Technocratic        Elitist         : GovernmentForm
    // Theocratic           Religious           Secular             Anticlerical    : Secularism
    // Isolationist         Non-Interventionist Open                Globalist       : Globalism
    // Pacifist             Defensive           Armed               Militarist      : Militarism

public:

    enum class Axis
    {
        Economy = 0, Authority, Culture, GovernmentForm, Secularism, Globalism, Militarism, Count
    };


    enum class Economy
    {
        Capitalist = 12, FreeMarket = 37, StateControlled = 62, Communist = 87
    };

    enum class Authority
    {
        Libertarian = 12, Liberal = 37, Authoritarian = 62, Totalitarian = 87
    };

    enum class Culture
    {
        Progressive = 12, Moderate = 37, Traditionalist = 62, Nationalist = 87
    };

    enum class GovernmentForm
    {
        Populist = 12, Democratic = 37, Technocratic = 62, Elitist = 87
    };

    enum class Secularism
    {
        Theocratic = 12, Religious = 37, Secular = 62, Anticlerical = 87
    };

    enum class Globalism
    {
        Isolationist = 12, NonInterventionist = 37, Open = 62, Globalist = 87
    };

    enum class Militarism
    {
        Pacifist = 12, Defensive = 37, Armed = 62, Militarist = 87
    };


public:

    Ideology();
    Ideology(const int& value);
    Ideology(std::array<int, static_cast<int>(Axis::Count)> values);

    void Print() const;

    std::string GetLabel(const Axis& axis) const;
    int GetValue(const Axis& axis) const;

    void SetValue(const Axis& axis, const int& value);
    void SetValues(const std::array<int, static_cast<int>(Axis::Count)> values);

    int GetEconomyValue() const;
    int GetAuthorityValue() const;
    int GetCultureValue() const;
    int GetGovernmentFormValue() const;
    int GetSecularismValue() const;
    int GetGlobalismValue() const;
    int GetMilitarismValue() const;

    std::string GetEconomyLabel() const;
    std::string GetAuthorityLabel() const;
    std::string GetCultureLabel() const;
    std::string GetGovernmentFormLabel() const;
    std::string GetSecularismLabel() const;
    std::string GetGlobalismLabel() const;
    std::string GetMilitarismLabel() const;

    Economy GetEconomyState() const;
    Authority GetAuthorityState() const;
    Culture GetCultureState() const;
    GovernmentForm GetGovernmentFormState() const;
    Secularism GetSecularismState() const;
    Globalism GetGlobalismState() const;
    Militarism GetMilitarismState() const;

    void SetEconomyState(const Economy& state);
    void SetAuthorityState(const Authority& state);
    void SetCultureState(const Culture& state);
    void SetGovernmentFormState(const GovernmentForm& state);
    void SetSecularismState(const Secularism& state);
    void SetGlobalismState(const Globalism& state);
    void SetMilitarismState(const Militarism& state);

    void SetEconomyStateFromValue(const int& value);
    void SetAuthorityStateFromValue(const int& value);
    void SetCultureStateFromValue(const int& value);
    void SetGovernmentFormStateFromValue(const int& value);
    void SetSecularismStateFromValue(const int& value);
    void SetGlobalismStateFromValue(const int& value);
    void SetMilitarismStateFromValue(const int& value);

    void UpdateEconomyState();
    void UpdateAuthorityState();
    void UpdateCultureState();
    void UpdateGovernmentFormState();
    void UpdateSecularismState();
    void UpdateGlobalismState();
    void UpdateMilitarismState();

    void UpdateAllStates();


    bool IsCapitalist() const;
    bool IsFreeMarket() const;
    bool IsStateControlled() const;
    bool IsCommunist() const;

    bool IsLibertarian() const;
    bool IsLiberal() const;
    bool IsAuthoritarian() const;
    bool IsTotalitarian() const;

    bool IsProgressive() const;
    bool IsModerate() const;
    bool IsTraditionalist() const;
    bool IsNationalist() const;

    bool IsPopulist() const;
    bool IsDemocratic() const;
    bool IsTechnocratic() const;
    bool IsElitist() const;

    bool IsTheocratic() const;
    bool IsReligious() const;
    bool IsSecular() const;
    bool IsAnticlerical() const;

    bool IsIsolationist() const;
    bool IsNonInterventionist() const;
    bool IsOpen() const;
    bool IsGlobalist() const;

    bool IsPacifist() const;
    bool IsDefensive() const;
    bool IsArmed() const;
    bool IsMilitarist() const;


    void ShiftTowards(const Economy& idea);
    void ShiftTowards(const Authority& idea);
    void ShiftTowards(const Culture& idea);
    void ShiftTowards(const GovernmentForm& idea);
    void ShiftTowards(const Secularism& idea);
    void ShiftTowards(const Globalism& idea);
    void ShiftTowards(const Militarism& idea);

    void ShiftTowardsIdeology(const Ideology& other);


    void RepelFrom(const Economy& idea);
    void RepelFrom(const Authority& idea);
    void RepelFrom(const Culture& idea);
    void RepelFrom(const GovernmentForm& idea);
    void RepelFrom(const Secularism& idea);
    void RepelFrom(const Globalism& idea);
    void RepelFrom(const Militarism& idea);

    void RepelFromIdeology(const Ideology& other);

    int CalculateIdeologicalDifference(const Ideology& other) const;

private:
    
    void SetEconomyValue(const int& value);
    void SetAuthorityValue(const int& value);
    void SetCultureValue(const int& value);
    void SetGovernmentFormValue(const int& value);
    void SetSecularismValue(const int& value);
    void SetGlobalismValue(const int& value);
    void SetMilitarismValue(const int& value);

    Economy AssessEconomy() const;
    Authority AssessAuthority() const;
    Culture AssessCulture() const;
    GovernmentForm AssessGovernmentForm() const;
    Secularism AssessSecularism() const;
    Globalism AssessGlobalism() const;
    Militarism AssessMilitarism() const;


private:

    std::array<int, static_cast<int>(Axis::Count)> m_Values{};

    Economy m_Economy = Economy::FreeMarket;
    Authority m_Authority = Authority::Liberal;
    Culture m_Culture = Culture::Moderate;
    GovernmentForm m_GovernmentForm = GovernmentForm::Democratic;
    Secularism m_Secularism = Secularism::Religious;
    Globalism m_Globalism = Globalism::NonInterventionist;
    Militarism m_Militarism = Militarism::Defensive;

};
