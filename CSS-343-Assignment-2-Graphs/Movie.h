/*
Andrew Montgomery
01/24/20
SID#: 1978495
*/
#include <iostream>
#include <string>
#pragma once
using namespace std;

class Movie
{
public:
	/*
	Default constructor for Movie
	*/
	Movie();

	/*
	Overload constructor for Movie
	@parameter title: Title of the Movie
	@parameter date: Release date of the Movie
	*/
	Movie(string title, string date);

	/*
	Method that returns the Movie
	@returns A string with the Movie Name and Movie Date seperate by a whitespace
	*/
	string getMovie() const;

	/*
	Method that changes the name and date of a Movie
	@parameter movieName: the new name of the Movie
	@parameter movieDate: the new date of the Movie
	*/
	void setMovie(const string movieName, const string movieDate);

	/*
	Operator overload that sets the current Movie equal to the Movie in the parameter
	@parameter rhs: The movie that you are copying into the current Movie
	@returns A movie with the data values of the parameter
	*/
	Movie& operator=(const Movie& rhs);

	/*
	Operator overload for equality
	@parameter rhs: The movie that you are comparing with the current movie
	@returns A bool value, true if the movies are equal or false if the movies are not equal
	*/
	bool operator==(const Movie& rhs);

	/*
	Operator overload for output. Allows the program to print out the Movie
	@parameter theStream: The output stream that contains the Movie
	@parameter theMovie: The Movie that is being outputted
	@returns A ostream that contains theStream of the outputted Movie
	*/
	friend ostream& operator<<(ostream& theStream, Movie& theMovie);

	/*
	Operator overload to check order of Movies based on alphabetical order. 
	@parameter rhs: The Movie that is being compared to the current Movie
	@return A bool value, false if the Movie being compared is less than the current Movie
	or true if the Movie being compared is greater than the current Movie
	*/
	bool operator<(const Movie& rhs);

	/*
	Operator overload to check order of Movies based on alphabetical order.
	@parameter rhs: The Movie that is being compared to the current Movie
	@return A bool value, false if the Movie being compared is greater than the current Movie
	or true if the Movie being compared is less than the current Movie
	*/
	bool operator>(const Movie& rhs);

private:
	/*
	Title: The title of the Movie
	Date: The date of the Movie
	*/
	string title, date;
};

