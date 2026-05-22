#pragma once

#include "GameManager/Actor.h"

class Player;

class Monster : public Actor
{
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
	static Monster SpawnRandomMonster(int PlayerLevel);

public:
	static Monster SpawnBossMonster(int PlayerLevel);

public:
	static int GetRandomValue(int Min, int Max);

public:
	void Attack(Player& Player);

public:
	void TakeDamage(Player& Player);

protected:
	string Name;
	int Health;
	int Power;
};
