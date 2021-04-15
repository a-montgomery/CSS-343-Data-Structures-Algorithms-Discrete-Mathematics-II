#include "SudokuOffspring.h"

/*
Pure virtual method override that creates a new Sudoku Puzzle from
an existing sudoku puzzle
@parameter puzzle: The original that is used to create the offspring
@return a Pointer to a new puzzle with the updated values
*/
Puzzle* SudokuOffspring::makeOffspring(Puzzle& puzzle)
{
	Puzzle* ParentPuzzle = &puzzle;
	Sudoku* ParentSudoku = dynamic_cast<Sudoku*> (ParentPuzzle);
	vector<vector<int>> SudokuVector = ParentSudoku->getSudoku();

	Sudoku* newPuzzle = new Sudoku();

	int mutation = 0; //represents a random number

	for (int row = 0; row < 9; row++)
	{
		for (int column = 0; column < 9; column++)
		{
			mutation = rand() % 100 + 1; //generate random number between 1 and 100
			bool isSet = ParentSudoku->isSet(row, column);

			//If the mutation is less than or equal to 3, and the node is not set
			//change the value in the node
			if (mutation <= 3 && !isSet)
			{
				int value = (rand() % 9) + 1;
				newPuzzle->insertNode(value, isSet, row, column);
			}
			else
			{
				newPuzzle->insertNode(SudokuVector[row][column], isSet, row, column);
			}
		}
	}
	return newPuzzle;
}
