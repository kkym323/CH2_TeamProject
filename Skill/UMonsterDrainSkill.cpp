#include "UMonsterDrainSkill.h"
#include "../Character/Character.h"
#include <string>

UMonsterDrainSkill::UMonsterDrainSkill(ACharacter* NewOwner)
	:USkill(NewOwner)
{

}

void UMonsterDrainSkill::Play(ACharacter* Target)
{
	FDamageResult result;
	result.Attacker = Owner;
	result.Target = Target;
	result.bCritical = false;

	int FinalDamage = Target->TakeDamage(Owner->GetAtk());
	result.Damage = FinalDamage;

	result.PrintMessage("이(가) 스킬을 사용했습니다! ");
	Owner->Heal(FinalDamage);
}