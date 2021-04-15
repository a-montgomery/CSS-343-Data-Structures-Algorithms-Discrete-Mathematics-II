#include "Puzzle.h"
#include "Reproduction.h"
#include "PuzzleFactory.h"
#pragma once

class SudokuFactory : public PuzzleFactory
{
public:
	/*
	Constructor for the SudokuFactory
	@parameter r: The reproduction object used to create new puzzles
	*/
	SudokuFactory(Reproduction& r);

	/*
	Virtual method override to create new puzzles in the SudokuFactory
	@parameter Puzzle: The original puzzle used to create puzzles from
	@return A pointer to the new puzzle with the updated values
	*/
	Puzzle* createPuzzle(Puzzle& Puzzle);
};

