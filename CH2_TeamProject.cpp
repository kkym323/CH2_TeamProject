#include <Windows.h>
#include "Character/Character.h"
#include "Character/Player.h"
#include "Character/Monster.h"
using namespace std;

void WaitForPlayerInput()
{
    system("pause");
    cout << endl;
}

int main()
{

    ACharacter* Player = new APlayer("나의 용사", {200, 50, 30, 5, 10});
    ACharacter* Monster = new AMonster("무서운 오크", { 100, 30, 20, 3, 10 });

    cout << "===  데스매치 시작!  ===" << endl;
    WaitForPlayerInput();

    while (!Player->IsDead() && !Monster->IsDead())
    {
        Player->PlayTurn(Monster);

        if (Monster->IsDead())
        {
            cout << "몬스터가 쓰러졌습니다! 승리!" << endl;
            break;
        }

        WaitForPlayerInput();

        Monster->PlayTurn(Player);

        if (Player->IsDead())
        {
            cout << "플레이어가 쓰러졌습니다... 패배..." << endl;
            break;
        }

        WaitForPlayerInput();
    }

    delete Player;
    delete Monster;
    
    return 0;
}