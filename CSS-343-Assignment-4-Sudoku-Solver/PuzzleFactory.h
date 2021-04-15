#include "Puzzle.h"
#include "Reproduction.h"
#pragma once
class PuzzleFactory
{
public:
	/*
	Constructor for PuzzleFactory
	@parameter r: The reproduction object used to create new puzzles in 
	the factory
	*/
	PuzzleFactory(Reproduction& r);

	/*
	Destructor for PuzzleFactory
	*/
	virtual ~PuzzleFactory();

	/*
	Virtual method that is used to create puzzles in the factory
	@parameter Puzzle: The puzzle that is used to create offspring from
	@return a pointer to the new puzzle containing the updated values
	*/
	virtual Puzzle* createPuzzle(Puzzle& Puzzle);

private:
	Reproduction* reproduction;
};

