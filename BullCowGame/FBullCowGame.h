#pragma once

class FBullCowGame {
public:
	void Reset();
	int GetMaxTries();
	int GetCurrentTry();
	bool IsGameWon();
	bool CheckGuessValidity();

private:
	int MyCurrentTry;
	int MyMaxTries;
};
