#pragma once
#include <map>

enum class StringKeys { WIN, LOSS, TRY_AGAIN, LEVEL_TITLE, LEVEL_TEXT, SUM_TEXT, MUL_TEXT, LEVEL_COMPLETE, TRIES_LEFT };

std::string Win = "\n\n***************  CONGRATULATIONS!!!  ***************\nYou passed all the levels and gained entrance to the mainframe\n\n";

std::string Loss = "You Got Caught!";
std::string TryAgain = "Wrong Password! Try Again!";
std::string LevelTitle = "This is Level Number ";
std::string TriesLeft = "Number of tries left: ";
std::string LevelText = "This code has 3 digits. ";
std::string SumText = "The sum of the 3 digits adds up to: ";
std::string MulText = "The multiplication of the 3 digits gives: ";
std::string LevelComplete = "You Completed The Level Succesfully!";

class StringMap {
public:
	StringMap() {}
	void Initialize();
	void DisplayMessage(StringKeys key);
	void DisplayMessage(unsigned short level);
	void DisplayMessage(StringKeys key, unsigned short value);
private:
	std::map<StringKeys, std::string> GameStrings;
};

void StringMap::Initialize()
{
	GameStrings.emplace(StringKeys::WIN, Win);
	GameStrings.emplace(StringKeys::LOSS, Loss);
	GameStrings.emplace(StringKeys::TRY_AGAIN, TryAgain);
	GameStrings.emplace(StringKeys::LEVEL_TITLE, LevelTitle);
	GameStrings.emplace(StringKeys::LEVEL_TEXT, LevelText);
	GameStrings.emplace(StringKeys::SUM_TEXT, SumText);
	GameStrings.emplace(StringKeys::MUL_TEXT, MulText);
	GameStrings.emplace(StringKeys::LEVEL_COMPLETE, LevelComplete);
	GameStrings.emplace(StringKeys::TRIES_LEFT, TriesLeft);
}

void StringMap::DisplayMessage(StringKeys key)
{
	std::cout << GameStrings[key] << "\n";
}

void StringMap::DisplayMessage(StringKeys key, unsigned short value)
{
	std::cout << GameStrings[key] << " " << value << "\n";
}

void StringMap::DisplayMessage(unsigned short level)
{
	std::cout << GameStrings[StringKeys::LEVEL_TITLE] << level << ".\n";
}