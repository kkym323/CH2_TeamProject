#include "Monster.h"

//자식클래스 생성자에서는, 부모 생성자를 호출해줘야 한다.
AMonster::AMonster(const string& NewName, const FUnitStat& NewStat)
	: ACharacter(NewName, NewStat)
{
	
}

void AMonster::Attack(ACharacter* Target)
{
	cout << "크아앙! " << Name << "이(가) 이빨로 물어뜯습니다!" << endl;

	Target->TakeDamage(Stat.Atk);
}