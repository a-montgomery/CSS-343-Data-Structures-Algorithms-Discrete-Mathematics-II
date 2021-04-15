/*
Andrew Montgomery
01/24/20
SID#: 1978495
*/
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
#include "Movie.h"
#include "Actor.h"
#pragma once
using namespace std;

class Graph
{
public:
	/*
	Overloaded constructor for graph class. Uses actorList to set up initial adjacency list
	with each actor in the vector at the head of their own list
	@parameter actorList: A vector of Actor's with each actor representing a vertex in the graph
	*/
	Graph(vector<Actor> actorList);

	/*
	Copy constructor for Graph
	*/
	Graph(const  Graph& source);

	/*
	Destructor for Graph
	*/
	~Graph();

	/*
	Method that returns an Actor from the actorList based upon the ID in the parameter
	@parameter ID: The ID of the Actor being searched for
	@return A actor that is found in the actorList
	*/
	Actor getActor(int ID);

	/*
	Method for perform a breadth first search of the graph based upon an inputted vertex
	@parameter startVertex: The vertex that the method is using to perform the search
	*/
	void BFS(int startVertex);

	/*
	Method that Prints the Graph. Prints each vertices and their given adjecency list
	*/
	void PrintGraph();

	/*
	Method that prints the map used to build the graph
	@parameter MovieToActorMap: The map to be printed
	*/
	void PrintMap(map<string, vector<Actor>> MovieToActorMap);

	/*
	Method used to find the unique ID of Kevin Bacon in the actorList vector
	@parameter actorList: A vector of Actor's 
	@return A bool value representing if the ID of Kevin Bacon was found in the vector of Actors,
	returns true if found, otherwise false.
	*/
	bool findKevinBaconID(vector<Actor> actorList, int& KevinBaconID);

	/*
	Method that searches through each Movie in the map, and adds an edge between vertices in the graph.
	Each actor in the map represents a vertex in the graph.
	@parameter MovieToActorMap: The map being searched through
	@parameter actorList: The vector of Actor, used to get the unique ID of each actor in the map
	@parameter g: The graph being modified (adding edges between vertices)
	*/
	void AddEdgesFromMap(map<string, vector<Actor>> MovieToActorMap, vector<Actor> actorList, Graph& g);

	/*
	Operator overload for equality
	@parameter g: The Graph that you are comparing with the current Graph
	@returns A bool value, true if the Graphs are equal or false if the Graphs are not equal
	*/
	bool operator==(const Graph& g);

	/*
	Operator overload that sets the current Graph equal to the Graph in the parameter
	@parameter rhs: The Graph that you are copying into the current Graph
	@returns A Graph with the data values of the parameter
	*/
	Graph& operator=(const Graph& g);

private:

	/*
	Struct that makes up a node in the Adjacency List of the Graph
	ID: The unique ID of the actor in the node
	actor: The actor in the node
	next: The pointer to the next node in the  Adjacency List
	*/
	struct AdjListNode
	{
		int ID;
		Actor actor;
		AdjListNode* next;
		AdjListNode() : ID(ID), actor(actor), next(nullptr) {}
		AdjListNode(int ID, Actor actor, AdjListNode* node) : ID(ID), actor(actor), next(node) {}

	};

	/*
	Struct that is used to create an  Adjacency List for each individual vertex
	head: Represents the node at the start of the  Adjacency List (this is the vertex on the graph
	that the  Adjacency List represents)
	*/
	struct AdjList
	{
		AdjListNode* head;
	};

	/*
	Method that adds an edge between two vertices in the graph using the unique ID's of each
	vertice. The graph is undirected so we add an Edge going in both directions.
	@parameter src: The source vertex
	@parameter dest: The destination vertex
	*/
	void addEdge(int src, int dest);

	/*
	Method used in the destructor to delete all of Adjacency Lists in
	the Graph
	*/
	void DeleteGraph();

	/*
	Method used by DeleteGraph() to delete each Node in the Adjacency List
	@parameter array: The Adjacency List containing the nodes to be deleted
	*/
	void DeleteNodes(AdjList array);

	/*
	Method used by the overloaded constructor to create the Adjacency List of each vertex
	in the Graph. Uses each Actor in the vector of Actors to represent an individual vertex
	@parameter actorList: The vector of Actor's containing each Actor
	*/
	void CreateAdjList(vector<Actor> actorList);

	/*
	Method used to insert a Node into an Adjacency List. This represents an added edge between vertices
	@parameter dest: The destination vertex
	@parameter src: The source parameter
	@return A bool value representing whether the Node was successfully inserted. True if the Node was
	inserted, otherwise False
	*/
	bool InsertNode(int dest, int src);

	/*
	Method that creates a new Node to be inputted into an Adjacency Node
	@parameter ID: The ID of the actor
	@parameter actor: The actor to be inserted in the node
	@return A pointer to the newly created Node
	*/
	AdjListNode* newAdjListNode(int ID, Actor actor);

	/*
	The total number of vertices in the Graph
	*/
	int vertices;

	/*
	Represents an Adjacency List for a vertex
	*/
	AdjList* array;

	/*
	A vector of Actor's that will be used as vertices in the Graph
	*/
	vector<Actor> actorList;
};

