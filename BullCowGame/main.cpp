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
void PrintGameSummary();
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
	while(!BCgame.IsGameWon() && BCgame.GetCurrentTry() <= MaxTries)
	{
		FText Guess = GetValidGues();
		FBullCowCount BullCowCount  =  BCgame.SubmitValidGuess(Guess);
	
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
	}

	PrintGameSummary();

	return;
}

// introduce the game
void PrintIntro()
{
	std::cout << "\n\n Welcome to Bulls and Cows, a fun word game." << std::endl;

	
	std::cout <<
		R"(
 .-=-.                .-=-.            .=     ,        =.
  `) )              ( (`      _  _   /'/    )\,/,/(_   \ \
 .' /                \ '.      `//-.|  (  ,\\)\//\)\/_  ) |
(  (   _.-'`::`'-._   )  )     //___\   `\\\/\\/\/\\///'  /
 \  `'`    .::.    `'`  /   ,-"~`-._ `"--'_   `"""`  _ \`'"~-,_
  `-._\`~`      `~`/_.-'    \       `-.  '_`.      .'_` \ ,-"~`/
 _,=` /            \ `=,_    `.__.-'`/   (-\        /-) |-.__,'
(    ,(^\        /^),    )     ||   |     \O)  /^\ (O/  |
 `~~` \0)\      /(0/ `~~`      `\\  |         /   `\    /
       | /`    '\ |              \\  \       /      `\ /
       |          |               `\\ `-.  /' .---.--.\
       |          |                 `\\/`~(, '()      ('
       |          |                  /(O) \\   _,.-.,_)
       /          \                 //  \\ `\'`      /
       \()      ()/               / |  ||   `""""~"`
        `._-==-_.'               /'  |__||
           `""`                        `o
           BULL           AND                 COW
                   A funny word game

)" << std::endl;

	std::cout << "Can you guess the " << BCgame.GetHiddenWordLenght();
	std::cout << " letter isogram I,m thinking of?\n";
	std::cout << std::endl;
	return;
} 


void PrintGameSummary()
{
		if (BCgame.IsGameWon())
		{
			std::cout << " WELL DONE - YOU WIN!\n";
		}
		else
		{
			std::cout << " Better luck next time!\n";
		}
	
	return;
}

// loop continually until the user gives a valid guess
FText GetValidGues()
{	
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;

	do {
		//get a guess from the player
		int32 CurrentTry = BCgame.GetCurrentTry();
		std::cout << "Try: " << CurrentTry << " of " << BCgame.GetMaxTries();
		std::cout << ". Enter your guess: ";
		std::getline(std::cin, Guess);

		Status = BCgame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word witout repeating letters. \n\n";
			break;
		case EGuessStatus::Wrong_Lenght:
			std::cout << "Please enter a " << BCgame.GetHiddenWordLenght() << " letter word. \n\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters. \n\n";
			break;
		default:
			// assume the guess is valid
			break;
		}
	} while (Status != EGuessStatus::OK); // keep looping untill we get no errors
	return Guess;
}


bool AskToPlayAgain()
{
	std::cout << "Do you want to play again with the same hidden word (y/n) ?";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}
