/*
Andrew Montgomery
01/24/20
SID#: 1978495
*/

#pragma once
#include <iostream>
#include <string>
using namespace std;

class WordTree
{

	/*
	Operator overload that uses a recursive function to output each node in the
	tree in alphabetical order.
	@Parameter theStream, the output stream that displays the words
	@Parameter tree, the tree that is being outputted
	@return theStream, theStream that is being outputted
	*/
	friend ostream& operator<<(ostream& theStream, const WordTree& tree);

public:

	/*
	Default constructor for WordTree
	*/
	WordTree();

	/*
	Copy constructor for WordTree
	*/
	WordTree(const WordTree& tree);

	/*
	destructor for WordTree
	*/
	~WordTree();

	/*
	Method that adds a word to the WordTree. Uses a recursive helper function to
	find the right location in the tree to insert the word.
	@Parameter: word, the string that will be added to the WordTree
	*/
	void Add(const string word);

	/*
	Method that counts the total number of words in the word tree. This is
	the number of unique words and how many times each one occurs.
	Uses a recursive method that checks each node in the tree and adds the
	count of the node to the total count
	@Return count, the number of total words in the tree
	*/
	int NumWords() const;

	/*
	Method that checks if the WordTree is empty
	@returns true if the WordTree is empty, or false if the WordTree is not empty
	*/
	bool isEmpty() const;

private:

	/*
	Struct the makes up a Node in the WordTree
	Count: the number of times the word in the Node has appeared in the file
	Word: The word from the file
	WordNode* left the pointer to the left child of the node
	WordNode* right the pointer to the right child of the node
	*/
	struct WordNode
	{
		int count;
		string word;
		WordNode* left;
		WordNode* right;
		//Convenience constructor with inializer list
		WordNode() : left(nullptr), right(nullptr), word(nullptr), count(0) {}
		WordNode(WordNode* leftWord, WordNode* rightWord, string theWord, int wordCount) : left(leftWord), right(rightWord),
			word(theWord), count(wordCount) {}
	};
	//The root of the tree
	WordNode* root = nullptr;

	/*
	Recursive helper method that finds the correct location in the WordTree
	to insert a string. Calls itself until the correct location is found
	@Parameter: word, the string that will be added to the WordTree
	@Parameter: root, the current node in the WordTree being compared to, to
	find the correct location for the string
	@return WordNode, an updated WordNode
	*/
	WordNode* Add(const string word, WordNode* root);

	/*
	Recursive helper function that sums up the count of each node to get
	the total number of words in the tree.
	@Parameter: Count, the total number of words in the tree
	@Parameter: root, the current node being examined
	@Return: count, the number of words in a given node
	*/
	int NumWords(int& count, WordNode* root) const;

	/*
	Recursive method that prints out the nodes in the tree in alphabetical order
	@Parameter theStream, the stream that is outputting the words from each node
	@Parameter node, the node currently being examined
	*/
	void OutputHelper(ostream& theStream, const WordNode* node) const;

	/*
	Recursive method that deletes all of the nodes in the tree
	@Parameter node, the node currently being deleted
	*/
	void EmptyTree(WordNode* node);
};

