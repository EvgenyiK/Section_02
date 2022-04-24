#include <iostream>
#include <string>


using namespace std;

void PrintIntro();
void PlayGame();
bool AskToPlayAgain();





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


// introduce the game
void PrintIntro()
{
	constexpr int WORD_LENGHT = 9;
	cout << "Welcome to Bulls and Cows, a fun word game." << endl;
	cout << "Can you guess the " << WORD_LENGHT;
	cout << " letter isogram I,m thinking of?\n";
	cout << endl;
	return;
}


string GetGues()
{
	//get a guess from the player
	cout << "Enter you guess: ";
	string Guess = "";
	getline(cin, Guess);
	return Guess;
}


void PlayGame()
{
	//loop for the number of turns asking for guesses
	constexpr int NUMBER_OF_TURNS = 5;
	for (int i = 1; i <= NUMBER_OF_TURNS; i++)
	{
		string st = GetGues();
		cout << "Your guess was: " << st << endl;
		cout << endl;
	}
}

bool AskToPlayAgain()
{
	cout << "Do you want to play again (y/n) ?";
	string Response = "";
	getline(cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}
