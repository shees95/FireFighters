#pragma once
#include "../Interface/Actor.h"
#include <string>

class Monster;
class Inventory;
class Item;

class Character : public Actor
{
public:
	// 싱글톤 관리 함수
	static Character* GetInstance(); //싱글톤 인스턴스 반환
	static void DestroyInstance(); //싱글톤 인스턴스 소멸

	//멤버 함수
	void Heal(int amount);
	void GainExp(int amount);
	void LevelUp();
	void Attack(Monster* monster); //공격 함수
	void TakeDamage(int damage);
	void PlayerStatus(); //상태 출력 함수
	bool IsDead() const; //상대 확인 함수
	void UseItem(Item* item); //아이템 사용 함수

	~Character(); //소멸자

public:
	//Getter, Setter 생성
	std::string GetName() const { return Name; }
	void SetName(std::string Name) { this->Name = Name; }

	int GetHealth() const { return Health; }
	void SetHealth(int Health) { this->Health = Health; }

	int GetPower() const { return Power; }
	void SetPower(int Power) { this->Power = Power; }

	int GetLevel() const { return Level; }
	void SetLevel(int Level) { this->Level = Level; }

	int GetExp() const { return Exp; }
	void SetExp(int Exp) { this->Exp = Exp; }

	int GetGold() const { return Gold; }
	void SetGold(int Gold) { this->Gold = Gold; }

	int GetMaxHealth() const { return MaxHealth; }

	Inventory* GetInventory() const { return Inventory; } //인벤토리 포인터 반환

private:
	static Character* Instance; //싱글톤 패턴을 위한 정적 멤버 변수

	Character(); //외부에서 호출 못 하도록 private 생성자 선언

	//멤버 변수
	std::string Name;
	int Level;
	int MaxHealth;
	int Health;
	int Power;
	int TmpPower; //일시적으로 증가한 공격력을 저장하는 변수
	int Exp;
	int Gold;
	Inventory* Inventory; //인벤토리 포인터
};