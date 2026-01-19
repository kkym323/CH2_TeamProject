#include "Character.h"

ACharacter::ACharacter(string NewName, int NewHp, int NewAtk)
{
    Name = NewName;
    Hp = NewHp;
    Atk = NewAtk;

    cout << "[생성] " << Name << "가 전장에 나타났습니다! (HP: " << Hp << ")" << endl;
}

ACharacter::~ACharacter()
{
    cout << "ACharacter 소멸됨" << endl;
}

void ACharacter::Attack(ACharacter* Target)
{
    cout << Name << "가 공격합니다! (공격력: " << Atk << ")";
    Target->TakeDamage(Atk);
}

void ACharacter::TakeDamage(int DamageAmount)
{
    Hp = Hp - DamageAmount;
    if (Hp < 0)
    {
        Hp = 0;
    }

    cout << Name << "가 " << DamageAmount << "의 피해를 입었습니다." << endl;
    cout << "   -> 남은 체력: " << Hp << endl;
}

int ACharacter::GetHp()
{
    return Hp;
}

bool ACharacter::IsDead()
{
    if (Hp <= 0)
    {
        return true;
    }

    else
        return false;
}