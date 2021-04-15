#include <iostream>
#include "Puzzle.h"
#pragma once
using namespace std;

class Fitness
{
public:
	/*
	Constructor for fitness
	*/
	Fitness();

	/*
	Pure virtual method that calculates the fitness of a puzzle
	@parameter thePuzzle: The puzzle that's fitness is being calculated
	@return a double value representing the fitness
	*/
	virtual double howFit(Puzzle& thePuzzle) = 0;
};

