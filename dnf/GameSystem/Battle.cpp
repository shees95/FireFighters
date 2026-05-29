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

void Battle::StartBattle()
{
    int selection = -1;
    
    GameManager::GL.ClearBattleLog();
    
    // 전투 시작
    std::cout << "\n\n";
    std::cout << Mst->GetName() << " (이)가 나타났다!";
    std::cout << "\n\n";
    
    SetIsOnBattle(true);
    
    // 전투 루프
    while (GetIsOnBattle())
    {
        selection = PlayerTurn();
        if (selection == 0)
        {
            MonsterVictory();
            
            SetIsOnBattle(false);
            std::cout << "\n\n";
            break;
        }
        // 스탯 확인
        if (selection == 2 || selection == 3) continue;
        
        std::cout << "\n\n";
        
        if (Mst->GetHealth() <= 0)
        {
            GameManager::GL.LogMonsterKill(Mst->GetName());
            PlayerVictory();
            Chr->GainExp(50);
            Chr->SetGold(Chr->GetGold() + rand() % 10 + 10);
            GiveReward();
            
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

    Chr->ResetTmpPower();
    GameManager::GL.ClearBattleLog();
}

int Battle::PlayerTurn()
{
    int selection = -1;
    std::cout << "플레이어 턴!" << std::endl;
    std::cout << "1. 공격\t2. 내 스탯 확인\t3. 몬스터 스탯 확인\t4. 아이템 사용\t0. 도망" << std::endl;
    switch (selection = Util::SelectorInt(0, 4))
    {
    case 0:
        break;
        
    case 1:
        GameManager::GL.LogPlayerAttack(Chr, Mst);
        Chr->Attack(Mst);
        break;
        
    case 2:
        Chr->PlayerStatus();
        break;
        
    case 3:
        Mst->MonsterStatus();
        break;
        
    case 4:
        Chr->GetInventory().PrintInventory();
        Chr->UseRandomItem();
        break;
        
    default:
        std::cout << "이 UI는 버그 UI 입니다.\n" << std::endl;
        break;
    }
    
    return selection;
}

void Battle::MonsterTurn()
{
    GameManager::GL.LogPlayerDamaged(Mst);
    Mst->Attack(Chr);
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
