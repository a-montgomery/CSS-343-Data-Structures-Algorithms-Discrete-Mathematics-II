/*
Andrew Montgomery
01/24/20
SID#: 1978495
*/
#include "Graph.h"

/*
Overloaded constructor for graph class. Uses actorList to set up initial adjacency list
with each actor in the vector at the head of their own list
@parameter actorList: A vector of Actor's with each actor representing a vertex in the graph
*/
Graph::Graph(vector<Actor> actorList)
{
	this->vertices = actorList.size();
	this->actorList = actorList;
	array = new AdjList[vertices];
	CreateAdjList(actorList); //Creates an adjacency list for each vertex
}

/*
Copy constructor for Graph
*/
Graph::Graph(const  Graph& source)
{
	//Sets each adjacency list in the current graph to nullptr
	//so that the Graph in the parameter can be copied into the
	//current graph
	for (int i = 0; i < vertices; i++)
	{
		this->array[i].head = nullptr;
	}
	*this = source;

}

/*
Destructor for Graph
*/
Graph::~Graph()
{
	DeleteGraph();
	delete array;
}

/*
Method that returns an Actor from the actorList based upon the ID in the parameter
@parameter ID: The ID of the Actor being searched for
@return A actor that is found in the actorList
*/
Actor Graph::getActor(int ID)
{
	return actorList[ID];
}

/*
Method that adds an edge between two vertices in the graph using the unique ID's of each
vertice. The graph is undirected so we add an Edge going in both directions.
@parameter src: The source vertex
@parameter dest: The destination vertex
*/
void Graph::addEdge(int src, int dest)
{
	//Adds an edge from the source vertex to the destination vertex
	InsertNode(src, dest);
	//Adds an edge from the destination vertex to the source vertex
	InsertNode(dest, src);
}

/*
Method for perform a breadth first search of the graph based upon an inputted vertex
@parameter startVertex: The vertex that the method is using to perform the search
*/
void Graph::BFS(int startVertex)
{
	int lastVertex;
	//vector representing whether each vertex has been visited or not
	vector<bool> marked;
	//vector representing the graph level of each vertex
	vector<int> level;
	//Sets all vertices to unvisited and the level of each vertex to -1
	//-1 represents that the vertex is not connected to the startVertex
	//will be changed later to the actual vertex if they are connected
	for (int i = 0; i < vertices; i++)
	{
		marked.push_back(false);
		level.push_back(-1);
	}

	list<int> q;
	//Sets the startVertex to visited, adds the vertex to the queue,
	//and sets the graph level to 0
	marked[startVertex] = true;
	q.push_back(startVertex);
	level[startVertex] = 0;
	//While loop that continues as long as there are vertices in the queue
	while (!q.empty())
	{
		startVertex = q.front();
		cout << array[startVertex].head->actor << '\t' << level[startVertex];
		cout << endl;
		lastVertex = q.front();
		q.pop_front();
		//Sets the current node to the head of the adjacency list for the start vertex
		//loops until all of the nodes in the adjecency list have been examined
		AdjListNode* currentNode = array[startVertex].head;
 		while (currentNode != nullptr)
		{
			//if the node in the adjacency list has not been visited, sets the graph level
			//of the node to 1 higher than the current node, and add the vertex to the queue
			if (!marked[currentNode->ID])
			{
				marked[currentNode->ID] = true;
				level[currentNode->ID] = level[lastVertex] + 1;
				q.push_back(currentNode->ID);
			}
			currentNode = currentNode->next;
		}	
	}
	//Loop that prints all of the vertices that are unconnected to the start vertex
	//and prints the actor's name and "infinity"
	//"infinity" represents an actor with no connection to the start vertex
	for (int i = 0; i < vertices; i++)
	{
		if (level[i] == -1)
		{
			cout << array[i].head->actor << '\t' << "infinity" << endl;
		}
	}
}

