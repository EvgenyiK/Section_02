/* This is console executable, that makes
* use of the BullCow class. This act as the 
* view in a MVC pattern, and is responsible 
* for all user interaction. For game logic see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

FText GetGues();
void PrintIntro();
void PlayGame();
bool AskToPlayAgain();

FBullCowGame BCgame; //initiate a new game



//The entry point for our application
int main() 
{
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);
	
	
	return 0;
}



void PlayGame()
{
	BCgame.Reset();
	int32 MaxTries = BCgame.GetMaxTries();
	//loop for the number of turns asking for guesses
	// TODO change from FOR to WHILE loop once we are validating tries
	for (int32 i = 1; i <= MaxTries; i++)
	{
		FText st = GetGues(); // TODO make loop checking valid

		// submit valid guess to the game
		FBullCowCount BullCowCount  =  BCgame.SubmitGuess(st);
		// print number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;

		std::cout << std::endl;
	}

	// TODO summarise game
}
// introduce the game
void PrintIntro()
{
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << BCgame.GetHiddenWordLenght();
	std::cout << " letter isogram I,m thinking of?\n";
	std::cout << std::endl;
	return;
}


FText GetGues()
{
	//get a guess from the player
	int32 CurrentTry = BCgame.GetCurrentTry();
	
	std::cout << "Try: " << CurrentTry << ". Enter you guess: ";
	FText Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}


bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n) ?";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}
