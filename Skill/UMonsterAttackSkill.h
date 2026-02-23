#pragma once

#include "Skill.h"

class UMonsterAttackSkill : public USkill
{
public:
	UMonsterAttackSkill(ACharacter* NewOwner);

	void Play(ACharacter* Target) override;
};
