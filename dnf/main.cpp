// main.cpp

#include "GameManager/GameManager.h"

int main(void)
{
	GameManager GM;

	GM.StartGame();

	GM.Basecamp();

	Character::DestroyInstance();

    return 0;
}
