#include "FBullCowGame.h"


FBullCowGame::FBullCowGame(){ Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLenght() const { return MyHiddenWord.length(); }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	return;
}


bool FBullCowGame::IsGameWon() const
{
	return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false)
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false)
	{
		return EGuessStatus::Not_Lowercase;
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
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// incriment the turn number
	MyCurrentTry++;
	// setup a return variable
	FBullCowCount BullCowCount;
	

	// loop throught all letters in the guess
	int32 HiddenWordLenght = MyHiddenWord.length();

	for (int32 MHWChar = 0; MHWChar < HiddenWordLenght; MHWChar++)
	{
		for (int32 GChar = 0; GChar < HiddenWordLenght; GChar++)
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
	

	return BullCowCount;
}
