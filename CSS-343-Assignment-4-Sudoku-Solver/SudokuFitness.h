#include <vector>
#include <set>
#include <algorithm>
#include "Fitness.h"
#include "Sudoku.h"
#pragma once

class SudokuFitness : public Fitness
{
public:
	/*
	Constructor for SudokuFitness
	*/
	SudokuFitness();

	/*
	Pure virtual method override that calculate the fitness of a given
	puzzle
	@parameter puzzle: The puzzle that's fitness is being calculated
	@return a double value representing the fitness
	*/
	double howFit(Puzzle& puzzle);

private:
	/*
	A helper method that is used to calculate the fitness of a Sudoku Puzzle
	@paramater SudokuPuzzle: A vector representation of the SudokuPuzzle thats
	fitness is being calculated
	@return a double value representing the fitness of the Sudoku Puzzle
	*/
	double FitnessHelper(vector<vector<int>> SudokuPuzzle);

	/*
	A helper method that is used to calculate the fitness of a row, column, or
	3x3 block
	@parameter SodukoValues: A vector of ints representing the values of each node
	in the row, column, or 3x3 block
	@return An integer value representing the fitness of a row. 
	*/
	int CalculateFitness(vector<int> SudokuValues);
};

