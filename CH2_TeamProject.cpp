#include <Windows.h>
#include "Character/Character.h"

//Monster  그냥 상속해서 구현

//Player는 
// 멤버변수: Level, Exp
// 멤버함수: UseItem(), LevelUp() - 빈 구현


int main()
{
    FUnitStat PlayerStat;
    PlayerStat.Hp = 200;
    PlayerStat.Atk = 15;
    PlayerStat.Def = 5;
    PlayerStat.Critical = 10;

    ACharacter* Player = new ACharacter("나의 용사", PlayerStat);
    ACharacter* Monster = new ACharacter("무서운 오크", { 100, 10, 5, 10 });

    cout << "===  데스매치 시작!  ===" << endl;
    Sleep(1000);

    while (!Player->IsDead() && !Monster->IsDead())
    {
        Player->Attack(Monster);

        if (Monster->IsDead())
        {
            cout << "몬스터가 쓰러졌습니다! 승리!" << endl;
            break;
        }

        Sleep(500);

        Monster->Attack(Player);

        if (Player->IsDead())
        {
            cout << "플레이어가 쓰러졌습니다... 패배..." << endl;
            break;
        }

        Sleep(1000);
    }

    delete Player;
    delete Monster;
    return 0;
}