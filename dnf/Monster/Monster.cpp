#include <iostream>
#include <string>
using namespace std;
#include <cstdlib>

#include "Monster.h"
#include "../Character/Character.h"

Monster::Monster(string Name, int Health, int Power)
	:Name(Name), Health(Health), Power(Power)
{
}

//랜덤값 구하는 함수
int Monster::GetRandomValue(int Min, int Max)
{
	return rand() % (Max - Min + 1) + Min;
}

void Monster::Attack(Character& Character)
{
	cout << Name << "이 " << Character.GetName() << "을 공격합니다!";
	Character.SetHealth(Character.GetHealth() - Power);

	cout << Character.GetName() << " 체력 : " << Character.GetHealth()+ Power << " -> " << Character.GetHealth() << "(" << Power << ")" << endl;
}

void Monster::TakeDamage(Character& Character)
{
	Health -= Character.GetPower();
	cout << Character.GetName() << "가 " << Name << "을 공격합니다! "
		<< Name << " 체력: " << Health + Character.GetPower() << " -> " << Health << "(" << Character.GetPower() << ")" << endl;
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
		return Monster("슬라임", Health, Power);

	case 1:
		return Monster("고블린", Health, Power);

	case 2:
		return Monster("오크", Health, Power);

	case 3:
		return Monster("스켈레톤", Health, Power);

	default:
		return Monster("슬라임", Health, Power);
	}
}

Monster Monster::SpawnBossMonster(int CharacterLevel)
{
	//보스 몬스터는 기존 몬스터보다 1.5배 스텟
	int Health = GetRandomValue(CharacterLevel * 20 * 1.5, CharacterLevel * 30 * 1.5);
	int Power = GetRandomValue(CharacterLevel * 5 * 1.5, CharacterLevel * 10 * 1.5);

	return Monster("짱짱쎈 투명드래곤", Health, Power);
}


