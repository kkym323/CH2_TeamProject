#include "Player.h"

APlayer::APlayer(const string& NewName, const FUnitStat& NewStat)
	: ACharacter(NewName, NewStat)
{
	Level = 1;
	Exp = 0;
}

void APlayer::Attack(ACharacter* Target)
{
	cout << "휘릭! " << Name << "이(가) 검을 휘두릅니다!" << endl;
	ACharacter::Attack(Target);
}

void APlayer::UseItem()
{
	
}

void APlayer::LevelUp()
{

}
