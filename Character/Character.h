#pragma once
#include <iostream>
#include <string>

using namespace std;

struct FUnitStat
{
    int Hp;
    int Atk;
    int Def;
    int Critical;
};

class ACharacter
{
public:
    ACharacter(string NewName, const FUnitStat& NewStat);
    ~ACharacter();

protected:
    string Name;
    FUnitStat Stat;

public:
    void Attack(ACharacter* Target);
    void TakeDamage(int DamageAmount);
    
    //간단한 게터는 헤더에서 구현하는 것을 권장.
    int GetHp();
    bool IsDead();
};