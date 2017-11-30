#include <string>
#include <iostream>
#include "maze.h"
using namespace std;



int main(){

	Maze *m = new Maze(20);
	m->printMaze();
	delete m;

	return 0;
}