#include "Sudoku.h"

/*
Default constructor for a Sudoku Puzzle
*/
Sudoku::Sudoku()
{
	//Create 81 nodes to represent a Sudoku Puzzle and set each
	//node to a value of 0 and false for whether each node is set
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			SudokuPuzzleNode startingState = SudokuPuzzleNode();
			startingState.value = 0;
			startingState.set = false;
			SudokuPuzzle[i][j] = startingState;
		}
	}
	fitness = -1; //-1 represents the fitness of an empty sudoku puzzle
}

/*
Method that returns the vector representation of a Sudoku
Puzzle
@return a vector representing the sudoku puzzle
*/
vector<vector<int>> Sudoku::getSudoku()
{
	vector<vector<int>> puzzle(9, vector<int>(9));
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			puzzle[i][j] = SudokuPuzzle[i][j].value;
		}
	}
	return puzzle;
}

/*
Method that returns the fitness value of the
Sudoku Puzzle
@return a double value representing the fitness
of the puzzle
*/
double Sudoku::getFitness() const
{
	return fitness;
}


/*
Pure virtual method override that is used by the output overload
to output a string represenetation of the Sudoku Puzzle
@parameter theStream: the output stream the sudoku puzzle is sent to
*/
void Sudoku::outputHelper(ostream& theStream) const
{
	theStream << "+-------+-------+-------+" << endl;
	for (int i = 1; i <= 9; i++)
	{
		theStream << "| ";
		for (int j = 1; j <= 9; j++)
		{
			theStream << SudokuPuzzle[i-1][j-1].value << " ";
			if (j % 3 == 0)
			{
				theStream << "| ";
			}
		}
		theStream << endl;
		if (i % 3 == 0)
		{
			theStream << "+-------+-------+-------+" << endl;
		}
	}
}


/*
Pure virtual method override that is used by the input overload
to convert a string representing a sudoku puzzle to a sudoku
puzzle
@parameter theStream: The input stream that contains the string
representation of the sudoku puzzle
*/
void Sudoku::inputHelper(istream & theStream)
{
	
	bool foundAllValues = false;
	int count = 0;
	int column = 0;
	int row = 0;
	char value;

	while (!foundAllValues)
	{
		while (cin.get(value) && !cin.eof())
		{
			if (isdigit(value))
			{
				SudokuPuzzleNode node = SudokuPuzzleNode();
				node.value = value - '0';
				node.set = node.value != 0;
				SudokuPuzzle[row][column] = node;

				column++;
				count++;
			}
			if (column == 9)
			{
				column = 0;
				row++;
			}
			if (count == 81)
			{
				foundAllValues = true;
				break;
			}
		}
	}
	
}

/*
Pure virtual method override that is used by the equality operator
overload to check if two sudoku puzzles are equal
@parameter puzzle: The puzzle that is being checked against for equality
@return A bool value representing equality, true if the sudoku puzzles are
equal, otherwise false
*/
bool Sudoku::equalityHelper(Puzzle* puzzle)
{
	Sudoku* newSudokuPuzzle = dynamic_cast<Sudoku*> (puzzle);
	vector<vector<int>> SudokuVector = newSudokuPuzzle->getSudoku();
	bool equal = true;
	for (int row = 0; row < 9; row++)
	{
		for (int column = 0; column < 9; column++)
		{
			if (SudokuVector[row][column] != SudokuPuzzle[row][column].value)
			{
				equal = false;
				break;
			}
		}
		if (equal == false)
		{
			break;
		}
	}
	return equal;
}

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
bool Sudoku::insertNode(int value, bool set, int row, int column)
{
	if (value < 0 || value > 9 || row < 0 || row > 8 || column < 0 || column > 8)
	{
		cout << "Invalid arguments for inserting a node." << endl;
		return false;
	}
	if (SudokuPuzzle[row][column].set == true)
	{
		cout << "The node at row " << row << " and column " << column << " is already set and " << 
			"cannot be changed" << endl;
		return false;
	}
	else
	{
		SudokuPuzzle[row][column].value = value;
		SudokuPuzzle[row][column].set = set;
		return true;
	}
}

/*
Pure virtual method override that is used to check if the value of a node in
the sudoku puzzle is set or not
@parameter row: The row where the node is located
@parameter column: The column where the node is located
@return a bool value representing whether the value of the node is set or not.
True if the value is set, otherwise false
*/
bool Sudoku::isSet(int row, int column)
{
	if (SudokuPuzzle[row][column].set == false)
	{
		return false;
	}
	else
	{
		return true;
	}
}

/*
Method that changes the fitness value of the Sudoku puzzle
@parameter value: The new fitness of the puzzle
*/
void Sudoku::setFitness(double value)
{
	fitness = value;
}
