/*
Andrew Montgomery
01/24/20
SID#: 1978495
*/
#include <iostream>
#include <string>
#pragma once
using namespace std;

class Actor
{
public:
	/*
	Default constructor for Actor
	*/
	Actor();

	/*
	Overload constructor for Movie
	@parameter name: name of the Actor
	@parameter ID: The ID of the Actor
	*/
	Actor(string name, int ID);

	/*
	Method that returns the Actor
	@returns A string with the Actor Name
	*/
	string getName() const;

	/*
	Method that returns the ID of the Actor
	@return A int value representing the ID of the Actor
	*/
	int getID() const;

	/*
	Operator overload for equality
	@parameter rhs: The Actor that you are comparing with the current Actor
	@returns A bool value, true if the Actor are equal or false if the Actor are not equal
	*/
	bool operator==(const Actor& rhs);

	/*
	Operator overload for equality
	@parameter rhs: The Actor that you are comparing with the current Actor
	@returns A bool value, false if the Actor are equal or true if the Actor are not equal
	*/
	bool operator!=(const Actor& rhs);

	/*
	Operator overload for output. Allows the program to print out the Actor
	@parameter theStream: The output stream that contains the Actor
	@parameter theActor: The Actor that is being outputted
	@returns A ostream that contains theStream of the outputted Actor
	*/
	friend ostream& operator<<(ostream& theStream, Actor& theActor);

	/*
	Operator overload that sets the current Actor equal to the Actor in the parameter
	@parameter rhs: The Actor that you are copying into the current Actor
	@returns A Actor with the data values of the parameter
	*/
	Actor& operator=(const Actor& rhs);
private:
	/*
	The name of the Actor
	*/
	string name;

	/*
	The ID of the Actor. This ID is used to locate Actors within the ActorList vector
	of the Graph Class. Each actor has a unique ID based upon when they are inserted into
	the actor list.
	*/
	int ID;
};

