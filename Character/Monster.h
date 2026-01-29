#pragma once
#include "Character.h"

class AMonster : public ACharacter
{
public:
    AMonster(const string& NewName, const FUnitStat& NewStat);
    void Attack(ACharacter* Target) override;
};