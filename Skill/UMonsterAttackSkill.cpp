#include "UMonsterAttackSkill.h"
#include "../Character/Character.h"
#include <string>

UMonsterAttackSkill::UMonsterAttackSkill(ACharacter* NewOwner)
	:USkill(NewOwner)
{

}

void UMonsterAttackSkill::Play(ACharacter* Target)
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

	string AttackMessage = "이(가) 이빨로 물어뜯습니다!";
	if (result.bCritical)
	{
		AttackMessage = "이(가) *급소*를 물어뜯습니다!";
	}

	result.PrintMessage(AttackMessage);
}