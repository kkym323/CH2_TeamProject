#include "Character/Character.h"

int main()
{

    ACharacter* MyChar = new ACharacter();

    MyChar->Attack();

    MyChar->TakeDamage(30);

    delete MyChar;

    return 0;
}