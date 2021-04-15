#include "Puzzle.h"
#include <vector>
#pragma once
class Reproduction
{
public:
	/*
	Constructor for Reproduction
	*/
	Reproduction();

	/*
	Destructor for Reproduction
	*/
	virtual ~Reproduction();

	/*
	Pure virtual method that is used to create a new puzzle from an existing
	puzzle
	@parameter puzzle: The original puzzled the offspring is based on
	@return A pointer to a puzzle that contains the updated values
	*/
	virtual Puzzle* makeOffspring(Puzzle& puzzle) = 0;

};

