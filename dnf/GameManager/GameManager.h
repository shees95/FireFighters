// GameManager.h

#pragma once

#include <iostream>
#include <string>
#include "../Character/Character.h"
#include "../GameSystem/Battle.h"
#include "../GameSystem/GameLog.h"
#include "../Interface/Actor.h"
#include "../Item/Item.h"
#include "../Monster/Monster.h"

using namespace std;

class GameManager
{
private:
    Character Player;
    Battle CurrentBattle;
    GameLog GameLog;
    Shop Shop;

public:
    void StartGame();
    Character CreateCharacter(string name);
    Monster SpawnMonster(int CharacterLevel);
    Shop EnterShop();
    List DisplayLog();
    void Basecamp();
};
