#include "Population.h"

/*
Constructor for population
*/
Population::Population()
{
	fitness = nullptr;
	theFactory = nullptr;
	initPuzzle = nullptr;
	reproduction = nullptr;
	popSize = 0;
}

/*
Deconstructor for population
*/
Population::~Population()
{
}
