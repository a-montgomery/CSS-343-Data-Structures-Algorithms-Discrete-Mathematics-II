/*
WordCounter
Andrew Montgomery
01/24/20
SID#: 1978495

This program was created to parse a text file with the purpose
of counting all of the words in the file. The program utilizes a
binary search tree to hold all of the unique words in the file,
where each node has the word as the key, and the number of times
the word is in the file as a data member.

The input for the program will be read in the cin, and read out to
cout. The program can be ran from the command line using the command
/a.out < (filename).

The program does not distinguish between capital letters and
lower case letters, for example cat and Cat are the same word.
Punctuation (except apostrophe's) and numbers are ignored.

The major compenents of the program are the deconstructor, Add(),
NumWords(), the operator<< overload, the struct WordNode, and the
recursive helpers associated with each.

Deconstructor: Deletes the nodes of the tree
Add(): Adds a new node to the tree
NumWords(): Counts the total number of words (the count of each
unique word).
Operator<<: Used for outputting the tree in alphabetical order
WordNode: Structure used for the nodes of the tree.

They key variables for the program are mainly contained within
the Node. Each node is made up of a key that is a string that contains
each uniquie word, and an int that is used to keep track of the number
of times the word appears in the text file. The Binary Search Tree also
has a root variable that is the first node of the Binary Search tree

*/

#include "WordTree.h"
#include <fstream>
using namespace std;

/*

The main method reads in a file from cin and outputs the number of unique
words and lists the unique words alphabetically to cout.
The file must be in the same directory as the program.

*/

int main()
{
	WordTree theTree = WordTree(); //Creates a new WordTree to hold unique words
	string word; //Variable to hold a word
	char letter; //Variable that receives each character from the file
	word.clear(); //Clears the content of word so it is ready to receive a new word
	//Loop that continues as long as there is another character to be read from cin
	//and the end of the file has not been reached.
	while (cin.get(letter) && !cin.eof())
	{
		//Sets the character retrieved from cin to lowercase because the
		//specifications is that words are not case sensitive
		letter = tolower(letter);
		//If the character is a letter or an apostrophe, add the character to
		//the word
		if (isalpha(letter) || letter == '\'')
		{
			word.push_back(letter);
		}
		//If the next character is not a letter or an apostrophe and the word
		//variable is not empty, add the word to the tree and clear the word
		//so it is ready to receive the next word
		else if (!word.empty())
		{
			theTree.Add(word);
			word.clear();
		}
	}
	//Once the loop has ended, checks to make sure there is not a word left over
	//in the word variable. If word is not empty, adds the word to the WordTree.
	if (!word.empty())
	{
		theTree.Add(word);
		word.clear();
	}
	//Prints out the total number of words and each unique word in alphabetical order
	cout << "Number of total words in the file: " << theTree.NumWords() << endl;
	cout << theTree;
}
