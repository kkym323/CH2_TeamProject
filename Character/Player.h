#pragma once
#include "Character.h"

class APlayer : public ACharacter
{
public:
	APlayer(const string& NewName, const FUnitStat& NewStat);

private:
	int Level;
	int Exp;

public:
	void UseItem();
	void LevelUp();
};

