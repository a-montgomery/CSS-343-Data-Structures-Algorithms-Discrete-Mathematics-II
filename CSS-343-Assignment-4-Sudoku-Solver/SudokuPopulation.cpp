#include <algorithm>
#include <vector>
#include "SudokuPopulation.h"
#include "SudokuFitness.h"
#include "SudokuOffspring.h"
#include "SudokuFactory.h"
#include "Sudoku.h"

/*
Constructor for sudoku population
@parameter puzzle: The initial puzzle to base the poplation off of
@parameter size: The size of the population
*/
SudokuPopulation::SudokuPopulation(Puzzle& puzzle, int size)
{
	popSize = size;
	*initPuzzle = puzzle;
	reproduction = new SudokuOffspring();
	theFactory = new SudokuFactory(*reproduction);
	fitness = new SudokuFitness();
	//Create the initial generation of puzzles for the population
	puzzleList = makeInitGeneration(&puzzle, size);
}

/*
Destructor for sudoku population
*/
SudokuPopulation::~SudokuPopulation()
{
	delete reproduction;
	delete fitness;
	delete theFactory;
	for (int i = 0; i < puzzleList.size(); i++)
	{
		delete puzzleList[i];
	}

}

/*
Method to print a generation of sudoku puzzles (primarily used for
testing purposes)
@parameter SudokuPuzzles: A vector of puzzle pointers that contains
all of the puzzles in the population
*/
void SudokuPopulation::PrintInitGeneration(vector<Puzzle*> SudokuPuzzles)
{
	cout << endl;
	for (int i = 0; i < SudokuPuzzles.size(); i++)
	{

		cout << *SudokuPuzzles[i] << endl;

	}
}

/*
Method that returns the vector containing the puzzle pointers
for all of the puzzles in the population
@return A vector of puzzle pointers
*/
vector<Puzzle*> SudokuPopulation::getPuzzleList()
{
	return puzzleList;
}

/*
Pure virtual method override that calculates the best fitness out of
all the puzzles in the given population
@return a double value representing the best fitness from the population
*/
double SudokuPopulation::bestFitness()
{
	double bestFitness = fitness->howFit(*puzzleList[0]);
	for (int i = 1; i < popSize; i++)
	{
		double newFitness = fitness->howFit(*puzzleList[i]);
		//if the new fitness is less than (better) than the previous best
		//fitness, update best fitness
		if (newFitness < bestFitness)
		{
			bestFitness = newFitness;
		}
	}
	return bestFitness;
}

/*
Pure virtual method override that returns the best Sudoku Puzzle from the
population based on the best fitness
@return The best puzzle from the population
*/
Puzzle& SudokuPopulation::bestIndividual()
{
	double bestFitness = fitness->howFit(*puzzleList[0]);
	Puzzle* bestPuzzle = puzzleList[0];
	for (int i = 1; i < popSize; i++)
	{
		double newFitness = fitness->howFit(*puzzleList[i]);
		//if the new fitness is less than (better) than the previous best
		//fitness, update best fitness and the bestPuzzle to the new puzzle
		if (newFitness < bestFitness)
		{
			bestFitness = newFitness;
			bestPuzzle = puzzleList[i];
		}
	}
	return *bestPuzzle;
}

/*
Pure virtual method override that creates a new generation of sudoku puzzles
based on the best 10% of puzzles from the current population. Uses puzzle
fitness to determine the best 10%.
*/
void SudokuPopulation::newGeneration()
{
	int count = 0;
	int puzzleCount = 0;
	//Sudoku* newPuzzle = new Sudoku();
	//Create a new generation, loop counts until 90% of the population
	//has been refilled (10% is left from previous generation)
	for (int i = 0; i < (popSize * 9) / 10; i++)
	{
		Puzzle* puzzle = theFactory->createPuzzle(*puzzleList[puzzleCount]);
		Sudoku* newPuzzle = dynamic_cast<Sudoku*> (puzzle);
		//Calculate and set the fitness value of the new puzzles
		//each time a new puzzle is created
		double fitnessValue = fitness->howFit(*newPuzzle);
		newPuzzle->setFitness(fitnessValue);
		puzzleList.push_back(newPuzzle);
		puzzleCount++;
		count++;
		if (puzzleCount > (popSize *.1 - 1))
		{
			puzzleCount = 0;
		}
	}
}


