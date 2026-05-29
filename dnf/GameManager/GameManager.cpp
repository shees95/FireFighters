// GameManager.cpp

#include <iostream>

#include "GameManager.h"

GameLog GameManager::GL;

using namespace std;

// 생성자 - 포인터 nullptr로 초기화
GameManager::GameManager()
	: Player(nullptr), CurrentMonster(nullptr), CurrentBattle(nullptr)
{

}

// 소멸자 - 동적 할당 해제
GameManager::~GameManager()
{
	Player = nullptr;
	delete CurrentMonster;
	delete CurrentBattle;
}

Character* GameManager::CreateCharacter(string name)
{
	Player = Character::GetInstance(); // 싱글톤 패턴으로 멤버 변수 초기화
	Player->SetName(name);         // 이름만 따로 세팅
	
	return Player;
}

Monster* GameManager::SpawnMonster(int CharacterLevel)
{
	if (CharacterLevel == 10) // 10렙이면 보스 몬스터 등장
	{
		cout << "이제 일반 몬스터는 상대도 안 된다!" << "\n";
		CurrentMonster = new Monster(Monster::SpawnBossMonster(CharacterLevel));
	}
	else
	{
		CurrentMonster = new Monster(Monster::SpawnRandomMonster(CharacterLevel));
	}
	return CurrentMonster;
}

//Shop GameManager::EnterShop()
//{
//
//}

//List GameManager::DisplayLog()
//{
//
//}

void GameManager::StartGame()
{
	// 인트로 로그 출력
	cout << "===========================================" << "\n";
	cout << "[ Text-Console RPG ]" << "\n";
	cout << "===========================================" << "\n";

	// 유틸리티로 이름 입력
	string name = Util::SelectorString("캐릭터 이름을 입력하세요. : ");
	cout << "\n";

	// 캐릭터 생성
	CreateCharacter(name);

	// 스탯 출력
	Player->PlayerStatus();
}

void GameManager::MainLoop()
{
	while (true)
	{
		cout << "=== 베이스캠프 ===" << "\n";
		cout << "1. 던전 입장" << "\n";
		cout << "2. 스탯 확인" << "\n";
		cout << "3. 인벤토리 확인" << "\n";
		cout << "4. 상점 입장" << "\n";
		cout << "0. 게임 종료" << "\n";

		switch (Util::SelectorInt(0, 4))
		{
		case 1: // 던전 입장
		{
			system("cls");
			GameManager::GL.LogSceneChange("던전");
			// 전투 시작
			if (CurrentMonster) // 이전 몬스터 메모리 해제
			{
				delete CurrentMonster; 
				CurrentMonster = nullptr;
			}
			
			if (CurrentBattle) // 이전 전투 메모리 해제
			{
				delete CurrentBattle;  
				CurrentBattle = nullptr;
			}

			CurrentMonster = SpawnMonster(Player->GetLevel());
			GameManager::GL.LogMonsterSpawn(*CurrentMonster);
			CurrentBattle = new Battle(Player, CurrentMonster);
			CurrentBattle->StartBattle();
			break;
		}
		case 2: // 인벤토리 확인
			system("cls");
			Player->PlayerStatus();
			break;
			
		case 3: // 인벤토리 확인
			system("cls");
			GameManager::GL.LogSceneChange("인벤토리");
			Player->DisplayItems();
			break;

		case 4: // 상점 입장 (도전 과제)
			system("cls");
			GameManager::GL.LogSceneChange("상점");
			GameShop.OpenShop(*Player);
			break;

		case 0: // 게임 종료
			delete CurrentMonster; CurrentMonster = nullptr; // 이전 몬스터 메모리 해제
			delete CurrentBattle;  CurrentBattle = nullptr; // 이전 전투 메모리 해제
			
			GL.PrintVisitedLog();
			
			cout << "게임 종료" << "\n";
			return; // MainLoop 함수 종료

		default:
			cout << "유효하지 않은 입력입니다. 올바른 번호를 입력하세요.";
			break;
		}
	}
}
