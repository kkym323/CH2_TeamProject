#include <Windows.h>
#include <iostream>

#include "ABattleManager.h"
#include "Character/Character.h"
#include "Character/Monster.h"
#include "Character/Player.h"

using namespace std;

int main()
{
	auto BattleManager = make_unique<ABattleManager>();

	FUnitStat PlayerStat(200, 50, 30, 5, 10);
	FUnitStat MonsterStat(100, 30, 20, 3, 10);

	auto Player = make_unique<APlayer>("용사", PlayerStat);
	auto Monster = make_unique<AMonster>("몬스터", MonsterStat);

	cout << "===  데스매치 시작!  ===" << endl;

	BattleManager->WaitForPlayerInput();
	BattleManager->RunBattle(Player.get(), Monster.get());
	BattleManager->WaitForPlayerInput();

	cout << "===  데스매치 종료!  ===" << endl;

	return 0;
}
