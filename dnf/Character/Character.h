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

	~Character(); //소멸자

	//멤버 함수
	void Heal(int amount);
	void GainExp(int amount);
	void LevelUp();
	void Attack(Monster* monster); //공격함수
	void TakeDamage(int damage);
	void PlayerStatus(); //캐릭터 상태 출력 함수
	bool IsDead() const; //상태 확인 함수

public:
	//Getter, Setter 생성
	string GetName() const { return Name; }
	void SetName(string Name) { this->Name = Name; }

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

private:
	static Character* Instance; //싱글톤 패턴을 위한 정적 멤버 변수

	Character(); //외부에서 호출 못 하도록 private 생성자 선언

	//멤버 변수
	string Name;
	int Level;
	int MaxHealth;
	int Health;
	int Power;
	int tmpPower; //일시적으로 증가한 공격력을 저장하는 변수
	int Exp;
	int Gold;

};
