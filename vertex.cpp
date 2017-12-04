#include <string>
#include "vertex.h"
using namespace std;




Vertex::Vertex(){
	shape = " ";
	length = -1;
	previous = -1;
	up = false;
	right = false;
	down = false;
	left = false;
	path = false;
	i = 0;
	k = 0;
}

Vertex::Vertex(int l, int p){
	shape = " ";
	length = l;
	previous = p;
	up = false;
	right = false;
	down = false;
	left = false;

	if (l < 0){
		length = -1;
	}
	if (p < 0){
		previous = -1;
	}

}





string Vertex::getShape() const{
	return shape;
}

int Vertex::getLength() const{
	return length;
}

int Vertex::getPrevious() const{
	return previous;
}

void Vertex::setLength(int l){
	if (l < 0){
		length = -1;
	}
	else{
		length = l;

	}
}

void Vertex::setPrevious(int p){
	if (p < 0){
		previous = -1;
	}
	else{
		previous = p;

	}
}

bool Vertex::getUp() const{
	return up;
}

void Vertex::switchUp(){
	up = !up;
}

bool Vertex::getRight() const{
	return right;
}

void Vertex::switchRight(){
	right = !right;
}

bool Vertex::getDown() const{
	return down;
}

void Vertex::switchDown(){
	down = !down;
}

bool Vertex::getLeft() const{
	return left;
}

void Vertex::switchLeft(){
	left = !left;
}

bool Vertex::getPath() const{
	return path;
}

void Vertex::setPath(){
	path = !path;
}

int Vertex::getI() const{
	return i;
}

int Vertex::getK() const{
	return k;
}

void Vertex::setI(int ik){
	i = ik;
}

void Vertex::setK(int ik){
	k = ik;
}

bool Vertex::operator<(const Vertex & e){

	return true;
}

bool Vertex::operator==(const Vertex & e){

	if (e.getI() == i && e.getK() == k){
		return true;
	}
	else{
		return false;
	}
	
}