/*
Pure virtual method override that removes the worst 90% of puzzles from the
current population using puzzle fitness.
*/
void SudokuPopulation::cullPopulation()
{
	int fitnessCount = 0;
	int count = 0;
	int size = popSize;
	vector<double> puzzleFitness;
	//Loop through the puzzle list, calculate the fitness of each puzzle, and
	//add all of the unique fitnesses to a vector
	for (int i = 0; i < popSize; i++)
	{
		puzzleFitness.push_back(fitness->howFit(*puzzleList[i]));
		fitnessCount++;
	}

	//Sort the vector of unique fitnesses and set the cull mark to
	//the best 10% of fitnesses. Any fitness above the 10% mark
	//will be removed from the population
	sort(puzzleFitness.begin(), puzzleFitness.end());

	double cullFitnessValue = puzzleFitness[popSize *.1 - 1];
	//sort(puzzList.begin(), puzzleList.end());

	//Loop through the puzzle list and delete any puzzle's that have a fitness
	//greater than the cullFitnessValue
	for (int i = 0; i < size; i++)
	{
		if (fitness->howFit(*puzzleList[i]) > cullFitnessValue)
		{
			delete puzzleList[i];
			puzzleList.erase(puzzleList.begin() + i);
			i--;
			size--;
			count++;
		}
	}
	int i = 0;

	//If the count of culled puzzles is less than 90% of the population size
	//then there is duplicate puzzles with a fitness value equal to the 
	//cullFitnessValue. Remove duplicate puzzles until 90% of the population
	//has been culled.
	while (count < (popSize * 9) / 10)
	{
		if (count == (popSize * 9) / 10)
		{
			break;
		}
		if (fitness->howFit(*puzzleList[i]) == cullFitnessValue)
		{
			delete puzzleList[i];
			puzzleList.erase(puzzleList.begin() + i);
			i--;
			size--;
			count++;
		}
		i++;
	}	
}

/*
Method that creates the initial generation of sudoku puzzles based on the puzzle
inputted in the parameter
@parameter puzzle: A pointer to the initial puzzle to base the population off of
@parameter size: The size of the population
@return a vector of puzzle pointers containing all of the sudoku puzzles in the
initial generation
*/
vector<Puzzle*> SudokuPopulation::makeInitGeneration(Puzzle* puzzle, int size)
{
	vector<Puzzle*> PuzzleList;
	Puzzle* initPuzzle = puzzle;
	Sudoku* SudokuPuzzle = dynamic_cast<Sudoku*> (initPuzzle);
	vector<vector<int>> SudokuVector = SudokuPuzzle->getSudoku();
	Sudoku* newPuzzle = new Sudoku();
	int count = 0;
	while (count < size)
	{
		for (int row = 0; row < 9; row++)
		{
			for (int column = 0; column < 9; column++)
			{
				bool set = SudokuPuzzle->isSet(row, column);
				
				//If the node at [row][column] in the sudoku puzzle is set, don't change
				//the value. If the node at [row][column] in the sudoku puzzle is not set,
				//pick a random number between 1 and 9 and insert the value into the node.
				if (set)
				{
					newPuzzle->insertNode(SudokuVector[row][column], set, row, column);
				}
				else
				{
					int value = (rand() % 9) + 1;
					newPuzzle->insertNode(value, set, row, column);
				}
			}
		}
		//Set the fitness value of each puzzle as each new puzzle is created
		double fitnessValue = fitness->howFit(*newPuzzle);
		newPuzzle->setFitness(fitnessValue);
		count++;
		PuzzleList.push_back(newPuzzle);
		newPuzzle = new Sudoku();
	}
	delete newPuzzle;
	return PuzzleList;
}

