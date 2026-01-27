#include "Monster.h"

//자식클래스 생성자에서는, 부모 생성자를 호출해줘야 한다.
AMonster::AMonster(const string& NewName, const FUnitStat& NewStat)
	: ACharacter(NewName, NewStat)
{
	
}