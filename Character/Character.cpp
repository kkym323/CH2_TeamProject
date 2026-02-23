#include "Character.h"
#include <random>


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

FDamageResult ACharacter::Attack(ACharacter* Target)
{
    int Damage = Stat.Atk;
    bool bCritical = GetRandomInt() < Stat.Critical;
    if (bCritical)
    {
        Damage = static_cast<int>(Damage * 1.5f);
    }

    int FinalDamage = Target->TakeDamage(Damage);
    FDamageResult result;
    result.Damage = FinalDamage;
    result.Attacker = this;
    result.Target = Target;
    result.bCritical = bCritical;
    return result;
}

int ACharacter::TakeDamage(int DamageAmount)
{
    DamageAmount = DamageAmount - Stat.Def;
    DamageAmount = max(DamageAmount, 0);
    
    Stat.Hp = Stat.Hp - DamageAmount;
    Stat.Hp = max(Stat.Hp , 0);
    return DamageAmount;
}

void UseSkill(ACharacter* Target)
{

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

int ACharacter::GetRandomInt()
{
    // 시드값 생성기 (한 번만 초기화하기 위해 static 사용)
    static std::random_device rd;

    // 메르센 트위스터 엔진 (고품질 난수 생성기)
    static std::mt19937 gen(rd());

    // 0부터 100까지 균등하게 분포 (양 끝값 포함)
    std::uniform_int_distribution<int> dis(0, 100);

    return dis(gen);
}

void ACharacter::ShowStat()
{
    cout << "[" << GetName() << "] HP: " << Stat.Hp << " / " << Stat.MaxHp << " | MP: " << Stat.Mp << " / " << Stat.MaxMp << endl;
}

void ACharacter::PlayTurn(ACharacter* Target)
{
    if (GetRandomInt() < 50)
    {
        Attack(Target);
    }
    else
    {
        UseSkill(Target);
    }
}

void ACharacter::Heal(int Amount)
{
    int BeforeHp = Stat.Hp;
    Stat.Hp += Amount;
    Stat.Hp = min(Stat.Hp, Stat.MaxHp);
    int ActualHeal = Stat.Hp - BeforeHp;

    cout << ActualHeal << "만큼 회복했습니다." << endl;
}