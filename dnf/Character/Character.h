#pragma once
#include <string>
#include <iostream>
#include "../Interface/Actor.h"

class Monster;

class Character : public Actor
{
protected:
	static Character* Instance; //싱글톤 패턴을 위한 정적 멤버 변수

	//멤버 변수
	std::string Name;
	int Level;
	int MaxHealth;
	int Health;
	int Power;
	int Exp;
	int Gold;

	Character(); //외부에서 호출 못 하도록 private 생성자 선언

public:
	static Character* GetInstance(); //싱글톤 인스턴스 반환

	//멤버 함수
	void TakeDamage(int damage);
	void Heal(int amount);
	void GainExp(int amount);
	void LevelUp();
	
	//Getter

	std::string GetName() const;
	int GetLevel() const { return Level; }
	int GetMaxHealth() const;
	int GetHealth() const;
	int GetPower() const;

	bool IsDead() const;

	//Setter

	void SetHealth(int Health);
	void SetGold(int Gold) { this->Gold = Gold; }
	void SetLevel(int Level) { this->Level = Level; }
	void SetPower(int Power) { this->Power = Power; }
	void SetName(string Name) { this->Name = Name; }

	void PlayerStatus();

	virtual void Attack(Monster* monster);
	virtual ~Character();

};
