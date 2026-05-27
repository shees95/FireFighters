#include <iostream>
#include "Battle.h"

#include "GameLog.h"
#include "../GameManager/GameManager.h"
#include "../Character/Character.h"
#include "../Monster/Monster.h"
#include "../Item/Item.h"
#include "../Interface/Util.h"

// GameLog GameManager::GameLog;

Battle::Battle(Character* InChr, Monster* InMst)
    : Chr(InChr), Mst(InMst)
{
    
}

Battle::~Battle()
{
    delete Chr; 
    delete Mst;
}

void Battle::StartBattle()
{
    GameManager::GL.ClearBattleLog();
    
    // 전투 시작
    std::cout << "\n\n";
    std::cout << Mst->GetName() << " (이)가 나타났다!";
    std::cout << "\n\n";
    
    SetIsOnBattle(true);
    
    // 전투 루프
    while (GetIsOnBattle())
    {
        PlayerTurn();
        std::cout << "\n\n";
        
        if (Mst->GetHealth() <= 0)
        {
            PlayerVictory();
            GiveReward();
            GameManager::GL.LogMonsterKill(Mst->GetName());
            
            SetIsOnBattle(false);   // 전투 종료
            std::cout << "\n\n";
            break;
        }
        
        MonsterTurn();
        if (Chr->GetHealth() <= 0)
        {
            MonsterVictory();
            
            SetIsOnBattle(false);   // 전투 종료
            std::cout << "\n\n";
            break;
        }
        
        std::cout << "\n\n";
        
    }
}

void Battle::PlayerTurn()
{
    std::cout << "플레이어 턴!" << std::endl;
    std::cout << "1. 공격 2. 방어 3. 아이템 사용 0. 도망" << std::endl;
    switch (Util::SelectorInt(0, 3))
    {
    case 0:
        MonsterVictory();
        break;
        
    case 1:
        Chr->Attack(Mst);
        break;
        
    case 2:
        std::cout << "방어는 구현 안했지롱\n턴은 넘어갔다!\n" << std::endl;
        break;
        
    case 3:
        Chr->GetInventory().PrintInventory();
        
        Chr->UseRandomItem();
        break;
        
    default:
        std::cout << "이 UI는 버그 UI 입니다.\n" << std::endl;
        break;
    }
}

void Battle::MonsterTurn()
{
    Mst->Attack(*Chr);
}

void Battle::PlayerVictory()
{
    std::cout << "★★★ 플레이어 승리! ★★★" << std::endl;
}

void Battle::MonsterVictory()
{
    std::cout << "* 패배 *" << std::endl;
}

void Battle::GiveReward()
{
    Chr->GetInventory().AddItem(Mst->GetDropItem());
}

int Battle::Selector(int min, int max)
{
    int selection = -1;
    
    while (selection < min || selection > max)
    {
        std::cout << "선택하세요 : ";
        std::cin >> selection;
        
    }
    std::cout << "\n\n";
    
    return selection;
}
