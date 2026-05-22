// GameManager.cpp

#include "GameManager.h"

using namespace std;

Character GameManager::CreateCharacter(string name)
{
	Player.SetName(name);
	return Player;
}

Monster GameManager::SpawnMonster(int CharacterLevel)
{
	if (CharacterLevel == 10) // 10렙이면 보스 몬스터 등장
	{
		cout << "이제 일반 몬스터는 상대도 안 된다!" << "\n";
		return Monster::SpawnBossMonster(CharacterLevel);
	}
	else
	{
		return Monster::SpawnRandomMonster(CharacterLevel);
	}
}

Shop GameManager::EnterShop()
{

}

List GameManager::DisplayLog()
{

}

void GameManager::StartGame()
{
	// 인트로 로그 출력
	cout << "===========================================" << "\n";
	cout << "[ Text-Console RPG ]" << "\n";
	cout << "===========================================" << "\n";

	// 이름 입력 받기
	string name;
	cout << "캐릭터 이름을 입력하세요. : ";
	cin >> name;
	cout << "\n";

	// 캐릭터 생성
	CreateCharacter(name);

	// 스탯 출력
	Player.PrintStatus();
}

void GameManager::Basecamp()
{
	while (true)
	{
		cout << "=== 베이스캠프 ===" << "\n";
		cout << "1. 던전 입장" << "\n";
		cout << "2. 인벤토리 확인" << "\n";
		cout << "3. 상점 입장" << "\n";
		cout << "0. 게임 종료" << "\n";
		cout << "선택 : ";
		int choose;
		cin >> choose;
		cout << "\n";

		switch (choose)
		{
		case 1: // 던전 입장
			Monster monster = SpawnMonster(Player.GetLevel());
			// 전투 시작
			CurrentBattle = Battle(Player, monster);
			CurrentBattle.StartBattle();
			break;

		case 2: // 인벤토리 확인
			// 인벤토리 출력 함수 호출

			break;

		case 3: // 상점 입장 (도전 과제)

		case 0: // 게임 종료
			return; // MainMenu 함수 종료

		default:
			cout << "유효하지 않은 입력입니다. 올바른 번호를 입력하세요.";
			break;
		}
	}
}

//int main()
//{
//	GameManager GM;
//
//	GM.StartGame();
//  
//	GM.Basecamp();
//
//	return 0;
//}