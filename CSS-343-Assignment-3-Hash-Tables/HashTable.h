#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <istream>
#include <fstream>
#include <sstream>
#include <string>
#include "Person.h"
#pragma once
using namespace std;

class HashTable
{
public:
	/*
	Overloaded constructor for HashTable.
	@parameter personList: The vector containing all of the People read
	from the file
	*/
	HashTable(vector<Person> personList);

	/*
	Destructor for HashTable
	*/
	~HashTable();

	/*
	Method that inserts a new Person into the HashTable. Each person is assigned a key that is used
	to place them in the HashTable
	@parameter person: The Person to be added to the hash table
	*/
	void Insert(Person person);

	/*
	Method that prints the contents of the HashTable. Displays the length of the chain at
	each index
	*/
	void PrintHashTable();

	/*
	Method that is used to keep track of the occurance of different chain lengths.
	*/
	void calculateChainLengths();
private:

	struct HashTableListNode
	{
		int key;
		Person person;
		HashTableListNode* next;
		HashTableListNode() : key(key), person(person), next(nullptr) {}
		HashTableListNode(int key, Person person, HashTableListNode* node) : 
			key(key), person(person), next(node) {}
	};

	struct HashTableList
	{
		HashTableListNode* head;
	};

	/*
	Method for the baseline hash function. Determines the hash key by take the ascii value of the
	first character in the Person's first name and last name, adding it to the sum of the person's
	phone number and zip code, and then returning the result modulus TABLESIZE
	@parameter person: The person who the hash key is being created for
	@return an integer value representing the hash key for the Person
	*/
	int HashFunc1(Person person);

	/*
	Method for the 2nd hash function. Determines the hash key by take the sum of
	all of the ascii values of the Person's first and last name, adding it to the
	sum of the person's phone number and zip code, and then returning the result
	modulus TABLESIZE
	@parameter person: The person who the hash key is being created for
	@return an integer value representing the hash key for the Person
	*/
	int HashFunc2(Person person);

	/*
	Method for the final hash function. Determines the hash key by multiplying the
	ascii value of each character in the Person's first and last name by 31. The absolute
	value is taken to ensure that if the resulting integer overflows and returns a negative
	number, the function will continue. After each ascii value is added to the hashKey, the
	resulting hashKey's bits are shifted to further increase the liklihood of creating a unique
	key. Once all the ascii values have been modified, the sum of the Person's zip code and phone
	number are added to the hashKey, and then the bits of the hashKey are shifted again.
	The hashkey modulos TABLESIZE is then returned to esnure the hashKey is within the bounds of
	the TABLESIZE
	@parameter person: The person who the hash key is being created for
	@return an integer value representing the hash key for the Person
	*/
	int HashFunc3(Person person);

	/*
	Method used by the overloaded constructor to create the linked list at each index
	of the hash table
	*/
	void CreateHashTableList();

	/*
	Method used by hashFunc3 to shift the bits of the current integer a
	@parameter a: An int value representing the current state of the hash key
	@return an int value after the bits of the int value in the parameter have been shifted.
	Bit shifting algorithm found at https://burtleburtle.net/bob/hash/integer.html
	*/
	int Shift(int a);

	/*
	Method used to delete all of the indices in the Hash Table
	*/
	void DeleteHashTable();

	/*
	Method used to delete each node in the linked lists located at each index
	of the Hash Table
	*/
	void DeleteHashTableNode(HashTableList array);

	static const int TABLESIZE = 4127; //The size of the table
	HashTableList* array;
	vector<Person> personList;
};

