#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#include "Character.h"
#include "../Monster/Monster.h"

//싱글톤 패턴을 위한 멤버 변수 초기화
Character* Character::Instance = nullptr;

//생성자
	Character::Character()
		: Name(Name), 
		Level(1), 
		MaxHealth(200), 
		Health(200), 
		Power(30), 
		Exp(0), 
		Gold(0)
	{}

	Character::~Character() {}

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

	//Attack 함수 구현
	void Character::Attack(Monster* monster)
	{
		cout << Name << "이(가) " << monster->GetName() << "을 공격합니다!" << endl;
		monster->TakeDamage(*this);
	}

//Damage를 입는 함수
void Character::TakeDamage(int damage)
{
	cout << Name << " 이(가) " << damage << " 데미지를 입었습니다!" << endl;

	SetHealth(max(GetHealth() - damage, 0));
	
	cout << Name << "체력: " << GetHealth() << endl;
}

void Character::Heal(int amount)
{
	cout << GetName() << " 이(가) " << amount << " 체력을 회복했습니다!" << endl;

	SetHealth(min(GetHealth() + amount, GetMaxHealth()));

	cout << GetName() << "체력: " << GetHealth() << endl;
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

void Character::LevelUp()
{
	//만렙설정
	if (Level >= 10)
	{
		cout << "최대 레벨(10) 입니다. 더 이상 레벨업 할 수 없습니다." << endl;
		return;
	}

	Level++; //레벨 증가
	MaxHealth += (Level * 20); //최대 체력 증가
	Power += (Level * 5); //공격력 증가
	Health = MaxHealth; //체력 회복
	cout << "축하합니다! 레벨업 하였습니다!" << endl;
	cout << "현재 레벨: " << Level << endl;
	cout << "최대 체력: " << MaxHealth << endl;
	cout << "공격력: " << Power << endl;
}

bool Character::IsDead() const
{
	return Health <= 0;
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