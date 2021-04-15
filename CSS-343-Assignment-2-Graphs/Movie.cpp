/*
Andrew Montgomery
01/24/20
SID#: 1978495
*/
#include "Movie.h"

/*
Default constructor for Movie
*/
Movie::Movie()
{
	title = "";
	date = "";
}

/*
Overload constructor for Movie
@parameter title: Title of the Movie
@parameter date: Release date of the Movie
*/
Movie::Movie(string title, string date)
{
	this->title = title;
	this->date = date;
}

/*
Method that returns the Movie
@returns A string with the Movie Name and Movie Date seperate by a whitespace
*/
string Movie::getMovie() const
{
	return this->title + " " + this->date;
}

/*
Method that changes the name and date of a Movie
@parameter movieName: the new name of the Movie
@parameter movieDate: the new date of the Movie
*/
void Movie::setMovie(const string movieName, const string movieDate)
{
	this->title = movieName;
	this->date = movieDate;
}

/*
Operator overload that sets the current Movie equal to the Movie in the parameter
@parameter rhs: The movie that you are copying into the current Movie
@returns A movie with the data values of the parameter
*/
Movie& Movie::operator=(const Movie& rhs)
{
	this->title = rhs.title;
	this->date = rhs.date;
	return *this;
}

/*
Operator overload for equality
@parameter rhs: The movie that you are comparing with the current movie
@returns A bool value, true if the movies are equal or false if the movies are not equal
*/
bool Movie::operator==(const Movie & rhs)
{
	if (this->title == rhs.title && this->date == rhs.date)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
Operator overload to check order of Movies based on alphabetical order.
@parameter rhs: The Movie that is being compared to the current Movie
@return A bool value, false if the Movie being compared is less than the current Movie
or true if the Movie being compared is greater than the current Movie
*/
bool Movie::operator<(const Movie & rhs)
{
	if (this->title < rhs.title)
	{
		return true;
	}
	else if (this->title == rhs.title && this->date < rhs.date)
	{
		return true;
	}
	else
	{
		return false;
	}

}

/*
Operator overload to check order of Movies based on alphabetical order.
@parameter rhs: The Movie that is being compared to the current Movie
@return A bool value, false if the Movie being compared is greater than the current Movie
or true if the Movie being compared is less than the current Movie
*/
bool Movie::operator>(const Movie & rhs)
{
	if (this->title < rhs.title)
	{
		return false;
	}
	else if (this->title == rhs.title && this->date < rhs.date)
	{
		return false;
	}
	else
	{
		return true;
	}

}

/*
Operator overload for output. Allows the program to print out the Movie
@parameter theStream: The output stream that contains the Movie
@parameter theMovie: The Movie that is being outputted
@returns A ostream that contains theStream of the outputted Movie
*/
ostream & operator<<(ostream & theStream, Movie& theMovie)
{
	theStream << theMovie.getMovie();
	return theStream;
}
