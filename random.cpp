#include <time.h>
#include <stdlib.h>
#include "random.h"

Rand::Rand(){
	t = time(NULL);
}

int Rand::randint(int min, int max){
	//Increment max
	max++;

	//Set the seed in relation to time
	srand(t);

	//Set res to a random value between and including min and max
	int res = (rand() % (max-min)) + min;

	//Update t to get different values
	t = t + (t % 100000);

	//return result
	return res;
}



double Rand::randdef(){
	//Set the seed in relation to time
	srand(t);

	//between 0 and 1
	double res = (rand() / (double)RAND_MAX);

	//Update t to get different values
	t = t + (t % 100000);
	
	//return result
	return res;
}


double Rand::randdouble(double min, double max){

	//randdef
	double def = randdef();

	//between min and max
	double res = (def * (max - min)) + min;

	//return result
	return res;
}
