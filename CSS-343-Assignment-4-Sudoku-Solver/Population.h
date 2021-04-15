#include "Fitness.h"
#include "PuzzleFactory.h"
#pragma once
class Population
{
public:
	/*
	Constructor for population
	*/
	Population();

	/*
	Deconstructor for population
	*/
	virtual ~Population();

	/*
	Pure virtual method that returns the best fitness of a population
	of puzzles
	@returns a double value representing the best fitness
	*/
	virtual double bestFitness() = 0;

	/*
	Pure virtual method that returns the best puzzle from a population
	of puzzles
	@returns the best puzzle from the population
	*/
	virtual Puzzle& bestIndividual() = 0;

	/*
	Pure virtual method that creates a new generation of puzzles from the
	best 10% of puzzles in the population
	*/
	virtual void newGeneration() = 0;

	/*
	Pure virtual method that removes the worst 90% of puzzles in the population
	*/
	virtual void cullPopulation() = 0;

protected:
	int popSize;
	Fitness* fitness;
	PuzzleFactory* theFactory;
	Reproduction* reproduction;
	Puzzle* initPuzzle;
	vector<Puzzle*> puzzleList;
};

