#include "Person.h"

/*
Default constructor for Person
*/
Person::Person()
{
	fName = "";
	lName = "";
	zipCode = -1;
	phoneNumber = -1;
}

/*
Overload constructor for Movie
@parameter fName: first name of the person
@parameter lName: last name of the person
@parameter zipCode: the zip code of the person
@parameter phoneNumber: the last 7 digits of the person's phone number
*/
Person::Person(string fName, string lName, int zipCode, int phoneNumber)
{
	this->fName = fName;
	this->lName = lName;
	this->zipCode = zipCode;
	this->phoneNumber = phoneNumber;
}

/*
Method that returns first name of the Person
@returns A string with the first name of the Person
*/
string Person::getFirstName() const
{
	return fName;
}

/*
Method that returns last name of the Person
@returns A string with the last name of the Person
*/
string Person::getLastName() const
{
	return lName;
}

/*
Method that returns the zip code of the Person
@return A int value representing the zip code of the Person
*/
int Person::getZipCode() const
{
	return zipCode;
}

/*
Method that returns the phone number code of the Person
@return A int value representing the phone number of the Person
*/
int Person::getPhoneNumber() const
{
	return phoneNumber;
}

/*
Operator overload for equality
@parameter rhs: The Person that you are comparing with the current Person
@returns A bool value, true if the Person's are equal or false if the Person's are not equal
*/
bool Person::operator==(const Person & rhs)
{
	if (this->fName == rhs.fName && this-> lName == rhs.lName && this->zipCode == rhs.zipCode
		&& this->phoneNumber == rhs.phoneNumber)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
Operator overload for equality
@parameter rhs: The Person that you are comparing with the current Person
@returns A bool value, false if the Person's are equal or true if the Person's are not equal
*/
bool Person::operator!=(const Person & rhs)
{
	if (this->fName != rhs.fName || this->lName != rhs.lName || this->zipCode != rhs.zipCode
		|| this->phoneNumber != rhs.phoneNumber)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
Operator overload that sets the current Person equal to the Person in the parameter
@parameter rhs: The Person that you are copying into the current Person
@returns A Person with the data values of the parameter
*/
Person& Person::operator=(const Person & rhs)
{
	this->fName = rhs.fName;
	this->lName = rhs.lName;
	this->zipCode = rhs.zipCode;
	this->phoneNumber = rhs.phoneNumber;
	return *this;
}

/*
Operator overload for output. Allows the program to print out the Actor
@parameter theStream: The output stream that contains the Person
@parameter thePerson: The Person that is being outputted
@returns A ostream that contains theStream of the outputted Person
*/
ostream & operator<<(ostream& theStream, Person & thePerson)
{
	theStream << thePerson.getFirstName() << ", " << thePerson.getLastName() << '\t' << 
		"(" << thePerson.getZipCode() << ") " << thePerson.getPhoneNumber();
	return theStream;
}
