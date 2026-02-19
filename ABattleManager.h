#pragma once

class ACharacter;

class ABattleManager
{
public:
	void RunBattle(ACharacter* charA, ACharacter* charB);
	void WaitForPlayerInput();

private:
	bool BattleTurn(ACharacter* Attacker, ACharacter* Defender);
};
