#include "Character.h"
#include <iostream>

using namespace std;

//싱글톤 패턴을 위한 멤버 변수 초기화
Character* Character::Instance = nullptr;

//생성자
Character::Character()
{
	Name = Name;
	Level = 1;
	Health = 200;
	MaxHealth = 200;
	Power = 30;
	Exp = 0;
	Gold = 0;
}

//싱글톤 객체 반환
Character* Character::GetInstance()
{
	//인스턴스가 아직 생성되지 않았다면 새로 생성
	if (Instance == nullptr)
	{
		Instance = new Character();
	}
	//생성된 인스턴스 반환
	return Instance;
}

//Damage를 입는 함수
void Character::TakeDamage(int damage)
{
	//체력이 damage만큼 감소 (음수방지)
	SetHealth(max(GetHealth() - damage, 0));

	cout << GetName() << " 이(가) " << damage << " 데미지를 입었습니다!" << endl;
}

void Character::Heal(int amount)
{
	//체력이 amount만큼 회복 (최대체력 초과 방지)
	SetHealth(min(GetHealth() + amount, GetMaxHealth()));

	cout << GetName() << " 이(가) " << amount << " 체력을 회복했습니다!" << endl;
}

void Character::GainExp(int amount)
{
	// 경험치 증가
	Exp += amount;

	cout << amount << " 만큼 경험치를 획득하였습니다!" << endl;

	// 경험치가 100 이상인 동안 반복
	while (Exp >= 100)
	{
		// 레벨업에 사용한 경험치 차감
		Exp -= 100;
		LevelUp();
	}
}

//PlayerStatus 출력
void Character::PlayerStatus()
{
	cout << "Name: " << Name << endl;
	cout << "Level: " << Level << endl;
	cout << "Exp: " << Exp << endl;
	cout << "HP: " << Health << endl;
	cout << "Power: " << Power << endl;
	cout << "Gold: " << Gold << endl;
}