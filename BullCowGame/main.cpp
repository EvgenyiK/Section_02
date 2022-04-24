#include <iostream>
#include <string>


using namespace std;


void PlayGame();

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



//The entry point for our application
int main() 
{

	PrintIntro();
	PlayGame();
	return 0;
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
