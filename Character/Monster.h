#pragma once
#include "Character.h"

class Monster : public ACharacter
{
public:
    Monster(const string& NewName, const FUnitStat& NewStat);
    virtual ~Monster();
};

