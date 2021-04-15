#include "SudokuFitness.h"

/*
Constructor for SudokuFitness
*/
SudokuFitness::SudokuFitness()
{
}

/*
Pure virtual method override that calculate the fitness of a given
puzzle
@parameter puzzle: The puzzle that's fitness is being calculated
@return a double value representing the fitness
*/
double SudokuFitness::howFit(Puzzle& puzzle)
{
	double fitness = 0;
	Sudoku* SudokuPuzzle = dynamic_cast<Sudoku*> (&puzzle);
	vector<vector<int>> SudokuVector = SudokuPuzzle->getSudoku();
	fitness = FitnessHelper(SudokuVector);
	return fitness;
}

/*
A helper method that is used to calculate the fitness of a Sudoku Puzzle
@paramater SudokuPuzzle: A vector representation of the SudokuPuzzle thats
fitness is being calculated
@return a double value representing the fitness of the Sudoku Puzzle
*/
double SudokuFitness::FitnessHelper(vector<vector<int>> SudokuPuzzle)
{
	double fitness = 0;

	//vector used to check for duplicates in row, column or 3x3 block
	vector<int> CheckDuplicates;
	set<int> sudokuValues;

	//Loop that calculates the fitness of each row in the sudoku puzzle.
	//The fitness of each row is added to the total fitness of the puzzle
	for (int row = 0; row < 9; row++)
	{
		for (int column = 0; column < 9; column++)
		{
			CheckDuplicates.push_back(SudokuPuzzle[row][column]);
		}
		sort(CheckDuplicates.begin(), CheckDuplicates.end());
		int initValue = CheckDuplicates[0];
		fitness += CalculateFitness(CheckDuplicates);
		CheckDuplicates.clear();
	}

	//Loop that calculates the fitness of each column in the sudoku puzzle.
	//The fitness of each row is added to the total fitness of the puzzle
	for (int row = 0; row < 9; row++)
	{
		for (int column = 0; column < 9; column++)
		{
			CheckDuplicates.push_back(SudokuPuzzle[column][row]);
		}
		sort(CheckDuplicates.begin(), CheckDuplicates.end());
		fitness += CalculateFitness(CheckDuplicates);
		CheckDuplicates.clear();
	}

	//Loop that calculates the fitness of each 3x3 block in the sudoku puzzle.
	//The fitness of each row is added to the total fitness of the puzzle
	for (int row = 0; row < 9; row++)
	{
		for (int column = 0; column < 9; column++)
		{
			int rowIndex = (row / 3) * 3 + column / 3;
			int columnIndex = (row * 3 % 9 + column % 3);
			CheckDuplicates.push_back(SudokuPuzzle[rowIndex][columnIndex]);
		}
		sort(CheckDuplicates.begin(), CheckDuplicates.end());
		fitness += CalculateFitness(CheckDuplicates);
		CheckDuplicates.clear();
	}

	//The total fitness value is subtracted from 243, and then the result is divided
	//by 243. Gives a value between 0 and 1, where a result of 0 is a solved sudoku
	//puzzle
	return (243 - fitness) / 243;
	
}

/*
A helper method that is used to calculate the fitness of a row, column, or
3x3 block
@parameter SodukoValues: A vector of ints representing the values of each node
in the row, column, or 3x3 block
@return An integer value representing the fitness of a row.
*/
int SudokuFitness::CalculateFitness(vector<int> SudokuValues)
{
	int fitness = 9;
	int initValue = SudokuValues[0];
	
	//Loops through the vector representing a row, column or 3x3 block.
	//If a duplicate number is found, reduces the fitness value for each
	//duplicate found
	for (int i = 1; i <= 8; i++)
	{
		if (initValue == SudokuValues[i])
		{
			fitness--;
		}
		initValue = SudokuValues[i];
	}
	return fitness;
}
