#pragma once

#include "Skill.h"

class UMonsterDrainSkill : public USkill
{
public:
	UMonsterDrainSkill(ACharacter* NewOwner);

	void Play(ACharacter* Target) override;
};
