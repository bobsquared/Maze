/*
	Name: Vincent Yu
	2017-06-21
	description: Pretty texts! pretty texts!


*/


#include <string>
#include <sstream>
using namespace std;



template <class ElementType>
class Color{

	public:

		//Takes in a string, and return the string with black text
		string Black(ElementType s);

		//Takes in a string, and return the string with red text
		string Red(ElementType s);

		//Takes in a string, and return the string with green text
		string Green(ElementType s);

		//Takes in a string, and return the string with yellow text
		string Yellow(ElementType s);

		//Takes in a string, and return the string with blue text
		string Blue(ElementType s);

		//Takes in a string, and return the string with magenta text
		string Magenta(ElementType s);

		//Takes in a string, and return the string with cyan text
		string Cyan(ElementType s);

		//Takes in a string, and return the string with White text
		string White(ElementType s);

};





//Description: takes in a string and turn it to the color black
template <class ElementType>
string Color<ElementType>::Black(ElementType s){

	stringstream ss;
	ss << s;
	string temp = ss.str();
	string ret = "\033[1;30m" + temp + "\033[0m";
	return ret;

}


//Description: takes in a string and turn it to the color red
template <class ElementType>
string Color<ElementType>::Red(ElementType s){

	stringstream ss;
	ss << s;
	string temp = ss.str();
	
	string ret = "\033[1;31m" + temp + "\033[0m";
	return ret;

}


//Description: takes in a string and turn it to the color green
template <class ElementType>
string Color<ElementType>::Green(ElementType s){

	stringstream ss;
	ss << s;
	string temp = ss.str();
	string ret = "\033[1;32m" + temp + "\033[0m";
	return ret;

}


//Description: takes in a string and turn it to the color yellow
template <class ElementType>
string Color<ElementType>::Yellow(ElementType s){

	stringstream ss;
	ss << s;
	string temp = ss.str();
	string ret = "\033[1;33m" + temp + "\033[0m";
	return ret;

}


//Description: takes in a string and turn it to the color blue
template <class ElementType>
string Color<ElementType>::Blue(ElementType s){

	stringstream ss;
	ss << s;
	string temp = ss.str();
	string ret = "\033[1;34m" + temp + "\033[0m";
	return ret;

}


//Description: takes in a string and turn it to the color magenta
template <class ElementType>
string Color<ElementType>::Magenta(ElementType s){

	stringstream ss;
	ss << s;
	string temp = ss.str();
	string ret = "\033[1;35m" + temp + "\033[0m";
	return ret;

}


//Description: takes in a string and turn it to the color cyan
template <class ElementType>
string Color<ElementType>::Cyan(ElementType s){

	stringstream ss;
	ss << s;
	string temp = ss.str();
	string ret = "\033[1;36m" + temp + "\033[0m";
	return ret;

}


//Description: takes in a string and turn it to the color white
template <class ElementType>
string Color<ElementType>::White(ElementType s){

	stringstream ss;
	ss << s;
	string temp = ss.str();
	string ret = "\033[1;37m" + temp + "\033[0m";
	return ret;

}
