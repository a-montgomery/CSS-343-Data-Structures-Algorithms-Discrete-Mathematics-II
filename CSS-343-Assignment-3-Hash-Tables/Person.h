#include <string>
#include <iostream>
#pragma once
using namespace std;

class Person
{
public:
	/*
	Default constructor for Person
	*/
	Person();

	/*
	Overload constructor for Movie
	@parameter fName: first name of the person
	@parameter lName: last name of the person
	@parameter zipCode: the zip code of the person
	@parameter phoneNumber: the last 7 digits of the person's phone number
	*/
	Person(string fName, string lName, int zipCode, int phoneNumber);

	/*
	Method that returns first name of the Person
	@returns A string with the first name of the Person
	*/
	string getFirstName() const;

	/*
	Method that returns last name of the Person
	@returns A string with the last name of the Person
	*/
	string getLastName() const;

	/*
	Method that returns the zip code of the Person
	@return A int value representing the zip code of the Person
	*/
	int getZipCode() const;

	/*
	Method that returns the phone number code of the Person
	@return A int value representing the phone number of the Person
	*/
	int getPhoneNumber() const;

	/*
	Operator overload for equality
	@parameter rhs: The Person that you are comparing with the current Person
	@returns A bool value, true if the Person's are equal or false if the Person's are not equal
	*/
	bool operator==(const Person& rhs);

	/*
	Operator overload for equality
	@parameter rhs: The Person that you are comparing with the current Person
	@returns A bool value, false if the Person's are equal or true if the Person's are not equal
	*/
	bool operator!=(const Person& rhs);

	/*
	Operator overload that sets the current Person equal to the Person in the parameter
	@parameter rhs: The Person that you are copying into the current Person
	@returns A Person with the data values of the parameter
	*/
	Person& operator=(const Person& rhs);

	/*
	Operator overload for output. Allows the program to print out the Actor
	@parameter theStream: The output stream that contains the Person
	@parameter thePerson: The Person that is being outputted
	@returns A ostream that contains theStream of the outputted Person
	*/
	friend ostream& operator<<(ostream& theStream, Person& thePerson);

private:
	string fName, lName;
	int zipCode, phoneNumber;
};

