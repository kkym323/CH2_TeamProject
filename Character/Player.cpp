#include "Player.h"
#include "../Skill/Skill.h"
#include "../Skill/UPlayerAttackSkill.h"
#include "../Skill/UPlayerStrikeSkill.h"
#include "../Skill/UPlayerGambleAttack.h"

APlayer::APlayer(const string& NewName, const FUnitStat& NewStat)
	: ACharacter(NewName, NewStat)
{
	Level = 1;
	Exp = 0;

    Skills.push_back(make_unique<UPlayerAttackSkill>(this));
    Skills.push_back(make_unique<UPlayerStrikeSkill>(this));
    Skills.push_back(make_unique<UPlayerGambleAttack>(this));
}

APlayer::~APlayer()
{

}

void APlayer::UseItem()
{
	
}

void APlayer::LevelUp()
{

}

void APlayer::PlayTurn(ACharacter* Target)
{
    cout << "=== 스킬 목록 ===" << endl;
    for (int i = 0; i < Skills.size(); i++)
    {
        cout << i + 1 << ". " << Skills[i]->GetName() << endl;
    }

    int choice = 0;
    while (choice < 1 || choice > Skills.size())
    {
        cout << "스킬을 선택하세요: ";
        cin >> choice;

        if (choice < 1 || choice > Skills.size())
        {
            cout << "잘못된 입력입니다!" << endl;
        }
    }

    Skills[choice - 1]->Play(Target);
}