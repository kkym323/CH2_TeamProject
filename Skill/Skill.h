#pragma once
#include <string>

using namespace std;

class ACharacter;

class USkill
{
public:
	USkill(ACharacter* NewOwner, int NewMpCost, string NewName);
	virtual void Play(ACharacter* Target) = 0;
	string GetName() { return Name; }
	int GetMpCost() { return MpCost; }

protected:
	ACharacter* Owner;
	string Name;
	int MpCost;
};