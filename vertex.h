#include <string>
using namespace std;

class Vertex{


private:

	//Initalize variables
	string shape;
	int length;
	int previous;
	bool up;
	bool right;
	bool down;
	bool left;
	bool path;
	int i;
	int k;


public:

	//Initialize vertex.
	Vertex();
	Vertex(int l, int p);

	//Get the shape of the vertex (char)
	string getShape() const;

	//Get length (for future use)
	int getLength() const;

	//Get previous (for future use)
	int getPrevious() const;

	//Set length to l;
	void setLength(int l);

	//Set previous to p
	void setPrevious(int p);

	//Get up to see if it is connected to a vertex above
	bool getUp() const;

	//Get up to see if it is connected to a vertex to the right
	bool getRight() const;

	//Get up to see if it is connected to a vertex below
	bool getDown() const;

	//Get up to see if it is connected to a vertex to the left
	bool getLeft() const;

	//Switch conditions for up, right, left, down.
	void switchUp();
	void switchRight();
	void switchDown();
	void switchLeft();

	//Basically checks if it is visited.
	bool getPath() const;
	void setPath();

	//Location of the vertex in a 2D array.
	int getI() const;
	int getK() const;

	void setI(int i);
	void setK(int k);

	//Use if weighted graph.
	bool operator<(const Vertex & e);
	bool operator==(const Vertex & e);

};