#include "SudokuFactory.h"

/*
Constructor for the SudokuFactory
@parameter r: The reproduction object used to create new puzzles
*/
SudokuFactory::SudokuFactory(Reproduction& r) : PuzzleFactory(r)
{
}

/*
Virtual method override to create new puzzles in the SudokuFactory
@parameter Puzzle: The original puzzle used to create puzzles from
@return A pointer to the new puzzle with the updated values
*/
Puzzle* SudokuFactory::createPuzzle(Puzzle& Puzzle)
{
	return PuzzleFactory::createPuzzle(Puzzle);
}
