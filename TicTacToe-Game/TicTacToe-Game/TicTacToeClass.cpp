#include "TicTacToeClass.h"

TicTacToe::TicTacToe()
{
	int asciiNum = 48;
	player = 1;
	choice = 0;

	for (int i = 0; i < tableSize; i++) // initilaze entire table as {'1','2', ... ,'9'}
	{
		table[i] = asciiNum;
		asciiNum++;
	}
}

TicTacToe::~TicTacToe()
{
	//destructor
}

void TicTacToe::SetPlayer(int playerNum)
{
	if (playerNum == 1 || playerNum == 2) // check if player number is valid
	{
		player = playerNum;
	}
	else // if it is not valid display message, and don't change current player number
	{
		cout << "   >> You can only select 'Player 1' or 'Player 2' !!! " << endl;
	}
}

int TicTacToe::GetPlayer()
{
	return player;
}

void TicTacToe::SetChoice(void)
{
	int userChoice;

	cout << " Please enter your choice: ";

	cin >> userChoice;
	cin.ignore();

	if (userChoice > 0 && userChoice < 10) // check if user input is valid
	{
		choice = userChoice;
	}
	else // if it is not, display message and set choice to 0
	{
		cout << "   >> You can only select between 1-9 !!! " << endl;
		choice = 0;
	}
}

int TicTacToe::GetChoice(void)
{
	return choice;
}

int TicTacToe::HandleInput(void)
{
	int retVal; // return value from game status
	char symbol; // in this case 'X' or 'O'
	int userChoice;
	bool sleep = false;

	if (GetPlayer() == 1)
	{
		symbol = 'X'; // set symbol for player 1
	}
	else
	{
		symbol = 'O'; // set symbol for player 2
	}

	cout << "Player " << GetPlayer() << " -";

	SetChoice();
	userChoice = GetChoice();

	switch (userChoice) // check if choice (move) is valid and process
	{
	case 1:
		if (GetTable(1) == '1')
		{
			SetTable(1, symbol);
		}
		else
		{
			cout << "	>> This move is invalid !!! It's your opponent's turn. " << endl;
			sleep = true;
		}
		break;
	case 2:
		if (GetTable(2) == '2')
		{
			SetTable(2, symbol);
		}
		else
		{
			cout << "	>> This move is invalid !!! It's your opponent's turn. " << endl;
			sleep = true;
		}
		break;
	case 3:
		if (GetTable(3) == '3')
		{
			SetTable(3, symbol);
		}
		else
		{
			cout << "	>> This move is invalid !!! It's your opponent's turn. " << endl;
			sleep = true;
		}
		break;
	case 4:
		if (GetTable(4) == '4')
		{
			SetTable(4, symbol);
		}
		else
		{
			cout << "	>> This move is invalid !!! It's your opponent's turn. " << endl;
			sleep = true;
		}
		break;
	case 5:
		if (GetTable(5) == '5')
		{
			SetTable(5, symbol);
		}
		else
		{
			cout << "	>> This move is invalid !!! It's your opponent's turn. " << endl;
			sleep = true;
		}
		break;
	case 6:
		if (GetTable(6) == '6')
		{
			SetTable(6, symbol);
		}
		else
		{
			cout << "	>> This move is invalid !!! It's your opponent's turn. " << endl;
			sleep = true;
		}
		break;
	case 7:
		if (GetTable(7) == '7')
		{
			SetTable(7, symbol);
		}
		else
		{
			cout << "	>> This move is invalid !!! It's your opponent's turn. " << endl;
			sleep = true;
		}
		break;
	case 8:
		if (GetTable(8) == '8')
		{
			SetTable(8, symbol);
		}
		else
		{
			cout << "	>> This move is invalid !!! It's your opponent's turn. " << endl;
			sleep = true;
		}
		break;
	case 9:
		if (GetTable(9) == '9')
		{
			SetTable(9, symbol);
		}
		else
		{
			cout << "	>> This move is invalid !!! It's your opponent's turn. " << endl;
			sleep = true;
		}
		break;
	default:
		cout << "	>> This move is invalid !!! It's your opponent's turn. " << endl;
		sleep = true;
		break;
	}
	
	if (sleep == true) // sleep for 2 seconds to show error messages on screen before clear it from screen.
	{
		this_thread::sleep_for(chrono::seconds(2));
		sleep = false;
	}

	retVal = GetGameStatus();

	if (retVal == 2) // if game is in progress, change player every time because 1 player can have only single move after opponent moves.
	{
		if (GetPlayer() == 1)
		{
			SetPlayer(2);
		}
		else
		{
			SetPlayer(1);
		}
	}

	return retVal;
}

int TicTacToe::GetGameStatus(void)
{
	if (GetTable(1) == GetTable(2) && GetTable(2) == GetTable(3) || // 
		GetTable(4) == GetTable(5) && GetTable(5) == GetTable(6) || // All possible sequences to win. (Horizontal)
		GetTable(7) == GetTable(8) && GetTable(8) == GetTable(9) || //

		GetTable(1) == GetTable(4) && GetTable(4) == GetTable(7) || //
		GetTable(2) == GetTable(5) && GetTable(5) == GetTable(8) || // All possible sequences to win. (Vertical)
		GetTable(3) == GetTable(6) && GetTable(6) == GetTable(9) || //

		GetTable(1) == GetTable(5) && GetTable(5) == GetTable(9) || // All possible sequences to win. (Cross)
		GetTable(3) == GetTable(5) && GetTable(5) == GetTable(7) )  //
	{
		return 1; // return 1 if game is over, and somone win
	}

	else if (GetTable(1) != '1' && GetTable(2) != '2' && GetTable(3) != '3' &&  //
			GetTable(4) != '4' && GetTable(5) != '5' && GetTable(6) != '6' &&   // All movements are already made and there is no possible move 
			GetTable(7) != '7' && GetTable(8) != '8' && GetTable(9) != '9')		//
	{
		return 0; // return 0 if game is over, but no one wins (there is no available move anymore)
	}

	else
	{
		return 2; // return 2 if game is in progress
	}
}

void TicTacToe::Draw()
{
	system("cls"); // clear screen
	cout << "\n\n\tTic Tac Toe Game\n\n";

	cout << "Player 1 (X)  -  Player 2 (O)" << endl;
	cout << endl;

	cout << "     ||     ||     " << endl;
	cout << "  " << table[1] << "  ||  " << table[2] << "  ||  " << table[3] << endl;

	cout << "=====||=====||=====" << endl;
	cout << "     ||     ||     " << endl;

	cout << "  " << table[4] << "  ||  " << table[5] << "  ||  " << table[6] << endl;

	cout << "=====||=====||=====" << endl;
	cout << "     ||     ||     " << endl;

	cout << "  " << table[7] << "  ||  " << table[8] << "  ||  " << table[9] << endl;

	cout << "     ||     ||     " << endl << endl;
}

void TicTacToe::SetTable(int tableIndex, char replaceChar)
{
	if (tableIndex > 0 && tableIndex < 10) // check if index number is valid and replace specific character into that index
	{
		table[tableIndex] = replaceChar;
	}
	else // if it is not, display message
	{
		cout << "   >> You can only set table elements between 1-9 !!!" << endl;
	}
}

char TicTacToe::GetTable(int tableIndex)
{
	if (tableIndex > 0 && tableIndex < 10) // check if index number is valid and return character that is into that index
	{
		return table[tableIndex];
	}
	else // if it is not, display message
	{
		cout << "   >> you can only get table elements between 1-9 !!!" << endl;
		return table[0];
	}
}