/*
Operator overload for equality
@parameter g: The Graph that you are comparing with the current Graph
@returns A bool value, true if the Graphs are equal or false if the Graphs are not equal
*/
bool Graph::operator==(const Graph & g)
{
	//Loops through each Adjacency list in the graph, if all adjacency lists
	//are equal, then the graphs are equal.
	for (int i = 0; i < vertices; i++)
	{
		AdjListNode* graph1 = g.array[i].head;
		AdjListNode* graph2 = this->array[i].head;
		while (graph1 != nullptr)
		{
			if (graph1->actor != graph2->actor || graph1->ID != graph2->ID)
			{
				return false;
			}
			graph1 = graph1->next;
			graph2 = graph2->next;
		}
	}
	return true;
}

/*
Operator overload that sets the current Graph equal to the Graph in the parameter
@parameter rhs: The Graph that you are copying into the current Graph
@returns A Graph with the data values of the parameter
*/
Graph & Graph::operator=(const Graph& g)
{
	//if the graphs are alredy equal, return the graph as is
	if (this == &g)
	{
		return *this;
	}

	//if the graphs are not equal, delete the current graph so the graph to
	//be copied can be copied into the current graph
	this->DeleteGraph();

	//Loop that goes through each adjacency list of the graph to be copied, and copies
	//each node into the current graph
	for (int i = 0; i < g.actorList.size(); i++)
	{
		AdjListNode* dNode, *sNode, *iNode;
		sNode = g.array[i].head;
		if (sNode == nullptr)
		{
			this->array[i].head = sNode;
		}
		else
		{
			dNode = new AdjListNode;
			dNode->actor = (g.array[i].head)->actor;
			dNode->ID = (g.array[i].head)->ID;
			this->array[i].head = dNode;
			sNode = sNode->next;
			while (sNode != nullptr)
			{
				iNode = new AdjListNode;
				iNode->actor = sNode->actor;
				iNode->ID = iNode->ID;
				iNode->next = nullptr;
				dNode->next = iNode;
				dNode = dNode->next;
				sNode = sNode->next;
			}
		}
	}
	return *this;
}

/*
Method that searches through each Movie in the map, and adds an edge between vertices in the graph.
Each actor in the map represents a vertex in the graph.
@parameter MovieToActorMap: The map being searched through
@parameter actorList: The vector of Actor, used to get the unique ID of each actor in the map
@parameter g: The graph being modified (adding edges between vertices)
*/
void Graph::AddEdgesFromMap(map<string, vector<Actor>> MovieToActorMap, 
	vector<Actor> actorList, Graph & g)
{
	//Iterator that iterates through each movie in the Map and adds an edge between actors
	//that had a role in the given movie
	for (map<string, vector<Actor> >::iterator ii = MovieToActorMap.begin(); 
		ii != MovieToActorMap.end(); ++ii) 
	{
		vector <Actor> inVect = (*ii).second;
		for (unsigned j = 0; j < inVect.size(); j++) {
			for (unsigned k = j + 1; k < inVect.size(); k++)
			{
				g.addEdge(inVect[j].getID(), inVect[k].getID());
			}
		}
	}
}

/*
Method used in the destructor to delete all of Adjacency Lists in
the Graph
*/
void Graph::DeleteGraph()
{
	//loops through each adjacency list starting with the last adjacency list
	//in the graph
	for (int i = vertices - 1; i > -1; i--)
	{
		DeleteNodes(array[i]);
	}
}

/*
Method used by DeleteGraph() to delete each Node in the Adjacency List
@parameter array: The Adjacency List containing the nodes to be deleted
*/
void Graph::DeleteNodes(AdjList array)
{
	//Loop that continues until the Adjacency Lists head is equal to nullptr
	//at this point, the list is empty and all nodes have been deleted
	AdjListNode* temp;
	while (array.head != nullptr)
	{
		temp = array.head;
		array.head = array.head->next;
		delete temp;
		temp = nullptr;
	}
}

