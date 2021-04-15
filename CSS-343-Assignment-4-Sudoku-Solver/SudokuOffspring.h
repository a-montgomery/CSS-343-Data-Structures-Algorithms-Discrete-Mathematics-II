#include <random>
#include "Puzzle.h"
#include "Sudoku.h"
#include "Reproduction.h"
//#pragma once
class SudokuOffspring : public Reproduction
{
public:
	/*
	Pure virtual method override that creates a new Sudoku Puzzle from
	an existing sudoku puzzle
	@parameter puzzle: The original that is used to create the offspring
	@return a Pointer to a new puzzle with the updated values
	*/
	Puzzle* makeOffspring(Puzzle& puzzle);
};

