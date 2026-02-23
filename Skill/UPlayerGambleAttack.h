#pragma once

#include "Skill.h"

class UPlayerGambleAttack:public USkill
{
public:
	UPlayerGambleAttack(ACharacter* NewOWner);

	void Play(ACharacter* Target) override;
};

