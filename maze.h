#include "vertex.h"
#include "VOList.h"
#include <string>
using namespace std;


class Maze{


private:

	//Initialize private arrays and variables
	Vertex **vertices;
	string player;
	int size;
	int width;
	int length;

	string walls;
	VOList<Vertex>* check;

	int playerI;
	int playerK;

	void initMaze();



public:

	//For any generated maze, the size cannot be more than 31 or less than 1.
	//
	//~~~Few notes:
	//
	//If the size is greater than 31, then size will be set to 31.
	//If the size is less than 1, then size will be set to 1.
	//Maze walls are initially set to full block
	//Shape of the maze is always a square for now.

	//Initialize maze with default having normal walls, and size of 25 (25*25 vertices)
	Maze();

	//Initialize maze with default walls, and size of x (x*x) vertices
	Maze(int x);

	//Initialize maze with walls of string w, and size of x*x
	Maze(int x, string w);

	//Initialize maze with walls and size of x, y
	Maze(int x, int y);

	//Initialize maze with walls of string w, and size of x,y 
	Maze(int x, int y, string w);

	//Delete maze
	~Maze();

	//Print the maze
	void printMaze();

	bool setPlayerUp();
	bool setPlayerDown();
	bool setPlayerRight();
	bool setPlayerLeft();


};//End of maze header