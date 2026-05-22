// GameManager.h

#pragma once

#include <iostream>
#include <string>
#include "../Character/Character.h"
#include "../GameSystem/Battle.h"
#include "../GameSystem/GameLog.h"
#include "../Monster/Monster.h"

class GameManager
{
private:
    Character Player;
    Battle CurrentBattle;
    GameLog GameLog;
    // Shop Shop;

public:
    void StartGame();
    Character CreateCharacter(std::string name);
    Monster SpawnMonster(int CharacterLevel);
    // Shop EnterShop();
    // List DisplayLog();
    void Basecamp();
};
