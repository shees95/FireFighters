#pragma once
#include "../Interface/Actor.h"
#include "../Item/Item.h"

#include <string>



class Character;

class Monster : public Actor
{
protected:
	std::string Name;
	int Health;
	int MaxHealth;
	int Power;
	
private:
	Item DropItem;

public:
	Monster(std::string Name, int Health, int Power, Item DropItem);

public:
	//getter,Setter 생성
	std::string GetName() { return Name; }
	void SetName(std::string Name) { this->Name = Name; }

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
	void Attack(Character* Character);
	void TakeDamage(Character* Character);
	void MonsterStatus();

};
