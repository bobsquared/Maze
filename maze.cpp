#include "maze.h"
#include "random.h"
#include <time.h>
#include "colors.h"


using namespace std;


Maze::Maze(){


	//Change this string to change the walls of the maze.
	walls = "\u2588";	
	player = "#";

	//Change the size of the maze.
	width = 25;
	length = 25;


	//Create 2D array of vertices
	const int w = width;
	const int l = length;

	vertices = new Vertex*[width];
	for (int i = 0; i < width; i++){
		vertices[i] = new Vertex[length];
	}

	//Initalize maze
	initMaze();




}

Maze::Maze(int x){


	//Change this string to change the walls of the maze.
	walls = "\u2588";
	player = "#";	

	//size conditions of the maze
	if (x < 1){
		x = 1;
	}
	else if (x > 100){
		x = 100;
	}

	width = x;
	length = x;

	//Create 2D array of vertices
	const int w = width;
	const int l = length;

	vertices = new Vertex*[width];
	for (int i = 0; i < width; i++){
		vertices[i] = new Vertex[length];
	}

	//Initalize maze
	initMaze();




}

Maze::Maze(int x, string wa){

	walls = wa;
	player = "#";	

	//size conditions of the maze
	if (x < 1){
		x = 1;
	}
	else if (x > 100){
		x = 100;
	}
	width = x;
	length = x;
	//Create 2D array of vertices
	const int w = width;
	const int l = length;

	vertices = new Vertex*[width];
	for (int i = 0; i < width; i++){
		vertices[i] = new Vertex[length];
	}

	//Initalize maze
	initMaze();




}

Maze::Maze(int x, int y){

	walls = "\u2588";
	player = "\u2588";	

	//size conditions of the maze
	if (x < 1){
		x = 1;
	}
	else if (x > 100){
		x = 100;
	}

	if (y < 1){
		y = 1;
	}
	else if (y > 100){
		y = 100;
	}

	width = x;
	length = y;
	//Create 2D array of vertices
	const int w = width;
	const int l = length;

	vertices = new Vertex*[width];
	for (int i = 0; i < width; i++){
		vertices[i] = new Vertex[length];
	}

	//Initalize maze
	initMaze();




}

Maze::Maze(int x, int y, string wa){

	walls = wa;	
	player = "#";

	//size conditions of the maze
	if (x < 1){
		x = 1;
	}
	else if (x > 100){
		x = 100;
	}

	if (y < 1){
		y = 1;
	}
	else if (y > 100){
		y = 100;
	}

	width = x;
	length = y;
	//Create 2D array of vertices
	const int w = width;
	const int l = length;

	vertices = new Vertex*[width];
	for (int i = 0; i < width; i++){
		vertices[i] = new Vertex[length];
	}

	//Initalize maze
	initMaze();




}

Maze::~Maze(){

	for (int i = 0; i < width; i++){
		delete [] vertices[i];
		vertices[i] = NULL;
	}
	delete [] vertices;
	vertices = NULL;

}

//Randomly generate the maze of with size.
//Maze is generated using Prim's algorithm

