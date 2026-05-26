#pragma once

#include <string>
#include <vector>
#include <map> // 잡은 몬스터 기록을 위한 장부

class Character; // 전방선언
class Monster;
class Item;

class GameLog
{
public:
	GameLog(); // 생성자

	void ClearBattleLog(); // 새로운 배틀이 시작되면 화변에 카운터 변수를 0으로 초기화

	void LogCharacterSpawn(const Character& CharacterRef); // 플레이어 객채 받아오는 함수 (참조자)
	void LogMonsterSpawn(const Monster& MonsterRef); // 몬스터 객채 받아오는 함수 (참조자)

	void LogPlayerAttack(std::string MonsterName, int Damage); // 플레이어가 피해
	void LogPlayerDamaged(std::string MonsterName, int Damage); // 플레이어가 피격
	void LogItemUse(const Item& ItemRef); // 아이템 사용
	void LogMonsterKill(std::string MonsterName); // 처치 몬스터 누적

	void LogSceneChange(std::string Location); // 메뉴 이동 시 출력 
	void PrintVisitedLog(); // 이동 경로 쌓아서 보여줌




private:
	
	// 새로운 몬스터를 만나서 조우 할 때 마다 초기화 됨
	int CurrentBattleAttackCount; //이번 배틀에서 공격 횟수
	int CurrentBattleDealtDamage; //이번 배틀에서 내가 가한 누적 데미지
	int CurrentBattleReceiveCount; //이번 배틀에서 내가 입은 누적 피해량
	int CurrentBattleReceiveDamage; //이번 배틀에서 내가 입은 총 피해량

	int CharacterAttackCount;                       //  총 공격 횟수
	int TotalDealtDamage;                           //  누적 가한 데미지
	int TotalReceivedDamage;                        //  누적 입은 피해량
	std::map<std::string, int> MonsterKills;        //  잡은 몬스터 누적
	std::map<std::string, int> ItemUseCount;        //  각 아이템 사용 횟수
	std::map<std::string, int> MonsterSpawnCount;   //  몬스터 스폰 카운트

	std::vector<std::string> VisitedLocations; // 플레이어 이동 경로 저장




};
