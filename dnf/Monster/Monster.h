#pragma once

#include "Interface/Actor.h"

class Player;

class Monster : public Actor
{
protected:
	string Name;
	int Health;
	int Attack;

public:
	Monster(string Name, int Health, int Attack);

public:
	//getter,Setter 생성
	string GetName() { return Name; }
	void SetName(string Name) { this->Name = Name; }

	int GetHealth() { return Health; }
	void SetHealth(int Health) { this->Health = Health; }

	int GetPower() { return Attack; }
	void SetAttack(int Attack) { this->Attack = Attack; }


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


};
