#include "ABattleManager.h"
#include <iostream>

#include "Character/Character.h"

using namespace std;

void ABattleManager::RunBattle(ACharacter* charA, ACharacter* charB)
{
	while (!charA->IsDead() && !charB->IsDead())
	{
		// 1. 플레이어의 턴 (게임 끝났으면 break)
		if (BattleTurn(charA, charB) == true)
		{
			break;
		}

		// 2. 몬스터의 턴 (게임 끝났으면 break)
		if (BattleTurn(charB, charA) == true)
		{
			break;
		}
	}
}

void ABattleManager::WaitForPlayerInput()
{
	system("pause");
	cout << endl;
}

bool ABattleManager::BattleTurn(ACharacter* Attacker, ACharacter* Defender)
{
	std::cout << "[System] " << Attacker->GetName() << "의 턴입니다...!\n";
	Attacker->PlayTurn(Defender);
	Attacker->ShowStat();
	Defender->ShowStat();

	WaitForPlayerInput();
	if (Defender->IsDead())
	{
		cout << "[System] " << Defender->GetName() << " 사망... ㅠㅠ. 꿱\n";
	}

	return Defender->IsDead();
}
