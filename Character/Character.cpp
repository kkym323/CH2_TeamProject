#include "Character.h"
#include <random>

int getRandomInt()
{
    // 시드값 생성기 (한 번만 초기화하기 위해 static 사용)
    static std::random_device rd;

    // 메르센 트위스터 엔진 (고품질 난수 생성기)
    static std::mt19937 gen(rd());

    // 0부터 100까지 균등하게 분포 (양 끝값 포함)
    std::uniform_int_distribution<int> dis(0, 100);

    return dis(gen);
}

ACharacter::ACharacter(string NewName, const FUnitStat& NewStat)
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
    if (getRandomInt() <= 10)
    {
        //오타 수정
        int Crtical_Atk = Stat.Atk * 15 / 10;
        cout << Name << "가 공격합니다![크리티컬!] (공격력: " << Crtical_Atk << ")" << endl;
        Target->TakeDamage(Crtical_Atk);
    }
    else
    {
        cout << Name << "가 공격합니다! (공격력: " << Stat.Atk << ")" << endl;
        Target->TakeDamage(Stat.Atk);
    }


    //if else 바깥에서 takedamage 호출해서 통일 가능.
}

void ACharacter::TakeDamage(int DamageAmount)
{
    if (Stat.Def >= DamageAmount)
    {
        DamageAmount = 0;
        cout << Name << "가 " << DamageAmount << "의 피해를 입었습니다." << endl;
        cout << "   -> 남은 체력: " << Stat.Hp << endl;
        //early return 권장.
    }
    else
    {
        int Damage = DamageAmount - Stat.Def;
        Stat.Hp = Stat.Hp - Damage;
        //std::max() 로 교체 가능.
        if (Stat.Hp < 0)
        {
            Stat.Hp = 0;
        }
        cout << Name << "가 " << Damage << "의 피해를 입었습니다." << endl;
        cout << "   -> 남은 체력: " << Stat.Hp << endl;

    }
}

int ACharacter::GetHp()
{
    return Stat.Hp;
}

bool ACharacter::IsDead()
{
    if (Stat.Hp <= 0)
    {
        return true;
    }

    else
        return false;
}