void Maze::initMaze(){

	//Initialize variables.
	playerI = 0;
	playerK = 0;
	Rand r = Rand();
	bool up,down,right,left;
	int i = 0;
	int k = 0;

	//Set the all the vertices' location into the vertex
	for (i = 0; i < width; i++){

		for (k = 0; k < length; k++){
			Vertex v = Vertex();
			v.setI(i);
			v.setK(k);
			vertices[i][k] = v;

		}
		

	}


	//Set vertex (0,0) as visited, and insert into list.
	check = new VOList<Vertex>();

	vertices[0][0].setPath();
	check->insert(vertices[0][0]);

	Vertex* temp = new Vertex();

	while (width*length > check->getElementCount()){

		//randomly pick a vertex in the list, and get its location.
		int set = r.randint(0,check->getElementCount()-1);
		temp = check->retrieveP(set);
		i = temp->getI();
		k = temp->getK();

		up = true;
	    right = true;
	    down = true;
	    left = true;

	    //Conditions for a path to be unavailiable.

	    //if at the top of the maze
		if (i <= 0){
			up = false;
		}

		//if at the border left of the maze
		if (k <= 0){
			left = false;
		}

		//if at the border right of the maze
		if (k >= length-1){
			right = false;
		}

		//if at the bottom of the maze
		if (i >= width-1){
			down = false;
		}

		

		int l = r.randint(0,3);

		//for each case, if condition is true and the vertex that you are trying to get to is not visited
		//then set that vertex as visited and add it to the list.
		switch (l){

			case 0:
				if (up && !vertices[i-1][k].getPath()){
					vertices[i-1][k].setPath();
					vertices[i][k].switchUp();
					vertices[i-1][k].switchDown();
					check->insert(vertices[i-1][k]);
				}
				break;

			case 1:
				if (down && !vertices[i+1][k].getPath()){
					vertices[i+1][k].setPath();
					vertices[i][k].switchDown();
					vertices[i+1][k].switchUp();
					check->insert(vertices[i+1][k]);
				}
				break;

			case 2:
				if (left && !vertices[i][k-1].getPath()){
					vertices[i][k-1].setPath();
					vertices[i][k].switchLeft();
					vertices[i][k-1].switchRight();
					check->insert(vertices[i][k-1]);
				}
				break;

			case 3:
				if (right && !vertices[i][k+1].getPath()){
					vertices[i][k+1].setPath();
					vertices[i][k].switchRight();
					vertices[i][k+1].switchLeft();
					check->insert(vertices[i][k+1]);
				}
				break;
		}

		
		
	}

	//delete temp;
	delete check;


}


//Once the maze is initialized, print the maze.
//Probably did some shit coding here tbh but it works.
void Maze::printMaze(){

	Color<string> cs = Color<string>();
	int j = 0;
	//Print top border
	for (int i = 0; i < (length*3 - 1); i++){
		cout << walls;
	}

	//And then I did something and i forgot what i did cause i didn't put comments while writing it.
	for (int i = 0; i < width; i++){

		if (i != 0){
			cout << walls;
		}

		for (int j = 0; j < length; j++){

			if (i !=0 && vertices[i][j].getUp()){
				
				if (j != length-1){
					cout << " " << walls << walls;
				}
				else{
					cout << " ";
				}
					
				
			}		
			else if (i != 0){
				
				if (j != length-1){
					cout << walls << walls << walls;
				}
				else{
					cout << walls;
				}
					
				
			}
		}

		cout << walls << endl << walls;

		for (int k = 0; k < length; k++){
			
			if (playerI == i && playerK == k){
				cout << cs.Red(player);
			}
			else{
				cout << vertices[i][k].getShape();
			}

			if (k != length-1 && vertices[i][k].getRight()){
				cout << "  ";
			}
			else if (k!= length-1){
				cout << walls << walls;
			}

		}
		cout << walls << endl;

	}

	for (int i = 0; i < (length*3); i++){
		cout << walls;
	}
	cout << endl;

}

bool Maze::setPlayerUp(){
	bool ret = false;
	if (vertices[playerI][playerK].getUp()){
		playerI--;
		ret = true;
	}

	return ret;

}

bool Maze::setPlayerDown(){
	bool ret = false;
	if (vertices[playerI][playerK].getDown()){
		playerI++;
		ret = true;
	}

	return ret;

}

bool Maze::setPlayerRight(){
	bool ret = false;
	if (vertices[playerI][playerK].getRight()){
		playerK++;
		ret = true;
	}

	return ret;

}

bool Maze::setPlayerLeft(){
	bool ret = false;
	if (vertices[playerI][playerK].getLeft()){
		playerK--;
		ret = true;
	}

	return ret;

}
