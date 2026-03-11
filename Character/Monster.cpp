#include "Monster.h"
#include "../Skill/Skill.h"
#include "../Skill/UMonsterAttackSkill.h"
#include "../Skill/UMonsterDrainSkill.h"

//자식클래스 생성자에서는, 부모 생성자를 호출해줘야 한다.
AMonster::AMonster(const string& NewName, const FUnitStat& NewStat)
	: ACharacter(NewName, NewStat)
{
	Skills.push_back(make_unique<UMonsterAttackSkill>(this));
	Skills.push_back(make_unique<UMonsterDrainSkill>(this));
}

AMonster::~AMonster()
{

}

void AMonster::PlayTurn(ACharacter* Target)
{
	int index = GetRandomInt(Skills.size());
	Skills[index]->Play(Target);
}