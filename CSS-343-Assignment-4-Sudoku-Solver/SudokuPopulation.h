#include "Population.h"
#pragma once

class SudokuPopulation : public Population
{

public:
	/*
	Constructor for sudoku population
	@parameter puzzle: The initial puzzle to base the poplation off of
	@parameter size: The size of the population
	*/
	SudokuPopulation(Puzzle& puzzle, int size);

	/*
	Destructor for sudoku population
	*/
	~SudokuPopulation();

	/*
	Method to print a generation of sudoku puzzles (primarily used for
	testing purposes)
	@parameter SudokuPuzzles: A vector of puzzle pointers that contains
	all of the puzzles in the population
	*/
	void PrintInitGeneration(vector<Puzzle*> SudokuPuzzles);

	/*
	Method that returns the vector containing the puzzle pointers
	for all of the puzzles in the population
	@return A vector of puzzle pointers
	*/
	vector<Puzzle*> getPuzzleList();

	/*
	Pure virtual method override that calculates the best fitness out of
	all the puzzles in the given population
	@return a double value representing the best fitness from the population
	*/
	double bestFitness();

	/*
	Pure virtual method override that returns the best Sudoku Puzzle from the
	population based on the best fitness
	@return The best puzzle from the population
	*/
	Puzzle& bestIndividual();

	/*
	Pure virtual method override that creates a new generation of sudoku puzzles
	based on the best 10% of puzzles from the current population. Uses puzzle 
	fitness to determine the best 10%.
	*/
	void newGeneration();

	/*
	Pure virtual method override that removes the worst 90% of puzzles from the
	current population using puzzle fitness.
	*/
	void cullPopulation();

private:
	/*
	Method that creates the initial generation of sudoku puzzles based on the puzzle
	inputted in the parameter
	@parameter puzzle: A pointer to the initial puzzle to base the population off of
	@parameter size: The size of the population
	@return a vector of puzzle pointers containing all of the sudoku puzzles in the 
	initial generation
	*/
	vector<Puzzle*> makeInitGeneration(Puzzle* puzzle, int size);
};

