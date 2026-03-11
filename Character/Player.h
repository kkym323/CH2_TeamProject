#pragma once
#include "Character.h"

class APlayer : public ACharacter
{
public:
	APlayer(const string& NewName, const FUnitStat& NewStat);
	~APlayer() override;

private:
	int Level;
	int Exp;

public:
	void UseItem();
	void LevelUp();
	void PlayTurn(ACharacter* Target) override;
};

