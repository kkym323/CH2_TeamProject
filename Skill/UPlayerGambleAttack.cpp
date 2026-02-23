#include "UPlayerGambleAttack.h"
#include "../Character/Character.h"
#include <string>

UPlayerGambleAttack::UPlayerGambleAttack(ACharacter* NewOwner)
	:USkill(Owner)
{

}

void UPlayerGambleAttack::Play(ACharacter* Target) 
{
    FDamageResult result;
    result.Attacker = Owner;
    result.Target = Target;
    result.bCritical = false;

    if (Owner->GetRandomInt() % 3 == 0) //랜덤 수가 3의 배수면 3배로 때리기
    {
        int FinalDamage = Target->TakeDamage(Owner->GetAtk() * 3);
        result.Damage = FinalDamage;
        result.PrintMessage("이(가) 도박 스킬을 사용했습니다! ");
    }
    else
    {
        result.PrintMessage("이(가) 도박 스킬을 실패했습니다! ");
    }
}