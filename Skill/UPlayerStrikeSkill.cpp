#include "UPlayerStrikeSkill.h"
#include "../Character/Character.h"
#include <string>

UPlayerStrikeSkill::UPlayerStrikeSkill(ACharacter* NewOwner)
	:USkill(NewOwner)
{

}

void UPlayerStrikeSkill::Play(ACharacter* Target)
{
    FDamageResult result;
    result.Attacker = Owner;
    result.Target = Target;
    result.bCritical = false;

    int FinalDamage = Target->TakeDamage(Owner->GetAtk() * 2);
    result.Damage = FinalDamage;
    result.PrintMessage("이(가) 스킬을 사용했습니다! ");
}