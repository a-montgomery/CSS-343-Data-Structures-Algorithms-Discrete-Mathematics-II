/*
Andrew Montgomery
01/24/20
SID#: 1978495

This program was created to parse a text file containing a portion
of the IMDB database and to calculate the Bacon number of the actor's
found in the file. The game is generally called Six Degrees of Kevin
Bacon, and the point is to find how many links away from Kevin Bacon
an actor is. For example, if  actor A was in a movie with actor B
who was in a movie with Kevin Bacon, then actor A would be two links
away from Kevin Bacon and thus have a Bacon score of two. Each movie 
link away adds one to the actors Kevin Bacon score. In this program, 
it was designated that actors with no links to Kevin Bacon had a score
of "infinity".

The input for the program will be read in through a command line
argument. In this case, the command line argument will be a the name
of a file that contains actor names, with corresponding movies.

The main hurdle the program must face is with parsing the file. An 
actor and a movie will be present, but there is also extraneous 
information that must be discarded/

The major components of the program are the Actor, Movie, and Graph 
class. The Movie and Actor class are standard object classes, that 
contain constuctors, get/set methods, and operator overloads.
The graph class has most of the functions the perform the heavy 
lifting of the program, such as a method that adds edges between
vertices and a breadth first search method that is used to calculate
the Bacon scores of the actors in the file

The key auxillary data structures used to make the graph work was a 
vector, which was used to store all of the Actor's from the file in 
a list. By placing the Actor's in a vector, the program is able to 
correspond a unique ID number to each Actor so that they are easily
accesible by the graph functions. The other data structure used was a 
map. The map is used to hold all of the individual movies and TV shows
from the text file as the key, and a vector of Actor's as the element 
for each key. By using the vector of Actor's as the element, the Graph 
class is able to add an edge between all actors who were in the same 
movie.
*/

#include <iostream>
#include <vector>
#include <istream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map>
#include "Actor.h"
#include "Movie.h"
#include "Graph.h"
#include <cstdint>
using namespace std;

/*
Method that is used to parse the file and populate the vector of Actor's with each actor in the file,
and adds each movie to the map and corresponding actors to the movie's.
@parameter fileName: the string representing the name of the file
@parameter theMap: the map to insert the movies and actor's into
@paramater actorList: the vector of Actor's that will contain each actor
@return a bool value representing whether the file was successfully read or not. True if read, otherwise 
false
*/
bool ReadFile(string fileName, map<string, vector<Actor>>& theMap, vector<Actor>& actorList);

int main(int argc, char* argv[])
{
	string fileName = "";
	
	if (argc != 2)
	{
		cerr << "Invalid number of command line arguments." << endl;
	}
	else
	{

		fileName = string(argv[1]);
		int KevinBaconID;
		map<string, vector<Actor>> MovieToActorMap;
		vector<Actor> actorList;

		ReadFile(fileName, MovieToActorMap, actorList);
		Graph SixDegressOfKevinBacon = Graph(actorList);
		SixDegressOfKevinBacon.AddEdgesFromMap(MovieToActorMap, actorList, SixDegressOfKevinBacon);

		if (SixDegressOfKevinBacon.findKevinBaconID(actorList, KevinBaconID))
		{
			SixDegressOfKevinBacon.BFS(KevinBaconID);
		}
		else
		{
			cout << "Kevin Bacon was not found in the file" << endl;
			cout << "Please ensure the name in the file matches the format: Bacon, Kevin (I)" << endl;
		}
		return 0;
	}
}

/*
Method that is used to parse the file and populate the vector of Actor's with each actor in the file,
and adds each movie to the map and corresponding actors to the movie's.
@parameter fileName: the string representing the name of the file
@parameter theMap: the map to insert the movies and actor's into
@paramater actorList: the vector of Actor's that will contain each actor
@return a bool value representing whether the file was successfully read or not. True if read, otherwise
false
*/
bool ReadFile(string fileName, map<string, vector<Actor>>& theMap, vector<Actor>& actorList)
{
	ifstream myfile;
	myfile.open(fileName);
	if (!myfile)
	{
		cout << "ERROR: The file entered could not be opened." << endl;
		return false;
	}
	string firstline;
	string actorName = "";
	string movieName = "";
	string movieDate = "";
	int actorCount = 0; //Counter to keep track of the number of actors read from the file
	Actor lastActor; //the last Actor read from the file
	Movie lastMovie; //the last Movie read from the file

	while (myfile.good())
	{
		bool actor = false;
		getline(myfile, firstline);
		//if the line is not empty, continue on, otherwise skip the line
		if (firstline != "")
		{
			istringstream ss(firstline);
			string token;

			//Searches the first character in the line for a tabspace. If a tabspace is not found
			//than there is a new actor, otherwise it is another movie for the last actor
			if (firstline[0] != '\t')
			{
				//Gets the line up to the first tabspace. This is the name of the actor. Use that
				//name to create a new actor, add the actor to the actorList, increase the 
				//actor count by 1, and set the new actor to the last actor found.
				getline(ss, token, '\t');
				Actor newActor = Actor(token, actorCount);
				actorList.push_back(newActor);
				actorCount++;
				lastActor = newActor;
				lastMovie = Movie();

				//Reads the remain token up to the next  opening parenthesis and remove any tabspaces in 
				//front of the token.  This token now represents the name of a movie
				getline(ss, token, '(');
				token.erase(remove(token.begin(), token.end(), '\t'), token.end());
				movieName = token;

				//Reads the remaining line up to the next closing parenthesis. This token now
				//represents the date the movie was released
				getline(ss, token, ')');
				movieDate = token;

				//If the newMovie is equal to the last movie found, we continue the loop without
				//doing anything. This avoids multiple entries of the same movie to the map
				if (lastMovie.getMovie() == movieName + " " + movieDate)
				{
					continue;
				}

				//If the movie is not the same, insert the movie into the map and add the associated actor
				//into the vector of Actor's associated with the movie in the map. Set the lastMovie to this
				//new movie
				else
				{
					Movie newMovie = Movie(movieName, movieDate);
					vector<Actor> actorNames;
					theMap.insert(pair<string, vector<Actor>>(newMovie.getMovie(), actorNames));
					theMap[newMovie.getMovie()].push_back(newActor);
					lastMovie = newMovie;
				}
			}

			//If the first character is a tabspace, then the next token is the name of a movie.
			//Follow the same procedure to get the tokens for the movie name and date, and then
			//check the map for the movie. Insert the movie and actor if not already in the map
			else
			{
				getline(ss, token, '(');
				token.erase(remove(token.begin(), token.end(), '\t'), token.end());
				movieName = token;
				getline(ss, token, ')');
				movieDate = token;
				if (lastMovie.getMovie() == movieName + " " + movieDate)
				{
					continue;
				}
				else
				{
					Movie newMovie = Movie(movieName, movieDate);
					vector<Actor> actorNames;
					theMap.insert(pair<string, vector<Actor>>(newMovie.getMovie(), actorNames));
					theMap[newMovie.getMovie()].push_back(lastActor);
					lastMovie = newMovie;
				}

			}
		}
	}
	myfile.close();
	return true;
}
