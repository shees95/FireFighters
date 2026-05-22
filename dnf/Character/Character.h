#pragma once
#include <string>
#include "../Interface/Actor.h"

using namespace std;

class Monster;

class Character : public Actor
{
private:
	static Character* Instance; //싱글톤 패턴을 위한 정적 멤버 변수

	//멤버 변수
	string Name;
	int Level;
	int MaxHealth;
	int Health;
	int Power;
	int Exp;
	int Gold;

	Character(); //생성자 (private으로 선언하여 외부에서 인스턴스 생성을 막음)

public:
	static Character* GetInstance(); //싱글톤 인스턴스 반환

	//멤버 함수
	void TakeDamage(int damage);
	void Heal(int amount);
	void GainExp(int amount);
	void LevelUp();
	
	//Getter
	string GetStatus();
	string GetName() const;
	int GetLevel() { return Level; }
	int GetMaxHealth() const;
	int GetHealth() const;
	int GetPower() const;

	//Setter
	void SetName(const string& Name);
	void SetLevel(int Level);
	void SetMaxHealth(int MaxHealth);
	void SetHealth(int Health);
	void SetPower(int Power);

	void PlayerStatus();
	void TakeDamage(int Damage);
	virtual void Attack(Monster* monster);
	virtual ~Character();

};
