#pragma once

#include "Skill.h"

class UPlayerAttackSkill : public USkill
{
public:
	UPlayerAttackSkill(ACharacter* NewOwner);

	void Play(ACharacter* Target) override;
};

