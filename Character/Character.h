#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "../Skill/Skill.h"

using namespace std;

class USkill;

struct FUnitStat
{
    int MaxHp;
    int MaxMp;
    int Atk;
    int Def;
    int Critical;

    int Hp = 0;
    int Mp = 0;

    FUnitStat()
    {
    }

    FUnitStat(int MaxHp, int MaxMp, int Atk, int Def, int Critical)
    {
        this->MaxHp = MaxHp;
        this->MaxMp = MaxMp;

        this->Atk = Atk;
        this->Def = Def;
        this->Critical = Critical;
    }
};

class ACharacter;

struct FDamageResult
{
    int Damage;
    bool bCritical;

    ACharacter* Attacker;
    ACharacter* Target;

    void PrintMessage(const string& AttackMessage);
};

class ACharacter
{
public:
    ACharacter(const string& NewName, const FUnitStat& NewStat);
    virtual ~ACharacter();

protected:
    string Name;
    FUnitStat Stat;
    vector<unique_ptr<USkill>> Skills;

public:
    int TakeDamage(int DamageAmount);
    virtual void PlayTurn(ACharacter* Target);
    void Heal(int Amount);
    void ShowStat();
    
    int GetHp() { return Stat.Hp; }
    bool IsDead() { return Stat.Hp <= 0; }
    string GetName() { return Name; }
    void PrintName();
    int GetMaxHp() const { return Stat.MaxHp; }
    int GetAtk() { return Stat.Atk; }
    int GetCritical() { return Stat.Critical; }
    int GetRandomInt(int Max = 100);
};