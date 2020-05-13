#ifndef _TicTacToe_H
#define _TicTacToe_H

#pragma warning (disable:4996)

#include <thread> // I included this in order to use sleep function.
#include <chrono> // I included this in order to use sleep function.
#include <iostream>

#define tableSize 10 

using namespace std;

class TicTacToe
{
private:

	int player; // int variable to store player number (Player 1 or Player 2)
	int choice; // int variable to store choice (move) made by user
	char table[tableSize]; // this is our main board that we see on screen

public:

	TicTacToe(); // constructor
	~TicTacToe(); // destructor
	void SetPlayer(int playerNum); // set player to 1 or 2
	int GetPlayer(void); // return current player 
	void SetChoice(void); // set choice (move) between 1-9
	int GetChoice(void); // return current choice
	void Draw(void); // draw board and update it when changes are made
	int HandleInput(void); // handle user input and process, and returns current game status
	int GetGameStatus(void); // return current game status (return 0 if game is over and game draw, return 1 if someone wins, return 2 if game is in progress)
	void SetTable(int tableIndex, char replaceChar); // set specific element at board with specific character (in our case 'X' or 'O')
	char GetTable(int tableIndex); // return character at specific index of table 
};
#endif // !_TicTacToe_H