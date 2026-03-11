#include "Character.h"
#include <random>
#include "../Skill/Skill.h"


ACharacter::ACharacter(const string& NewName, const FUnitStat& NewStat)
{
    Name = NewName;
    Stat = NewStat;

    Stat.Hp = Stat.MaxHp;
    Stat.Mp = Stat.MaxMp;

    cout << "[생성] " << Name << "가 전장에 나타났습니다! (HP: " << Stat.Hp << ")" << endl;
}

ACharacter::~ACharacter()
{
    cout << "ACharacter 소멸됨" << endl;
}

int ACharacter::TakeDamage(int DamageAmount)
{
    DamageAmount = DamageAmount - Stat.Def;
    DamageAmount = max(DamageAmount, 0);
    
    Stat.Hp = Stat.Hp - DamageAmount;
    Stat.Hp = max(Stat.Hp , 0);
    return DamageAmount;
}

void FDamageResult::PrintMessage(const string& AttackMessage)
{
    cout << "-------------------------------------------------" << endl;
    Attacker->PrintName();
    cout << AttackMessage << '\n';

    Target->PrintName();
    cout << "받은 데미지 : " << Damage << " | 남은 HP : " << Target->GetHp() << "/" << Target->GetMaxHp() << endl;
    cout << "-------------------------------------------------" << endl;
}

void ACharacter::PrintName()
{
    cout << "[" << Name << "] ";
}

int ACharacter::GetRandomInt(int Max)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, Max - 1);
    return dis(gen);
}

void ACharacter::ShowStat()
{
    cout << "[" << GetName() << "] HP: " << Stat.Hp << " / " << Stat.MaxHp << " | MP: " << Stat.Mp << " / " << Stat.MaxMp << endl;
}

void ACharacter::Heal(int Amount)
{
    int BeforeHp = Stat.Hp;
    Stat.Hp += Amount;
    Stat.Hp = min(Stat.Hp, Stat.MaxHp);
    int ActualHeal = Stat.Hp - BeforeHp;

    cout << ActualHeal << "만큼 회복했습니다." << endl;
}

void ACharacter::PlayTurn(ACharacter* Target) 
{

}