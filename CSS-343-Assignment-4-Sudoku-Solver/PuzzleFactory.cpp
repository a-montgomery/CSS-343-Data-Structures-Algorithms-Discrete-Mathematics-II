#include "PuzzleFactory.h"

/*
Constructor for PuzzleFactory
@parameter r: The reproduction object used to create new puzzles in
the factory
*/
PuzzleFactory::PuzzleFactory(Reproduction& r)
{
	reproduction = &r;
}

/*
Destructor for PuzzleFactory
*/
PuzzleFactory::~PuzzleFactory()
{
}

/*
Virtual method that is used to create puzzles in the factory
@parameter Puzzle: The puzzle that is used to create offspring from
@return a pointer to the new puzzle containing the updated values
*/
Puzzle* PuzzleFactory::createPuzzle(Puzzle& Puzzle)
{
	return reproduction->makeOffspring(Puzzle);
}
