#pragma once
#include "Game.h"'

// Tommy Yang
// Assignemnt 6 - TickTacToe 

class TicTacToe : public Game
{
private:
	char m_board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'}; // TicTacToe game board - from instructions.
	int m_playerTurn; // interger to check the players turn.

public:
	TicTacToe();

	// Inherited methods from Game.
	virtual bool IsGameOver() const;
	virtual void TakeTurn();
	virtual void Display() const;

};
