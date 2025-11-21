#include <iostream>
#include <conio.h>

#include "TicTacToe.h"

// Tommy Yang
// Assignemnt 6 - TickTacToe 

using namespace std;

TicTacToe::TicTacToe() // constructor - wasn't sure how to initalize the board so i just did it in my header
{
	m_playerTurn = 0; // starts on player 1's turn. 0 = Player 1 // 1 = Player 2.
}

void TicTacToe::Display() const
{
	system("cls");
	cout << "TicTacToe Game.\n";
	
	// displays the TicTacToe Board
	cout << // prints out row one
		" " << m_board[0] <<
		" | " << m_board[1] <<
		" | " << m_board[2] << "\n";
	cout << "---------\n";
	cout << // prints out row two
		" " << m_board[3] <<
		" | " << m_board[4] <<
		" | " << m_board[5] << "\n";
	cout << "---------\n";
	cout << // prints out row three
		" " << m_board[6] <<
		" | " << m_board[7] <<
		" | " << m_board[8] << "\n";
	if (m_playerTurn == 0)
		cout << "\n" << "Player 1's turn \n" << "\n";
	else
		cout << "\n"  << "Player 2's turn \n" << "\n";

}


void TicTacToe::TakeTurn()
{
	int boardPosition; // position on the board
	char playerMark; // position player wants to place their mark.
	

	if (m_playerTurn == 0)
	{
		playerMark = 'X';
		cout << "Player 1 pick a position (Enter 1-9): ";
	}
	else
	{
		playerMark = 'O';
		cout << "Player 2 pick a position (Enter 1-9): ";
	}

	bool valid = false;

	while (!valid)
	{
		cin >> boardPosition;

		int positionIndex = boardPosition - 1; // variable for player position. -1 for indexing. 

		if (boardPosition < 1 || boardPosition > 9)
		{
			cout << "Please enter in a valid board position (1-9): ";
		}

		else if (m_board[positionIndex] == 'X' || m_board[positionIndex] == 'O')
		{
			cout << "This spot has been taken. Please enter another positions: ";
		}
		else 
		{
			valid = true;

			m_board[positionIndex] = playerMark;
		}
	}
	m_playerTurn = 1 - m_playerTurn;

}

bool TicTacToe:: IsGameOver() const
{
	int Winner; // Variable to find the winner if there is one. 

	// winning board (0,1,2) row 1
	if (m_board[0] == m_board[1] && m_board[1] == m_board[2] && (m_board[0] == 'X' || (m_board[0] == 'O'))) 
	{
		if (m_board[0] == 'X')
			Winner = 1;
		else
			Winner = 2;
		cout << "Player " << Winner << " is the winner!\n";
		return true;
	}

	// winning board (3,4,5) row 2
	if (m_board[3] == m_board[4] && m_board[4] == m_board[5] && (m_board[3] == 'X' || (m_board[3] == 'O')))
	{
		if (m_board[3] == 'X')
			Winner = 1;
		else
			Winner = 2;
		cout << "Player " << Winner << " is the winner!\n";
		return true;
	}

	// winning board (6,7,8) row 3
	if (m_board[6] == m_board[7] && m_board[7] == m_board[8] && (m_board[6] == 'X' || (m_board[6] == 'O'))) 
	{
		if (m_board[6] == 'X')
			Winner = 1;
		else
			Winner = 2;
		cout << "Player " << Winner << " is the winner!\n";
		return true;
	}

	// winning board (0,3,6) column 1
	if (m_board[0] == m_board[3] && m_board[3] == m_board[6] && (m_board[0] == 'X' || (m_board[0] == 'O'))) 
	{
		if (m_board[0] == 'X')
			Winner = 1;
		else
			Winner = 2;
		cout << "Player " << Winner << " is the winner!\n";
		return true;
	}

	// winning board (1,4,7) column 2
	if (m_board[1] == m_board[4] && m_board[4] == m_board[7] && (m_board[1] == 'X' || (m_board[1] == 'O'))) 
	{
		if (m_board[1] == 'X')
			Winner = 1;
		else
			Winner = 2;
		cout << "Player " << Winner << " is the winner!\n";
		return true;
	}

	// winning board (2,5,8) column 3
	if (m_board[2] == m_board[5] && m_board[5] == m_board[8] && (m_board[2] == 'X' || (m_board[2] == 'O'))) 
	{
		if (m_board[2] == 'X')
			Winner = 1;
		else
			Winner = 2;
		cout << "Player " << Winner << " is the winner!\n";
		return true;
	}

	// winning board (0,4,8) diaogonal 1
	if (m_board[0] == m_board[4] && m_board[4] == m_board[8] && (m_board[0] == 'X' || (m_board[0] == 'O'))) 
	{
		if (m_board[0] == 'X')
			Winner = 1;
		else
			Winner = 2;
		cout << "Player " << Winner << " is the winner!\n";
		return true;
	}

	// winning board (2,4,6) diaogonal 2
	if (m_board[2] == m_board[4] && m_board[4] == m_board[6] && (m_board[2] == 'X' || (m_board[2] == 'O'))) 
	{
		if (m_board[2] == 'X')
			Winner = 1;
		else
			Winner = 2;
		cout << "Player " << Winner << " is the winner!\n";
		return true;
	}
	
	// checks to see if the game is a tie.
	for (int i = 0; i < 9; i++)
	{
		if (m_board[i] != 'X' && m_board[i] != 'O')
			return false;
	}
	cout << "The game has tied! \n";
	return true;
}
