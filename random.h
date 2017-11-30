#include <time.h>



class Rand{

	private:

		//Time_t t to keep the whole thing
		time_t t;
		
	public:

		//Default constructor
		Rand();

		//Description: takes two integers, and randint will take a random number between them
		//O(1)
		int randint(int min,int max);

		//Description: returns random double between 0 and 1
		//O(1)
		double randdef();

		//Description: returns double between min and max
		//O(1)
		double randdouble(double min, double max);

};//End of Rand header