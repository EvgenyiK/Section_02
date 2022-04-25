#pragma once
#include <string>

using FString = std::string;
using int32 = int;


// all values initialized to zero
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};


enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Lenght,
	Not_Lowercase
};


class FBullCowGame 
{
public:
	FBullCowGame();

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLenght() const;

	bool IsGameWon() const;
	void Reset(); // TODO make a more rich return value.
	EGuessStatus CheckGuessValidity(FString) const;
	FBullCowCount SubmitValidGuess(FString);

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};
