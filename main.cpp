#include <string>
#include <iostream>
#include "maze.h"
#include "colors.h"

using namespace std;


//Gives the player a choice between 0 and num-1 (num choices)
int choice(string text1, int num){

	//Check if num is less than 2, then make it equal to 2 if true.
	if (num < 2){
		num = 2;
	}

	//initialize
	Color<string> cs = Color<string>();
	string text2 = cs.White(text1);
	int res1 = -1;
	string res2;

	//While res1 >= num and res1 < 0, repeat the loop
	while (res1 >= num || res1 < 0){

		cout << text2;
		cin >> res2;

		//Try string to integer
		try{

			res1 = stoi(res2);

			//if successful, check if it is within the range.
			if (res1 >=num || res1 < 0){
				cout << endl << cs.Yellow("That number is not within the range, please try again.") << endl << endl;
			}
		}
		//Catch the string isn't an integer.
		catch(exception){
			cout << endl << cs.Yellow("That is not a number, please try again.") << endl << endl;
		}

	}
	//return res1
	return res1;

}

//Gives the player a choice between 0 and num-1 (num choices)
int wasd(string text1){

	//Check if num is less than 2, then make it equal to 2 if true.
	int num = 4;

	//initialize
	Color<string> cs = Color<string>();
	string text2 = cs.White(text1);
	int res1 = -1;
	string res2;

	//While res1 >= num and res1 < 0, repeat the loop
	while (res1 >= num || res1 < 0){

		cout << text2;
		cin >> res2;

		if (res2 == "w"){
			res2 = "0";
		}
		if (res2 == "s"){
			res2 = "1";
		}
		if (res2 == "d"){
			res2 = "2";
		}
		if (res2 == "a"){
			res2 = "3";
		}

		//Try string to integer
		try{

			res1 = stoi(res2);

			//if successful, check if it is within the range.
			if (res1 >=num || res1 < 0){
				cout << endl << cs.Yellow("That number is not within the range, please try again.") << endl << endl;
			}
		}
		//Catch the string isn't an integer.
		catch(exception){
			cout << endl << cs.Yellow("That is not a number, please try again.") << endl << endl;
		}

	}
	//return res1
	return res1;

}


int main(){

	Maze *m = new Maze(25,25);
	int choose;
	while (true){
		m->printMaze();
		choose = wasd("\nWhich way would you like to go? 0: up, 1: down, 2: right, 3: left: ");

		switch (choose){
			case 0:
				m->setPlayerUp();
				break;
			case 1:
				m->setPlayerDown();
				break;
			case 2:
				m->setPlayerRight();
				break;
			case 3:
				m->setPlayerLeft();
				break;
		}
	}
	m->printMaze();

	delete m;


	return 0;
}