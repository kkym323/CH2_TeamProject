#pragma once
#include "Character.h"

class AMonster : public ACharacter
{
public:
    AMonster(const string& NewName, const FUnitStat& NewStat);
    FDamageResult Attack(ACharacter* Target) override;
    void UseSkill(ACharacter* Target) override;
};