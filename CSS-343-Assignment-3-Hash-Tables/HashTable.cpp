#include "HashTable.h"

/*
Overloaded constructor for HashTable.
@parameter personList: The vector containing all of the People read
from the file
*/
HashTable::HashTable(vector<Person> personList)
{
	this->personList = personList;
	array = new HashTableList[TABLESIZE];
	CreateHashTableList();
}

/*
Destructor for HashTable
*/
HashTable::~HashTable()
{
	DeleteHashTable();
	delete[] array;
}

/*
Method for the baseline hash function. Determines the hash key by take the ascii value of the
first character in the Person's first name and last name, adding it to the sum of the person's
phone number and zip code, and then returning the result modulus TABLESIZE
@parameter person: The person who the hash key is being created for
@return an integer value representing the hash key for the Person
*/
int HashTable::HashFunc1(Person person)
{
	int hashKey = 0;
	int firstLetter = (int)person.getFirstName().at(0);
	int secondLetter = (int)person.getLastName().at(0);
	hashKey = ((person.getPhoneNumber() + person.getZipCode()) + (firstLetter + secondLetter));
	return hashKey % TABLESIZE;
}


/*
Method for the 2nd hash function. Determines the hash key by take the sum of
all of the ascii values of the Person's first and last name, adding it to the
sum of the person's phone number and zip code, and then returning the result
modulus TABLESIZE
@parameter person: The person who the hash key is being created for
@return an integer value representing the hash key for the Person
*/
int HashTable::HashFunc2(Person person)
{
	int hashKey = 0;
	string personString = person.getFirstName() + person.getLastName();
	int phoneNumber = person.getPhoneNumber();

	for (int i = 0; i < personString.length(); i++)
	{
		hashKey += personString.at(i);
	}
	hashKey += (person.getPhoneNumber() + person.getZipCode());
	return hashKey % TABLESIZE;
}

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
int HashTable::HashFunc3(Person person)
{
	int hashKey = 0;
	string personString = person.getFirstName() + person.getLastName();

	for (int i = 0; i < personString.length(); i++)
	{
		hashKey += abs(31 * personString.at(i));
		hashKey = Shift(hashKey);
	}
	hashKey += (person.getPhoneNumber() + person.getZipCode());
	hashKey = Shift(hashKey);
	return hashKey % TABLESIZE;
}

/*
Method that inserts a new Person into the HashTable. Each person is assigned a key that is used
to place them in the HashTable
@parameter person: The Person to be added to the hash table
*/
void HashTable::Insert(Person person)
{
	int key = HashFunc3(person); //Calls the hash function to assign a key to the Person being inserted
	//Createsa new node with to be inserted in the table, using the key and the Person
	HashTableListNode* insNode = new HashTableListNode(key, person, nullptr);

	//If the head of the list at the entry index is nullptr, insert the new node as the head. If the head
	//is not empty, traverse the list until the end, and place the node at the end of the list
	if (array[key].head == nullptr)
	{
		array[key].head = insNode;
	}
	else
	{
		HashTableListNode* currentNode = array[key].head->next;
		HashTableListNode* previousNode = array[key].head;
		while (currentNode != nullptr)
		{
			if (currentNode->person == insNode->person)
			{
				delete insNode;
			}
			else
			{
				previousNode = currentNode;
				currentNode = currentNode->next;
			}
		}
		previousNode->next = insNode;
	}
}

/*
Method that prints the contents of the HashTable. Displays the length of the chain at
each index
*/
void HashTable::PrintHashTable()
{
	for (int i = 0; i < TABLESIZE; ++i)
	{
		HashTableListNode* node = array[i].head;
		if (node == nullptr)
		{
			cout << "Hash Table is empty at key: " << i << endl;
		}
		if (node != nullptr)
		{
			int count = 0;
			while (node)
			{
				count++;
				node = node->next;
			}
			cout << "Chain Length at key value " << i << " is: " << count << endl;
		}
	}
}

/*
Method that is used to keep track of the occurance of different chain lengths. 
*/
void HashTable::calculateChainLengths()
{
	vector<int> chainLength(TABLESIZE);
	int totalCount = 0;
	for (int i = 0; i < TABLESIZE; i++)
	{
		HashTableListNode* node = array[i].head;
		int count = 0;
		while (node != nullptr)
		{
			count++;
			totalCount++;
			node = node->next;
		}

		chainLength.at(count) = chainLength.at(count) + 1;
	}

	for (int i = 0; i < TABLESIZE; i++)
	{
		if (chainLength.at(i) == 0)
		{
			continue;
		}
		cout << "Chain Length " << i << ": " << chainLength.at(i) << endl;
	}
}

/*
Method used by the overloaded constructor to create the linked list at each index
of the hash table
*/
void HashTable::CreateHashTableList()
{
	for (int i = 0; i < TABLESIZE; i++)
	{
		array[i].head = nullptr;
	}
}

/*
Method used by hashFunc3 to shift the bits of the current integer a
@parameter a: An int value representing the current state of the hash key
@return an int value after the bits of the int value in the parameter have been shifted.
Bit shifting algorithm found at https://burtleburtle.net/bob/hash/integer.html
*/
int HashTable::Shift(int a)
{
	a -= (a << 6);
	a ^= (a >> 17);
	a -= (a << 9);
	a ^= (a << 4);
	a -= (a << 3);
	a ^= (a << 10);
	a ^= (a >> 15);

	return a;
}

/*
Method used to delete all of the indices in the Hash Table
*/
void HashTable::DeleteHashTable()
{
	for (int i = TABLESIZE - 1; i > -1; i--)
	{
		DeleteHashTableNode(array[i]);
	}
}

/*
Method used to delete each node in the linked lists located at each index
of the Hash Table
*/
void HashTable::DeleteHashTableNode(HashTableList array)
{
	//Loop that continues until the HashTableList head is equal to nullptr
	//at this point, the list is empty and all nodes have been deleted
	HashTableListNode* temp;
	while (array.head != nullptr)
	{
		temp = array.head;
		array.head = array.head->next;
		delete temp;
		temp = nullptr;
	}
}