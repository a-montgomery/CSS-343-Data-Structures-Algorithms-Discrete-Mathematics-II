#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#pragma once
class Puzzle
{
public:
	/*
	Default constructor for puzzle
	*/
	Puzzle();

	/*
	Destructor for Puzzle
	*/
	virtual ~Puzzle();

	/*
	Method that prints out the contents of a Puzzle
	@parameter theStream: the output stream that contains the puzzle
	@parameter puzzle: the Puzzle to be outputted
	@return an outstream containing the string representation of the puzzle
	*/
	friend ostream& operator<<(ostream& theStream, const Puzzle& puzzle)
	{
		puzzle.outputHelper(theStream);
		return theStream;
	}

	/*
	Method that is used to input the contents of a puzzle
	@parameter theStream: Input stream that contains puzzle information
	@paramter puzzle: The puzzle that will receive the input data
	@return the instream containing the puzzle information
	*/
	friend istream& operator>>(istream& theStream, Puzzle& puzzle)
	{
		puzzle.inputHelper(theStream);
		return theStream;
	}

	bool operator==(Puzzle& rhs)
	{
		return rhs.equalityHelper(&rhs);
	}

	/*
	Method that is overridden by derived classes to help output the
	contents of a puzzle
	@parameter theStream: outstream that contains the output information
	*/
	virtual void outputHelper(ostream& theStream) const = 0;

	/*
	Method that is overriden by derived class to help input the contents
	of a puzzle
	@parameter theStream: istream that contains the input information
	*/
	virtual void inputHelper(istream& theStream) = 0;

	virtual bool equalityHelper(Puzzle* puzzle) = 0;
};

