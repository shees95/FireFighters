#include <iostream>

#include "GameLog.h"
#include "../Character/Character.h"
#include "../Monster/Monster.h"
#include "../Item/Item.h"

GameLog::GameLog()
{
    CharacterAttackCount = 0;
    TotalDealtDamage = 0;
    TotalReceivedDamage = 0;

   
    ClearBattleLog(); // 배틀 카운트 초기화
}

void GameLog::ClearBattleLog()
{
    CurrentBattleAttackCount = 0;
    CurrentBattleDealtDamage = 0;
    CurrentBattleReceiveCount = 0;
    CurrentBattleReceiveDamage = 0;
}

void GameLog::LogCharacterSpawn(const Character& CharacterRef)
{
}

// 몬스터 스폰 기록 및 카운트 누적
void GameLog::LogMonsterSpawn(const Monster& MonsterRef)
{
    string name = MonsterRef.GetName();
    MonsterSpawnCount[name]++; // 몬스터별 스폰 횟수 누적

    cout << " [" << name << "] 등장 (누적 스폰: " << MonsterSpawnCount[name] << "회)" << endl;
}