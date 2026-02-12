#include <Windows.h>
#include "Character/Character.h"
#include "Character/Player.h"
#include "Character/Monster.h"
using namespace std;

ACharacter* Player = new APlayer("나의 용사", { 200, 50, 30, 5, 10 });
ACharacter* Monster = new AMonster("무서운 오크", { 100, 30, 20, 3, 10 });


void WaitForPlayerInput()
{
    system("pause");
    cout << endl;
}

bool BattleTurn(ACharacter* Attacker, ACharacter* Defender) 
{
        Attacker->PlayTurn(Defender);
        WaitForPlayerInput();

        if (Defender->IsDead())
        {
            cout << Defender->GetName() << "가 쓰러졌습니다! "<< Attacker->GetName() << "의 승리!" << endl;
            return true;
        }
        return false;
}

int main()
{
    cout << "===  데스매치 시작!  ===" << endl;
    WaitForPlayerInput();

    while (true)
    {
        if (BattleTurn(Player, Monster) == true)
        {
            break;
        }

        if (BattleTurn(Monster, Player) == true)
        {
            break;
        }
    }

    WaitForPlayerInput();

    delete Player;
    delete Monster;
    
    return 0;
}