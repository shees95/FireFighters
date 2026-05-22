#include <iostream>
#include <string>
using namespace std;
#include <cstdlib>

#include "Monster.h"
#include "Player.h"

Monster::Monster(string Name, int Health, int Attack)
	:Name(Name), Health(Health), Attack(Attack)
{
}

//랜덤값 구하는 함수
int Monster::GetRandomValue(int Min, int Max)
{
	return rand() % (Max - Min + 1) + Min;
}

void Monster::Attack(Player& Player)
{
	cout << Name << "이 " << Player.GetName() << "을 공격합니다!";
	Player.SetHealth(Player.GetHealth() - Attack);

	cout << Player.GetName() << " 체력 : " << Player.GetHealth()+ Attack << " -> " << Player.GetHealth() << "(" << Attack << ")" << endl;
}

void Monster::TakeDamage(Player& Player)
{
	Health -= Player.GetAttack();
	cout << Player.GetName() << "가 " << Name << "을 공격합니다! "
		<< Name << " 체력: " << Health + Player.GetAttack() << " -> " << Health << "(" << Player.GetAttack() << ")" << endl;
}


//랜덤한 몬스터를 불러오는 함수
Monster Monster::SpawnRandomMonster(int PlayerLevel)
{
	//플레이어 레벨에 따라 체력, 공격령 변경
	int Health = GetRandomValue(PlayerLevel * 20, PlayerLevel * 30);
	int Attack = GetRandomValue(PlayerLevel * 5, PlayerLevel * 10);

	//스위치 구문용 랜덤 수치 (몬스터가 4마리니까 0~3 사이 랜덤)
	int RandomIndex = rand() % 4;

	//랜덤한 몬스터 선택
	switch (RandomIndex)
	{
	case 0:
		return Monster("슬라임", Health, Attack);

	case 1:
		return Monster("고블린", Health, Attack);

	case 2:
		return Monster("오크", Health, Attack);

	case 3:
		return Monster("스켈레톤", Health, Attack);

	default:
		return Monster("슬라임", Health, Attack);
	}
}

Monster Monster::SpawnBossMonster(int PlayerLevel)
{
	//보스 몬스터는 기존 몬스터보다 1.5배 스텟
	int Health = GetRandomValue(PlayerLevel * 20 * 1.5, PlayerLevel * 30 * 1.5);
	int Attack = GetRandomValue(PlayerLevel * 5 * 1.5, PlayerLevel * 10 * 1.5);

	return Monster("짱짱쎈 투명드래곤", Health, Attack);
}


