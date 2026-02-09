#include "Player.h"

APlayer::APlayer(const string& NewName, const FUnitStat& NewStat)
	: ACharacter(NewName, NewStat)
{
	Level = 1;
	Exp = 0;
}

FDamageResult APlayer::Attack(ACharacter* Target)
{
    FDamageResult result = ACharacter::Attack(Target);
    string AttackMessage = "이(가) 검을 휘두릅니다! ";
    if (result.bCritical)
    {
        AttackMessage = "이(가) *급소*를 베었습니다! ";
    }

    result.PrintMessage(AttackMessage);
    return result;
}

void APlayer::UseSkill(ACharacter* Target)
{
    FDamageResult result;
    result.Attacker = this;
    result.Target = Target;
    result.bCritical = false;

    int FinalDamage = Target->TakeDamage(Stat.Atk * 2);
    result.Damage = FinalDamage;
    result.PrintMessage("이(가) 스킬을 사용했습니다! ");
}

void APlayer::UseItem()
{
	
}

void APlayer::LevelUp()
{

}
