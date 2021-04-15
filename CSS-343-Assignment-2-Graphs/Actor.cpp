/*
Andrew Montgomery
01/24/20
SID#: 1978495
*/
#include "Actor.h"

/*
Default constructor for Actor
*/
Actor::Actor()
{
	name = "";
	ID = -1;
}

/*
Overload constructor for Movie
@parameter name: name of the Actor
@parameter ID: The ID of the Actor
*/
Actor::Actor(string name, int ID)
{
	this->name = name;
	this->ID = ID;
}

/*
Method that returns the Actor
@returns A string with the Actor Name
*/
string Actor::getName() const
{
	return name;
}

/*
Method that returns the ID of the Actor
@return A int value representing the ID of the Actor
*/
int Actor::getID() const
{
	return ID;
}

/*
Operator overload for equality
@parameter rhs: The Actor that you are comparing with the current Actor
@returns A bool value, true if the Actor are equal or false if the Actor are not equal
*/
bool Actor::operator==(const Actor& rhs)
{
	if (this->name == rhs.name && this->ID == rhs.ID)
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
@parameter rhs: The Actor that you are comparing with the current Actor
@returns A bool value, false if the Actor are equal or true if the Actor are not equal
*/
bool Actor::operator!=(const Actor& rhs)
{
	if (this->name != rhs.name && this->ID != rhs.ID)
	{
		return true;
	}
	else
	{
		return false;
	}
}


/*
Operator overload that sets the current Actor equal to the Actor in the parameter
@parameter rhs: The Actor that you are copying into the current Actor
@returns A Actor with the data values of the parameter
*/
Actor& Actor::operator=(const Actor & rhs)
{
	this->name = rhs.name;
	this->ID = rhs.ID;
	return *this;
}

/*
Operator overload for output. Allows the program to print out the Actor
@parameter theStream: The output stream that contains the Actor
@parameter theActor: The Actor that is being outputted
@returns A ostream that contains theStream of the outputted Actor
*/
ostream & operator<<(ostream & theStream, Actor & theActor)
{
	theStream << theActor.getName();
	return theStream;
}
