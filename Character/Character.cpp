#include "Character.h"
#include <random>


ACharacter::ACharacter(const string& NewName, const FUnitStat& NewStat)
{
    Name = NewName;
    Stat = NewStat;

    cout << "[생성] " << Name << "가 전장에 나타났습니다! (HP: " << Stat.Hp << ")" << endl;
}

ACharacter::~ACharacter()
{
    cout << "ACharacter 소멸됨" << endl;
}

void ACharacter::Attack(ACharacter* Target)
{
    int Damage = Stat.Atk;
    if (GetRandomInt() <= Stat.Critical)
    {
        Damage = static_cast<int>(Damage * 1.5f);
        cout << "크리티컬...!! ";
    }
    
    cout << Name << "가 공격합니다! (공격력: " << Damage << ")" << endl;
    Target->TakeDamage(Damage);
}

void ACharacter::TakeDamage(int DamageAmount)
{
    int Damage = DamageAmount - Stat.Def;
    Damage = std::max(Damage, 0);
    
    Stat.Hp = Stat.Hp - Damage;
    Stat.Hp = std::max(Stat.Hp , 0);
    
    cout << Name << "가 " << Damage << "의 피해를 입었습니다." << endl;
    cout << "   -> 남은 체력: " << Stat.Hp << endl;
}

int ACharacter::GetRandomInt()
{
    // 시드값 생성기 (한 번만 초기화하기 위해 static 사용)
    static std::random_device rd;

    // 메르센 트위스터 엔진 (고품질 난수 생성기)
    static std::mt19937 gen(rd());

    // 0부터 100까지 균등하게 분포 (양 끝값 포함)
    std::uniform_int_distribution<int> dis(0, 100);

    return dis(gen);
}