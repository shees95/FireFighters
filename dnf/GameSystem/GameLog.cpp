#include <iostream>

#include "GameLog.h"
#include "../Character/Character.h"
#include "../Monster/Monster.h"
#include "../Item/Item.h"

using std::cout;
using std::endl;
using std::string;

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
    string name = MonsterRef.GetName(); // 클래스 함수명 아직 안 맞음
    MonsterSpawnCount[name]++; // 몬스터별 스폰 횟수 누적

    cout << " [" << name << "] 등장 (누적 스폰: " << MonsterSpawnCount[name] << "회)" << endl;
}


// 실시간 전투 로그 시스템


void GameLog::LogPlayerAttack(string MonsterName, int Damage) // 플레이어가 공격했을 때
{
    // 전체 누적 데이터
    CharacterAttackCount++;       // 총 공격 횟수
    TotalDealtDamage += Damage;   // 누적 가한 데미지

    // 배틀 화면용 카운터 누적
    CurrentBattleAttackCount++;
    CurrentBattleDealtDamage += Damage;

    // 지정 포맷으로 실시간 배출
    cout << MonsterName << " 조우 | 총 공격: " << CurrentBattleAttackCount
        << "회 | 가한 총 데미지: " << CurrentBattleDealtDamage << endl;
}

// 플레이어가 피격당했을 때
void GameLog::LogPlayerDamaged(string MonsterName, int Damage)
{
    // 전체 누적 데이터
    TotalReceivedDamage += Damage; // 누적 입은 피해량

    // 배틀 화면용 카운터 누적
    CurrentBattleReceiveCount++;
    CurrentBattleReceiveDamage += Damage;

    // 지정 포맷으로 실시간 배출
    cout << MonsterName << " 조우 | 총 피격: " << CurrentBattleReceiveCount
        << "회 | 입은 총 피해량: " << CurrentBattleReceiveDamage << endl;
}





// 아이템 사용 기록 및 카운트 누적
void GameLog::LogItemUse(const Item& ItemRef)
{
    string name = ItemRef.GetName(); // 클래스 함수명 아직 안맞음
    ItemUseCount[name]++; // 각 아이템 사용 횟수 누적

    cout << "[아이템] " << name << " 사용 (누적 사용: " << ItemUseCount[name] << "회)" << endl;
}

// 처치 몬스터 누적 및 결과 배출
void GameLog::LogMonsterKill(string MonsterName)
{
    MonsterKills[MonsterName]++; // 잡은 몬스터 누적

    // 어떤 몬스터를 총 몇 마리 잡았는지 결과만 배출
    cout << MonsterName << " 처치 | 누적 처치 수: " << MonsterKills[MonsterName] << "마리" << endl;
}


// 메뉴 이동 시 실시간 출력 및 주머니 누적
void GameLog::LogSceneChange(string Location)
{
    cout << "[이동] -> " << Location << endl; // 즉시 화면 배출

    VisitedLocations.push_back(Location); // 플레이어 이동 경로 저장
}

// 이동 경로 쌓인 것 한눈에 보여주기
void GameLog::PrintVisitedLog()
{
    cout << "\n----------- [플레이어 이동 경로 히스토리] -----------" << endl;
    if (VisitedLocations.empty())
    {
        cout << ">> 이동 기록이 존재하지 않습니다." << endl;
    }
    else
    {
        for (size_t i = 0; i < VisitedLocations.size(); ++i)
        {
            // 1부터 차례대로 배출
            cout << "  [" << i + 1 << "] " << VisitedLocations[i] << endl;
        }
    }
    cout << "-----------------------------------------------------" << endl;
}