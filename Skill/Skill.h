#pragma once

class ACharacter;

class USkill
{
public:
	USkill(ACharacter* NewOwner);
	virtual void Play(ACharacter* Target) = 0;

protected:
	ACharacter* Owner;
};