/*
Method that Prints the Graph. Prints each vertices and their given adjecency list
*/
void Graph::PrintGraph()
{
	//Loop that iterates through each adjacency list, and shows the connections between
	//actors
	for (int i = 0; i < vertices; ++i)
	{
		AdjListNode* node = array[i].head;
		cout << "\nAdjacency list of vertex " << array[i].head->actor << endl;
		while (node)
		{
			cout << node->actor;
			if (node->next)
				cout << "-> ";
			node = node->next;
		}
		cout << endl;
	}
}

/*
Method that prints the map used to build the graph
@parameter MovieToActorMap: The map to be printed
*/
void Graph::PrintMap(map<string, vector<Actor>> MovieToActorMap)
{
	//Iterates through the map and prints the movie followed by every actor that
	//had a role in the movie
	for (map<string, vector<Actor> >::iterator ii = MovieToActorMap.begin(); 
		ii != MovieToActorMap.end(); ++ii) {
		cout << (*ii).first << ": ";
		vector<Actor> inVect = (*ii).second;
		for (unsigned j = 0; j < inVect.size(); j++) {
			cout << inVect[j] << " ";
		}
		cout << endl;
	}
}

/*
Method used to find the unique ID of Kevin Bacon in the actorList vector
@parameter actorList: A vector of Actor's
@return A bool value representing if the ID of Kevin Bacon was found in the vector of Actors,
returns true if found, otherwise false.
*/
bool Graph::findKevinBaconID(vector<Actor> actorList, int& KevinBaconID)
{
	//Searches each element of the actorList until Kevin Bacon is found. String
	//matches the input from the file given
	string KevinBacon = "Bacon, Kevin (I)";
	for (int i = 0; i < actorList.size(); i++)
	{
		if (actorList[i].getName() == KevinBacon)
		{
			KevinBaconID = actorList[i].getID();
			return true;
		}
	}
	return false;
}

/*
Method used by the overloaded constructor to create the Adjacency List of each vertex
in the Graph. Uses each Actor in the vector of Actors to represent an individual vertex
@parameter actorList: The vector of Actor's containing each Actor
*/
void Graph::CreateAdjList(vector<Actor> actorList)
{
	//Loops through the actorList and creates an adjacency list for each actor. The actor's in 
	//the list represent vertices in the graph
	for (int i = 0; i < vertices; ++i)
	{
		AdjListNode* newNode = newAdjListNode(actorList[i].getID(), actorList[i]);
		array[i].head = newNode;
		array[i].head->next = nullptr;
	}
}

/*
Method used to insert a Node into an Adjacency List. This represents an added edge between vertices
@parameter dest: The destination vertex
@parameter src: The source parameter
@return A bool value representing whether the Node was successfully inserted. True if the Node was
inserted, otherwise False
*/
bool Graph::InsertNode(int src, int dest)
{
	//Creates a new node with the Actor's information
	AdjListNode* insNode = newAdjListNode(array[dest].head->ID, array[dest].head->actor);
	//If the next node of the adjacency list is nullptr, inserts the node into place
	if (array[src].head->next == nullptr)
	{
		array[src].head->next = insNode;
		return true;
	}
	//If there are more nodes in the Adjacency list than just the head, iterates through the
	//adjacency list until either the actor is found in the list (in which case the actor is
	//not added), or the end of the list has been reached (in which case the actor is added to
	//the end of the list)
	else
	{
		AdjListNode* currentNode = array[src].head->next;
		AdjListNode* prevNode = array[src].head;
		while (currentNode != nullptr)
		{
			if (currentNode->actor == insNode->actor)
			{
				delete insNode;
				return false;
			}
			else
			{
				prevNode = currentNode;
				currentNode = currentNode->next;
			}
		}
		prevNode->next = insNode;
		return true;
	}
}

/*
Method that creates a new Node to be inputted into an Adjacency Node
@parameter ID: The ID of the actor
@parameter actor: The actor to be inserted in the node
@return A pointer to the newly created Node
*/
Graph::AdjListNode* Graph::newAdjListNode(int ID, Actor actor)
{
	AdjListNode* newNode = new AdjListNode(ID, actor, nullptr);
	return newNode;
}
