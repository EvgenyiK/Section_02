#include "FBullCowGame.h"


FBullCowGame::FBullCowGame(){ Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLenght() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 3;
	const FString HIDDEN_WORD = "planet";

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}




EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false)
	{
		return EGuessStatus::Not_Isogram; //TODO write function
	}
	else if (false)
	{
		return EGuessStatus::Not_Lowercase; //TODO write function
	}
	else if (Guess.length() != GetHiddenWordLenght())
	{
		return EGuessStatus::Wrong_Lenght;
	}
	else
	{
		return EGuessStatus::OK;
	}
	
}

// receives a VALID guess, increments turn , and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{

	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLenght = MyHiddenWord.length();

	// loop throught all letters in the hidden word
	for (int32 MHWChar = 0; MHWChar < WordLenght; MHWChar++)
	{
		for (int32 GChar = 0; GChar < WordLenght; GChar++)
		{
			if (Guess[GChar] == MyHiddenWord[MHWChar])
			{
				if (MHWChar == GChar)
				{
					BullCowCount.Bulls++;
				}
				else
				{
					BullCowCount.Cows++;
				}
			}
		}
	}
	
	if (BullCowCount.Bulls == WordLenght)
	{
		bGameIsWon = true;
	}
	else 
	{
		bGameIsWon = false;
	}

	return BullCowCount;
}
