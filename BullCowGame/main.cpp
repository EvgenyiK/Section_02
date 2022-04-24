#include <iostream>
#include <string>
#include "FBullCowGame.h"


std::string GetGues();
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
	//loop for the number of turns asking for guesses
	
	int MaxTries = BCgame.GetMaxTries();
	
	for (int i = 1; i <= MaxTries; i++)
	{
		std::string st = GetGues();
		std::cout << "Your guess was: " << st << std::endl;
		std::cout << std::endl;
	}
}
// introduce the game
void PrintIntro()
{
	constexpr int WORD_LENGHT = 9;
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << WORD_LENGHT;
	std::cout << " letter isogram I,m thinking of?\n";
	std::cout << std::endl;
	return;
}


std::string GetGues()
{
	//get a guess from the player
	int CurrentTry = BCgame.GetCurrentTry();
	
	std::cout << "Try: " << CurrentTry << ". Enter you guess: ";
	std::string Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}


bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n) ?";
	std::string Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}
