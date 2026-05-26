#pragma once


#include "../Interface/Actor.h"
#include "../Item/Item.h"

class Character;

class Monster : public Actor
{
protected:
	string Name;
	int Health;
	int Power;
	
private:
	Item DropItem;

public:
	Monster(string Name, int Health, int Power, Item DropItem);

public:
	//getter,Setter 생성
	string GetName() { return Name; }
	void SetName(string Name) { this->Name = Name; }

	int GetHealth() { return Health; }
	void SetHealth(int Health) { this->Health = Health; }

	int GetPower() { return Power; }
	void SetPower(int Power) { this->Power = Power; }

	Item GetDropItem() { return DropItem; }

public:
	static Monster SpawnRandomMonster(int CharacterLevel);
	static Monster SpawnBossMonster(int CharacterLevel);

public:
	static int GetRandomValue(int Min, int Max);

public:
	void Attack(Character& Character);
	void TakeDamage(int Damage);


};
