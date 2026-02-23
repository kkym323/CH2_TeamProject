#include "UPlayerAttackSkill.h"
#include "../Character/Character.h"
#include <string>

UPlayerAttackSkill::UPlayerAttackSkill(ACharacter* NewOwner) 
	:USkill(NewOwner)
{

}

void UPlayerAttackSkill::Play(ACharacter* Target)
{
    int Damage = Owner->GetAtk();
    bool bCritical = Owner->GetRandomInt() < Owner->GetCritical();
    if (bCritical)
    {
        Damage = static_cast<int>(Damage * 1.5f);
    }

    int FinalDamage = Target->TakeDamage(Damage);
    FDamageResult result;
    result.Damage = FinalDamage;
    result.Attacker = Owner;
    result.Target = Target;
    result.bCritical = bCritical;

    string AttackMessage = "이(가) 검을 휘두릅니다! ";
    if (result.bCritical)
    {
        AttackMessage = "이(가) *급소*를 베었습니다! ";
    }

    result.PrintMessage(AttackMessage);
}