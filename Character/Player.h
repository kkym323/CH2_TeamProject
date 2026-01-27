#pragma once
#include "Character.h"

class Player : public ACharacter
{
public:
	int Level;
	int Exp;

	void UseItem();
	void LevelUp();


};

