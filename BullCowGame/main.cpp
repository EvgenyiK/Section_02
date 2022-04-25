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

FText GetValidGues();
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
		FText Guess = GetValidGues(); // TODO make loop checking valid

		

		FBullCowCount BullCowCount  =  BCgame.SubmitGuess(Guess);
	
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
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


// loop continually until the user gives a valid guess
FText GetValidGues()
{	
	EGuessStatus Status = EGuessStatus::Invalid_Status;

	do {
		//get a guess from the player
		int32 CurrentTry = BCgame.GetCurrentTry();
		std::cout << "Try: " << CurrentTry << ". Enter you guess: ";
		FText Guess = "";
		std::getline(std::cin, Guess);

		Status = BCgame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word witout repeating letters. \n";
			break;
		case EGuessStatus::Wrong_Lenght:
			std::cout << "Please enter a " << BCgame.GetHiddenWordLenght() << " letter word. \n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters. \n";
			break;
		default:
			return Guess;;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK); // keep looping untill we get no errors
}


bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n) ?";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}
