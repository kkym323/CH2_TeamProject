#include "Character.h"

ACharacter::ACharacter()
{
    Name = "Unknown";
    Hp = 100;
    Atk = 10;
    cout << "ACharacter 생성됨: " << Name << " (HP: " << Hp << ")" << endl;
}

ACharacter::~ACharacter()
{
    cout << "ACharacter 소멸됨" << endl;
}

void ACharacter::Attack()
{
    cout << Name << "가 공격합니다! (공격력: " << Atk << ")";
}

void ACharacter::TakeDamage(int DamageAmount)
{
    Hp = Hp - DamageAmount;

    cout << Name << "가 " << DamageAmount << "의 피해를 입었습니다." << endl;
    cout << "   -> 남은 체력: " << Hp << endl;
}