/*
Andrew Montgomery
01/24/20
SID#: 1978495
*/
#include "WordTree.h"

/*
Default constructor for WordTree
*/
WordTree::WordTree()
{
	root = nullptr;
}

/*
Copy constructor for WordTree
*/
WordTree::WordTree(const WordTree& tree)
{
	this->root = nullptr;
	*this = tree;
}

/*
destructor for WordTree
*/
WordTree::~WordTree()
{
	EmptyTree(root);
}

/*
Method that checks if the WordTree is empty
@returns true if the WordTree is empty, or false if the WordTree is not empty
*/
bool WordTree::isEmpty() const
{
	if (root == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
Method that adds a word to the WordTree. Uses a recursive helper function to
find the right location in the tree to insert the word.
@Parameter: word, the string that will be added to the WordTree
*/
void WordTree::Add(const string word)
{
	//If the root of the WordTree is a nullptr (the WordTree is empty), then
	//the method creates a new WordNode and places it at the root of the 
	//WordTree. If the tree is not empty, calls the recursive helper function
	//to find the right location in the WordTree to place the string
	if (root == nullptr)
	{
		WordNode* insNode = new WordNode(nullptr, nullptr, word, 1);
		root = insNode;
	}
	else
	{
		Add(word, root);
	}
}

/*
Recursive helper method that finds the correct location in the WordTree
to insert a string. Calls itself until the correct location is found
@Parameter: word, the string that will be added to the WordTree
@Parameter: root, the current node in the WordTree being compared to, to
find the correct location for the string
@return WordNode, an updated WordNode
*/
WordTree::WordNode* WordTree::Add(const string word, WordNode* root)
{
	//If the node is empty, insert the word in this place
	if (root == nullptr)
	{
		WordNode* insNode = new WordNode(nullptr, nullptr, word, 1);
		root = insNode;
		return insNode;
	}
	else
	{
		//if the word is the same as the word in the node, do not add
		//the word to the tree, but increase the count by 1
		if (word == root->word)
		{
			root->count = root->count + 1;
		}
		//If the word is less than the word in the node (Alphabetically)
		//move to the left child, and use the Add method again
		else if (word < root->word)
		{
			root->left = Add(word, root->left);
		}
		//If the word is greater than the word in the node (Alphabetically)
		//move to the left child, and use the Add method again
		else
		{
			root->right = Add(word, root->right);
		}
	}

	return root;
}

/*
Method that counts the total number of words in the word tree. This is
the number of unique words and how many times each one occurs.
Uses a recursive method that checks each node in the tree and adds the 
count of the node to the total count
@Return count, the number of total words in the tree
*/
int WordTree::NumWords() const
{
	int count = 0;
	//if the tree is empty, returns 0
	if (isEmpty())
	{
		return count;
	}
	//if the tree is not empty, runs the recursive helper to get the
	//total number of words
	else
	{
		count = NumWords(count, root);
	}
	return count;
}

/*
Recursive helper function that sums up the count of each node to get
the total number of words in the tree.
@Parameter: Count, the total number of words in the tree
@Parameter: root, the current node being examined
@Return: count, the number of words in a given node
*/
int WordTree::NumWords(int& count, WordNode* root) const
{
	//If the node is not empty, recursively counts the number of words
	//in each node
	if (root != nullptr)
	{
		count += root->count;
		NumWords(count, root->left);
		NumWords(count, root->right);
	}
	return count;
}

/*
Operator overload that uses a recursive function to output each node in the
tree in alphabetical order.
@Parameter theStream, the output stream that displays the words
@Parameter tree, the tree that is being outputted
@return theStream, theStream that is being outputted
*/
ostream & operator<<(ostream& theStream, const WordTree& tree)
{
	tree.OutputHelper(theStream, tree.root);
	theStream << endl;
	return theStream;
}

/*
Recursive method that prints out the nodes in the tree in alphabetical order
@Parameter theStream, the stream that is outputting the words from each node
@Parameter node, the node currently being examined
*/
void WordTree::OutputHelper(ostream& theStream, const WordNode* node) const
{
	//If the node is not empty, recursively print the nodes in order
	if (node != nullptr)
	{
		OutputHelper(theStream, node->left);
		theStream << node->word << " " << node->count << endl;
		OutputHelper(theStream, node->right);
	}
}

/*
Recursive method that deletes all of the nodes in the tree
@Parameter node, the node currently being deleted
*/
void WordTree::EmptyTree(WordNode* node)
{
	//If the node is not empty, delete the nodes in post order
	if (node != nullptr)
	{
		EmptyTree(node->left);
		EmptyTree(node->right);
		delete node;
	}
}
