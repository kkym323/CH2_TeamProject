// 파일명: Character.h
#pragma once
#include <iostream>
#include <string> // 문자열(이름)을 쓰기 위해 필요합니다.

using namespace std;

// [Mission 1] 클래스 선언
// 언리얼 표준: 클래스 이름은 'A'로 시작합니다.
class ACharacter
{
public:
    ACharacter(string NewName, int NewHp, int NewAtk);
    ~ACharacter();

protected:
    string Name;
    int Hp;
    int Atk;

public:
    void Attack(ACharacter* Target);
    void TakeDamage(int DamageAmount);
    int GetHp();
    bool IsDead();
};