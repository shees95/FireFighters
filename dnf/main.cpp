// main.cpp

#include "GameManager/GameManager.h"

int main(void)
{
	GameManager GM;

	GM.StartGame();

	GM.MainLoop();

	Character::DestroyInstance(); // Character 클래스에서 생성한 객체 메모리에서 해제

    return 0;
}
