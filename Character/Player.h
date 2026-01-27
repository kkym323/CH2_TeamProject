#pragma once
#include "Character.h"

class Player : public ACharacter
{
public:
	Player(const string& NewName, const FUnitStat& NewStat);
	virtual ~Player();

private:
	int Level;
	int Exp;

public:
	void UseItem();
	void LevelUp();

};

