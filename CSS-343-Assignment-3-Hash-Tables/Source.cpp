/*
Andrew Montgomery
01/24/20
SID#: 1978495

The goal of this assignment is to investigate the performance of three different hash 
functions for a separate chaining hash table. The performance of the hash function will 
be based upon the number of collisions that occur when adding elements to the hash table. 
More collisions will result in longer chains, and thus lower performance. 

Hashing allows  us to store large amounts of data (such as phone numbers or flight numbers) 
in a much more memory efficient manner, while at the same time providing faster access to the data. 
However, there is not one set way in which to accomplish hashing, and the various methods 
are known as hash functions.  The point of the assignment is to investigate different hash 
functions, and then implement the best of those hash functions into our own program.
*/

#include <iostream>
#include <vector>
#include <istream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include "Person.h"
#include "HashTable.h"
using namespace std;

/*
Method that is used to parse the file and populate the vector of People with each person (name + phone number)
in the file.
@parameter fileName: the string representing the name of the file
@paramater personList: the vector of people that will contain each person from the file
*/
void ReadFile(string fileName, vector<Person>& personList);

int main()
{
	vector<Person> personList;

	ReadFile("phonebook.txt", personList);
	HashTable testTable =  HashTable(personList);
	for (int i = 0; i < personList.size(); i++)
	{
		testTable.Insert(personList[i]);
	}
	testTable.calculateChainLengths();
}


/*
Method that is used to parse the file and populate the vector of People with each person (name + phone number)
in the file.
@parameter fileName: the string representing the name of the file
@paramater personList: the vector of people that will contain each person from the file
*/
void ReadFile(string fileName, vector<Person>& personList)
{
	ifstream myfile;
	myfile.open(fileName);
	if (!myfile)
	{
		cout << "ERROR: The file entered could not be opened." << endl;
	}
	string firstline;

	string firstName = "";
	string lastName = "";
	string zipCodeString = "";
	string phoneNumberString = "";
	int zipCode;
	int phoneNumber;

	while (myfile.good())
	{
		getline(myfile, firstline);
		{
			string token;
			istringstream ss(firstline);

			//Reads the line until a comma is found, then sets the string to 
			//fistName.
			getline(ss, token, ',');
			firstName = token; //Represents the first name of a person

			//Reads the line until a tab space is found, then sets the string to
			//lastName.
			getline(ss, token, '\t');
			token.erase(remove(token.begin(), token.end(), ' '), token.end());
			lastName = token; //Represents the last name of a person

			//Reads the line until a white space is found, then removes parenthesis
			//from the string and sets the string to zipCode. 
			getline(ss, token, ' ');
			token.erase(remove(token.begin(), token.end(), '('), token.end());
			token.erase(remove(token.begin(), token.end(), ')'), token.end());
			zipCodeString = token; //Represent the zipCode of the phone number
			zipCode = stoi(zipCodeString);

			//Reads the rest of the line, then removes the '-' from the string and
			//sets the string to phoneNumber
			getline(ss, token);
			token.erase(remove(token.begin(), token.end(), '-'), token.end());
			phoneNumberString = token; //Represents the last 7 digits of the phone number
			phoneNumber = stoi(phoneNumberString);

			Person newPerson = Person(firstName, lastName, zipCode, phoneNumber);
			personList.push_back(newPerson);
			
		}
	}
	myfile.close();
}
