#pragma once
#include "../Interface/Actor.h"

class Monster;

class Character : public Actor
{
public:
	static Character* GetInstance(); //싱글톤 인스턴스 반환
	static void DestroyInstance(); //싱글톤 인스턴스 소멸

	//멤버 함수
	void TakeDamage(int damage);
	void Heal(int amount);
	void GainExp(int amount);
	void LevelUp();

	//Getter

	string GetName() const { return Name; }
	int GetLevel() const { return Level; }
	int GetMaxHealth() const { return MaxHealth; }
	int GetHealth() const { return Health; }
	int GetPower() const { return Power; }

	bool IsDead() const;

	//Setter

	void SetHealth(int Health) { this->Health = Health; }
	void SetGold(int Gold) { this->Gold = Gold; }
	void SetLevel(int Level) { this->Level = Level; }
	void SetPower(int Power) { this->Power = Power; }
	void SetName(string Name) { this->Name = Name; }

	void PlayerStatus();
	virtual void Attack(Monster* monster);
	virtual ~Character();

private:
	static Character* Instance; //싱글톤 패턴을 위한 정적 멤버 변수

	Character(); //외부에서 호출 못 하도록 private 생성자 선언

	//멤버 변수
	string Name;
	int Level;
	int MaxHealth;
	int Health;
	int Power;
	int Exp;
	int Gold;

};
