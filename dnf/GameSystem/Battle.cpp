#include <iostream>
#include "Battle.h"
#include "../Character/Character.h"
#include "../Monster/Monster.h"
#include "../Item/Item.h"

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
    // 전투 시작
    std::cout << Mst->GetName() << " 가 나타났다!" << std::endl;
    SetIsOnBattle(true);
    
    // 전투 루프
    while (GetIsOnBattle())
    {
        PlayerTurn();
        if (Mst->GetHealth() <= 0)
        {
            PlayerVictory();
            GiveReward();
            
            SetIsOnBattle(false);   // 전투 종료
        }
        
        MonsterTurn();
        if (Chr->GetHealth() <= 0)
        {
            MonsterVictory();
            
            SetIsOnBattle(false);   // 전투 종료
        }
        
    }
}

void Battle::PlayerTurn()
{
    std::cout << "플레이어 턴!\n" << std::endl;
    std::cout << "1. 공격 2. 방어 3. 아이템 사용 0. 도망" << std::endl;
    switch (Selector(0, 3))
    {
    case 0:
        // Chr->Attack();
        break;
        
    case 1:
        
        break;
        
    case 2:
        
        break;
        
    case 3:
        MonsterVictory();
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
    std::cout << "★ 플레이어 승리! ★" << std::endl;
}

void Battle::MonsterVictory()
{
    std::cout << "* 패배 *" << std::endl;
}

void Battle::GiveReward()
{
    
}

int Battle::Selector(int min, int max)
{
    int selection = -1;
    
    while (selection < min || selection > max)
    {
        std::cout << "선택하세요 : ";
        std::cin >> selection;
        
    }
    
    return selection;
}
