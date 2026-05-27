#include <iostream>
#include <string>
using namespace std;
#include <cstdlib>
//랜덤 난수용(rand) 라이브러리

#include "Monster.h"
#include "../Character/Character.h"

Monster::Monster(string Name, int MaxHealth, int Power, Item DropItem)
	:Name(Name), MaxHealth(MaxHealth), Power(Power), DropItem(DropItem)
{
	Health = MaxHealth;
}

//랜덤값 구하는 함수
int Monster::GetRandomValue(int Min, int Max)
{
	return rand() % (Max - Min + 1) + Min;
}

void Monster::Attack(Character* character)
{
	cout << Name << "이 " << character->GetName() << "을 공격합니다!" << endl;
	character->TakeDamage(this);
}

void Monster::TakeDamage(Character* character)
{
	cout << Name << "이(가) 공격 받았습니다!" << endl;
	Health -= character->GetPower();
	cout << "체력 : " << Health + character->GetPower() << " -> " << Health << " (-" << character->GetPower() << ")" << endl;
}


//랜덤한 몬스터를 불러오는 함수
Monster Monster::SpawnRandomMonster(int CharacterLevel)
{
	//플레이어 레벨에 따라 체력, 공격력 변경
	int Health = GetRandomValue(CharacterLevel * 20, CharacterLevel * 30);
	int Power = GetRandomValue(CharacterLevel * 5, CharacterLevel * 10);

	//스위치 구문용 랜덤 수치 (몬스터가 4마리니까 0~3 사이 랜덤)
	int RandomIndex = rand() % 4;

	//랜덤한 몬스터 선택
	switch (RandomIndex)
	{
	case 0:
		return Monster("슬라임",Health,Power,Item("슬라임 젤리", ItemType::Etc, 0, 0, 20));

	case 1:
		return Monster("고블린", Health, Power,Item("고블린의 손톱", ItemType::Etc, 0, 0, 30));

	case 2:
		return Monster("오크", Health, Power, Item("오크의 가죽", ItemType::Etc, 0, 0, 40));

	case 3:
		return Monster("스켈레톤", Health, Power, Item("스켈레톤의 뼈", ItemType::Etc, 0, 0, 50));

	default:
		return Monster("슬라임", Health, Power, Item("슬라임 젤리", ItemType::Etc, 0, 0, 20));
	}
}

Monster Monster::SpawnBossMonster(int CharacterLevel)
{
	//보스 몬스터는 기존 몬스터보다 1.5배 스텟
	int Health = GetRandomValue((int)(CharacterLevel * 20 * 1.5),(int)(CharacterLevel * 30 * 1.5));
	int Power = GetRandomValue((int)(CharacterLevel * 5 * 1.5),(int)(CharacterLevel * 10 * 1.5));

	return Monster("짱짱쎈 투명드래곤", Health, Power, Item("짱짱쎈 투명 드래곤 하트!!!!", ItemType::Etc, 0, 0, 99999));
}


void Monster::MonsterStatus()
{
	cout << Name << endl;
	cout << "HP: " << Health << " / " << MaxHealth << "\tPower: " << GetPower() << endl;
}