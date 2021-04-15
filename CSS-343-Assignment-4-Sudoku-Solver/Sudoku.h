#include <iostream>
#include <string>
#include <vector>	
#include <fstream>
#include "Puzzle.h"
using namespace std;
#pragma once
class Sudoku : public Puzzle
{
public:
	/*
	Default constructor for a Sudoku Puzzle
	*/
	Sudoku();

	/*
	Method that returns the vector representation of a Sudoku
	Puzzle
	@return a vector representing the sudoku puzzle
	*/
	vector<vector<int>> getSudoku();

	/*
	Method that returns the fitness value of the
	Sudoku Puzzle
	@return a double value representing the fitness 
	of the puzzle
	*/
	double getFitness() const;

	/*
	Method that changes the fitness value of the Sudoku puzzle
	@parameter value: The new fitness of the puzzle
	*/
	void setFitness(double value);

	/*
	Pure virtual method override that is used by the output overload
	to output a string represenetation of the Sudoku Puzzle
	@parameter theStream: the output stream the sudoku puzzle is sent to
	*/
	void outputHelper(ostream& theStream) const;

	/*
	Pure virtual method override that is used by the input overload
	to convert a string representing a sudoku puzzle to a sudoku
	puzzle
	@parameter theStream: The input stream that contains the string
	representation of the sudoku puzzle
	*/
	void inputHelper(istream& theStream);

	/*
	Pure virtual method override that is used by the equality operator
	overload to check if two sudoku puzzles are equal
	@parameter puzzle: The puzzle that is being checked against for equality
	@return A bool value representing equality, true if the sudoku puzzles are
	equal, otherwise false
	*/
	bool equalityHelper(Puzzle* puzzle);

	/*
	Pure virtual method override that is used to insert a node into the Sudoku
	Puzzle. A node represents a single value in the sudoku puzzle.
	@parameter value: The value of the node
	@parameter set: A bool value representing whether the number in the sudoku 
	puzzle can be changed. True if the value cannot be changed, otherwise false.
	@parameter row: The row to insert the node
	@parameter column: The column to insert the node
	@return A bool value representing whether the insert was successful or not
	True if the node was interserted, otherwise false
	*/
	bool  insertNode(int value, bool set, int row, int column);

	/*
	Pure virtual method override that is used to check if the value of a node in
	the sudoku puzzle is set or not
	@parameter row: The row where the node is located
	@parameter column: The column where the node is located
	@return a bool value representing whether the value of the node is set or not.
	True if the value is set, otherwise false
	*/
	bool isSet(int row, int column);

private:
	/*
	A struct that represents a node in the Sudoku Puzzle. Each node in the Sudoku
	Puzzle contains an integer value, and a bool that represents if the value in the
	node is set or not.
	*/
	struct SudokuPuzzleNode
	{
		int value;
		bool set;
	};

	SudokuPuzzleNode SudokuPuzzle[9][9];
	double fitness; //The fitness of the puzzle
};

