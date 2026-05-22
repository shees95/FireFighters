#pragma once

#include "../Interface/Actor.h"

class Character;

class Monster : public Actor
{
protected:
	string Name;
	int Health;
	int Power;

public:
	Monster(string Name, int Health, int Power);

public:
	//getter,Setter 생성
	string GetName() { return Name; }
	void SetName(string Name) { this->Name = Name; }

	int GetHealth() { return Health; }
	void SetHealth(int Health) { this->Health = Health; }

	int GetPower() { return Power; }
	void SetPower(int Power) { this->Power = Power; }


public:
	static Monster SpawnRandomMonster(int CharacterLevel);

public:
	static Monster SpawnBossMonster(int CharacterLevel);

public:
	static int GetRandomValue(int Min, int Max);

public:
	void Attack(Character& Character);

public:
	void TakeDamage(Character& Character);


};
