#include <iostream>
#include <string>
#include "Game.h"

int main()
{
	std::unique_ptr<Game> myGame = std::make_unique<Game>();

	while (myGame->IsGameEnded() == false)
	{
		myGame->PlayLevel();
	}

	return 0;
}