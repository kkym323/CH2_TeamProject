#include "Skill.h"

USkill::USkill(ACharacter* NewOwner, int NewMpCost, string NewName)
{
	Owner = NewOwner;
	Name = NewName;
	MpCost = NewMpCost;
}
