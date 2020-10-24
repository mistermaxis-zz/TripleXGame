#pragma once
#include <ctime>
#include "StringMap.h"

class Game {
public:

	Game() {

		GameEnded = false;
		
		DifficultyMultiplier = 0;
		GameLevel = 1;
		NumberOfLevels = 10;
		NumberOfTries = 5;
		TriesPerLevel = 5;
		
		PlayerGuessA = 0; PlayerGuessB = 0; PlayerGuessC = 0; PlayerGuessSum = 0; PlayerGuessMul = 0;
		CodeNumberA = 0; CodeNumberB = 0; CodeNumberC = 0; CodeNumberSum = 0; CodeNumberMul = 0;
		
		GameMessages.Initialize();
	};
	void PlayLevel();
	
	unsigned short const& GetNumberOfTries() { return NumberOfTries; }
	unsigned short const& GetLevelNumber() { return GameLevel; }
	unsigned short const& GetNumberOfLevels() { return NumberOfLevels; }
	bool IsGameEnded() { return GameEnded; }

private:

	void IncreaseLevel() { ++GameLevel; DifficultyMultiplier = (GameLevel / 2) + 1; }
	void ResetTries() { NumberOfTries = TriesPerLevel; }
	void DecreaseNumberOfTries() { --NumberOfTries; }
	void DecreaseTriesPerLevel() { if (TriesPerLevel > 3) { --TriesPerLevel; } }
	
	void Randomize();
	
	void AddUpCodes() { CodeNumberSum = CodeNumberA + CodeNumberB + CodeNumberC; }
	void MultiplyCodes() { CodeNumberMul = CodeNumberA * CodeNumberB * CodeNumberC; }
	
	void AddUpGuesses() { PlayerGuessSum = PlayerGuessA + PlayerGuessB + PlayerGuessC; }
	void MultiplyGuesses() { PlayerGuessMul = PlayerGuessA * PlayerGuessB * PlayerGuessC; }
	
	bool GuessIsCorrect();

	unsigned short NumberOfTries;
	unsigned short DifficultyMultiplier;
	
	unsigned short PlayerGuessA;
	unsigned short PlayerGuessB;
	unsigned short PlayerGuessC;
	unsigned short PlayerGuessSum;
	unsigned short PlayerGuessMul;

	unsigned short CodeNumberA;
	unsigned short CodeNumberB;
	unsigned short CodeNumberC;
	unsigned short CodeNumberSum;
	unsigned short CodeNumberMul;
	
	unsigned short GameLevel;
	unsigned short TriesPerLevel;
	unsigned short NumberOfLevels;

	bool GameEnded;

	StringMap GameMessages;
};

void Game::PlayLevel() {

	if (GameLevel > NumberOfLevels)
	{
		GameEnded = true;
		GameMessages.DisplayMessage(StringKeys::WIN);
		return;
	}

	Randomize();
	AddUpCodes();
	MultiplyCodes();
	
	GameMessages.DisplayMessage(GameLevel);
	GameMessages.DisplayMessage(StringKeys::TRIES_LEFT, NumberOfTries);
	GameMessages.DisplayMessage(StringKeys::LEVEL_TEXT);
	GameMessages.DisplayMessage(StringKeys::SUM_TEXT, CodeNumberSum);
	GameMessages.DisplayMessage(StringKeys::MUL_TEXT, CodeNumberMul);
	std::cin >> PlayerGuessA >> PlayerGuessB >> PlayerGuessC;

	AddUpGuesses(); MultiplyGuesses();

	if (GuessIsCorrect())
	{
		GameMessages.DisplayMessage(StringKeys::LEVEL_COMPLETE);
		IncreaseLevel();
		ResetTries();
		if (GameLevel % 3 == 0)
		{
			DecreaseTriesPerLevel();
		}
		std::cin.clear();
		std::cin.ignore();
		std::cin.get();
	}
	else {
		DecreaseNumberOfTries();
		if (NumberOfTries == 0)
		{
			system("cls");
			GameMessages.DisplayMessage(StringKeys::LOSS);
			GameEnded = true;
		}
		else
		{
			GameMessages.DisplayMessage(StringKeys::TRY_AGAIN);
		}

		std::cin.clear();
		std::cin.ignore();
		std::cin.get();
	}
	system("cls");
}

void Game::Randomize()
{
	srand(time(NULL));
	CodeNumberA = 1 + (rand() % (DifficultyMultiplier + 3));
	CodeNumberB = 1 + (rand() % (DifficultyMultiplier + 3));
	CodeNumberC = 1 + (rand() % (DifficultyMultiplier + 3));
}

bool Game::GuessIsCorrect()
{
	if (CodeNumberSum == PlayerGuessSum && CodeNumberMul == PlayerGuessMul)
	{
		return true;
	}
	else {
		return false;
	}
}