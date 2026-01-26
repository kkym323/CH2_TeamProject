#include "Character.h"
#include <random>

int getRandomInt()
{
    // �õ尪 ������ (�� ���� �ʱ�ȭ�ϱ� ���� static ���)
    static std::random_device rd;

    // �޸��� Ʈ������ ���� (��ǰ�� ���� ������)
    static std::mt19937 gen(rd());

    // 0���� 100���� �յ��ϰ� ���� (�� ���� ����)
    std::uniform_int_distribution<int> dis(0, 100);

    return dis(gen);
}

ACharacter::ACharacter(string NewName, int NewHp, int NewAtk, int NewDef, int NewCritical)
{
    Name = NewName;
    Hp = NewHp;
    Atk = NewAtk;
    Def = NewDef;
    Critical = NewCritical;

    cout << "[����] " << Name << "�� ���忡 ��Ÿ�����ϴ�! (HP: " << Hp << ")" << endl;
}

ACharacter::~ACharacter()
{
    cout << "ACharacter �Ҹ��" << endl;
}

void ACharacter::Attack(ACharacter* Target)
{
    if (getRandomInt() <= 10)
    {
        //��Ÿ ����
        int Crtical_Atk = Atk * 15 / 10;
        cout << Name << "�� �����մϴ�![ũ��Ƽ��!] (���ݷ�: " << Crtical_Atk << ")" << endl;
        Target->TakeDamage(Crtical_Atk);
    }
    else
    {
        cout << Name << "�� �����մϴ�! (���ݷ�: " << Atk << ")" << endl;
        Target->TakeDamage(Atk);
    }
    
    //if else �ٱ����� takedamage ȣ���ؼ� ���� ����.
}

void ACharacter::TakeDamage(int DamageAmount)
{
    if (Def >= DamageAmount)
    {
        DamageAmount = 0;
        cout << Name << "�� " << DamageAmount << "�� ���ظ� �Ծ����ϴ�." << endl;
        cout << "   -> ���� ü��: " << Hp << endl;
        //early return ����.
    }
    else
    {
        int Damage = DamageAmount - Def;
        Hp = Hp - Damage;
        //std::max() �� ��ü ����.
        if (Hp < 0)
        {
            Hp = 0;
        }
        cout << Name << "�� " << Damage << "�� ���ظ� �Ծ����ϴ�." << endl;
        cout << "   -> ���� ü��: " << Hp << endl;
        
    }
}

int ACharacter::GetHp()
{
    return Hp;
}

bool ACharacter::IsDead()
{
    if (Hp <= 0)
    {
        return true;
    }

    else
        return false;
}

