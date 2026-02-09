#include "Monster.h"

//자식클래스 생성자에서는, 부모 생성자를 호출해줘야 한다.
AMonster::AMonster(const string& NewName, const FUnitStat& NewStat)
	: ACharacter(NewName, NewStat)
{

}

FDamageResult AMonster::Attack(ACharacter* Target)
{
	FDamageResult result = ACharacter::Attack(Target);
	string AttackMessage = "이(가) 이빨로 물어뜯습니다!";
	if (result.bCritical)
	{
		AttackMessage = "이(가) *급소*를 물어뜯습니다!";
	}

	result.PrintMessage(AttackMessage);
	return result;
}

void AMonster::UseSkill(ACharacter* Target)
{
	FDamageResult result;
	result.Attacker = this;
	result.Target = Target;
	result.bCritical = false;

	int FinalDamage = Target->TakeDamage(Stat.Atk);
	result.Damage = FinalDamage;

	result.PrintMessage("이(가) 스킬을 사용했습니다! ");
	Heal(FinalDamage);
}