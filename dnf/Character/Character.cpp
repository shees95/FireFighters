#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "Character.h"
#include "../Monster/Monster.h"
#include "../Item/Inventory.h"
#include "../Item/Item.h"

//싱글톤 패턴을 위한 멤버 변수 초기화
Character* Character::Instance = nullptr;

//생성자
	Character::Character()
		: Name(), Level(1), MaxHealth(200), Health(200), Power(30), TmpPower(0), Exp(0), Gold(0)
	{}

//소멸자
	Character::~Character() 
	{}

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

	//싱글톤 객체 소멸
	void Character::DestroyInstance()
	{
		delete Instance;
		Instance = nullptr;
	}

	//Attack 함수 구현
	void Character::Attack(Monster* monster)
	{
		cout << Name << "이(가) " << monster->GetName() << "을 공격합니다!" << endl;
		monster->TakeDamage(GetTotalPower());

		if (monster->GetHealth() <= 0)
		{
			ResetTmpPower();
		}
	}


//Damage를 입는 함수
void Character::TakeDamage(int damage)
{
	cout << Name << " 이(가) " << damage << " 데미지를 입었습니다!" << endl;

	SetHealth(max(GetHealth() - damage, 0));
	
	cout << Name << "체력: " << GetHealth() << " / " << GetMaxHealth() << endl;

	if (IsDead())
	{
		ResetTmpPower(); //전투 종료 후 일시적으로 증가한 공격력 초기화
	}
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

	// 레벨업 조건을 만족하는 동안 레벨업 반복
	while (Level < 10 && Exp >= 100)
	{
		// 레벨업에 사용한 경험치 차감
		Exp -= 100;

		// 레벨업
		LevelUp();
	}
}

void Character::LevelUp()
{
		Level++; //레벨 증가
		MaxHealth += (Level * 20); //최대 체력 증가
		Power += (Level * 5); //공격력 증가
		Health = MaxHealth; //체력 회복

		cout << "축하합니다! 레벨업 하였습니다!" << endl;
		cout << "현재 레벨: " << Level << endl;
		cout << "최대 체력: " << MaxHealth << endl;
		cout << "공격력: " << Power << endl;

	if (Level == 10)
	{
		cout << "\n최대 레벨(10)에 도달했습니다." << endl;
		cout << "(이후 획득하는 경험치는 계속 누적 됩니다.)" << endl;
	}
}

bool Character::IsDead() const
{
	return Health <= 0;
}

//Lv.1 John (exp 25/100)
// HP: 100 / 100   Power : 25
// Gold: 00G
void Character::PlayerStatus()
{
	cout << "Lv." << Level << " " << Name << " (exp " << Exp << "/100)" << endl;
	cout << "HP: " << Health << " / " << MaxHealth << "   Power: " << GetTotalPower() << endl;
	cout << "Gold: " << Gold << "G" << endl;
}

void Character::AddItem(Item item)
{
	Inven.AddItem(item);
}

void Character::DisplayItems()
{
	Inven.PrintInventory();
}

void Character::UseRandomItem()
{
	Inven.UseRandomItem(this);
}

void Character::ResetTmpPower()
{
		cout << "일시적으로 증가한 공격력이 초기화됩니다." << endl;
		TmpPower = 0;
}