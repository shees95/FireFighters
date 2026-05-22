#pragma once
#include "../Interface/Actor.h"

class Monster;
class Character;

class Battle : public Actor
{
    Character* Chr;
    Monster* Mst;
    
    bool IsOnBattle = false;
public:
    Battle(Character& InChr, Monster& InMst);
    
    void SetIsOnBattle(bool InIsOnBattle) { IsOnBattle = InIsOnBattle; }
    bool GetIsOnBattle() { return IsOnBattle; }
    
    void StartBattle();
    
    void PlayerTurn();
    void MonsterTurn();
    
    void PlayerVictory();
    void MonsterVictory();
    
    void GiveReward();
    
    
    // UI
    int Selector(int min, int max);
    
};
