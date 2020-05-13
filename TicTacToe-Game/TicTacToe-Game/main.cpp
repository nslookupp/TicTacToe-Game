#include <iostream>
#include "TicTacToeClass.h"

using namespace std;

int main(void)
{
	int test;
	int gameStatus; // variable to store return value that indicates current game status
	TicTacToe gameObj; // TicTacToe class instance (object)

	do
	{
		gameObj.Draw();
		gameStatus = gameObj.HandleInput();

	} while (gameStatus == 2); // loop until game is no longer in progress.

	gameObj.Draw();

	if (gameStatus == 1) // if someone wins, display message
	{
		cout << "	>> Congrats !!! Player " << gameObj.GetPlayer() << " wins the game. " << endl;
	}
	else // if game draw, display message
	{
		cout << "	>> Game draw !!! There is no winner for this game." << endl;
	}

	system("Pause");
	return 0;
}