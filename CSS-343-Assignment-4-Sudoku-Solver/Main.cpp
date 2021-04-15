/*
/*
Andrew Montgomery
03/13/20
SID#: 1978495

The goal of this assignment is to solve sudoku puzzles using genetic 
algorithms. Sudoku puzzles are a 9-by-9 arrangement of squares, subdivided
into 3-by-3 groups. To solve a sudoku puzzle each row, column, and 3-by-3 
block must have digits 1-9, without any duplicates. The initial state of a 
sudoku puzzle has some numbers already filled in, these numbers are set and 
cannot be changed at any point during the puzzle. The difficulty of the 
puzzle can be increased/decreased based on the total set locations and where 
the locations occur in the puzzle. More difficult sudoku puzzles will have 
less spaces filled initially.

Genetic programming is a type of randomized algorithm.  Randomized algorithms 
use a non-deterministic approach to search for problem solutions, coupling 
randomness with a means for quickly eliminating possibilities that are likely 
to be inferior. While there are more deterministic methods for solving sudoku 
puzzles, the use of genetic algorithms in this assignment is to demonstrate an 
example of a general algorithm that can be implemented independently of the type 
of data operated on.

The general idea behind using genetic algorithms is that we generate possible 
solutions, in this case potential sudoku puzzle solutions, evaluate how good the 
solutions are, and then use that information to generate what are hopefully are 
better solutions.  This process is then repeated until either a solution is found, 
or a solution that is considered “good enough”.  In order to determine how “good” a 
puzzle solution is we can use the fitness of the puzzle. This is an algorithm 
designed to determine how close to the actual solution the one that was generated is. 
The way in which the fitness algorithm will be developed for this program will be to 
count the number of unique values in each row and column. If the number of unique 
values is 9, then the row/column/3x3 grid is unique, and if the number is less than 9. 
Then the row/column is not unique, and a fitness value can be assigned to the 
row/column/3x3 grid based upon the count of unique values. By adding up all the fitness 
values of each row, column, and 3x3 grid, a total fitness value for the sudoku solution 
can be determined.
*/


#include <iostream>
#include <string>
#include "Puzzle.h"
#include "Sudoku.h"
#include "Population.h"
#include "SudokuPopulation.h"

int main(int argc, char* argv[])
{
	//Check for correct number of command line arguments
	if (argc != 3)
	{
		cerr << "Wrong number of command line arguments." << endl;
		return -1;
	}

	Puzzle* a = new Sudoku();
	cin >> *a;
	cout << *a;


	Population* x = new SudokuPopulation(*a, atoi(argv[1]));

	double bestFitness = 1.0; //1.0 fitness is the worst fitness
	double bestCurrentFitness = x->bestFitness();
	int SolvedGeneration = 0;
	bool solved = false;
	int countGenerations = 0;
	int diagnosticInterval = (atoi(argv[2])) / 10;
	int count = 0;

	//Loop through genetic algorithm until max number of generations has been reached
	//or the solution is found
	for (int i = 1; i <= atoi(argv[2]); i++)
	{
		if (x->bestFitness() == 0)
		{
			solved = true;
			SolvedGeneration = i;
			cout << "Puzzle solution has been found" << endl;
			break;
		}
		x->cullPopulation();
		x->newGeneration();

		if (x->bestFitness() < bestFitness)
		{
			bestFitness = x->bestFitness();
		}
		count++;
		if (count == diagnosticInterval)
		{
			cout << "Generation: " << i << endl;
			count = 0;
			cout << x->bestIndividual();
			cout << "The fitness of the best puzzle so far is: " << bestFitness << endl;
		}
		
	}

	if (solved)
	{
		cout << "The solution for this sudoku puzzle is: " << endl;
		cout << x->bestIndividual();
		cout << endl;
		cout << "The solution was found in " << SolvedGeneration << " generations." << endl;
	}
	else
	{
		cout << "No solution was found for this sudoku puzzle" << endl;
		cout << "The best puzzle found was: " << endl;
		cout << x->bestIndividual();
		cout << "The fitness of the best puzzle was: " << bestFitness << endl;
	}
	delete a;
	delete x;
}
