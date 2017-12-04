#include <iostream>
#include <string>
#include "ExceptionNotFound.h"

using namespace std;
#pragma once

template <class ElementType>
class VOList{

private:
	ElementType *stock;
	int elementCount;

public:
	VOList();
	~VOList();

	int getElementCount() const;
	bool insert(ElementType toAdd);
	bool remove(ElementType toRemove);
	void removeAll();
	ElementType* retrieve(ElementType toRetrieve) const throw(ExceptionNotFound);
	ElementType* retrieveP(int pos) const throw(ExceptionNotFound);

	void printList();



};


template <class ElementType>
VOList<ElementType>::VOList(){

	stock = new ElementType[10000];
	elementCount = 0;

}

template <class ElementType>
VOList<ElementType>::~VOList(){
	delete[] stock;
}

template <class ElementType>
int VOList<ElementType>::getElementCount() const{
	return elementCount;
}

template <class ElementType>
bool VOList<ElementType>::insert(ElementType toAdd){

	bool ret = true;
	int ipoint = elementCount;
	ElementType temp;

	if (elementCount == 10000){
		ret = false;
	}
	else if (elementCount == 0){
		stock[elementCount] = toAdd;
		elementCount++;
	}
	else{

		for (int i = 0; i < elementCount; i++){
			if (toAdd < stock[i]){
				ipoint = i;
				break;
			}
		}

		for (int i = elementCount; i > ipoint; i--){
			stock[i] = stock[i-1];
		}

		stock[ipoint] = toAdd;
		elementCount++;
	}

	return ret;

}

template <class ElementType>
bool VOList<ElementType>::remove(ElementType toRemove){

	bool ret = true;
	int rpoint = -1;

	if (elementCount == 0){
		ret = false;
	}
	else{
		
		for (int i = 0; i < elementCount; i++){
			if (stock[i] == toRemove){
				rpoint = i;
			}
		}

		if (rpoint == -1){
			ret = false;
		}
		else{

			for (int i = rpoint; i < elementCount; i++){
				stock[i] = stock[i+1];
			}
			elementCount--;



		}

	}

	return ret;

}

template <class ElementType>
void VOList<ElementType>::removeAll(){
	elementCount = 0;
}

template <class ElementType>
ElementType* VOList<ElementType>::retrieve(ElementType toRetrieve) const throw(ExceptionNotFound){

	ElementType* ret = NULL;

	for (int i = 0; i < elementCount; i++){
		if (toRetrieve == stock[i]){
			ret = &stock[i];
		}
	}

	if (ret == NULL){
		throw ExceptionNotFound("VOList retrieve data not found");
	}

	return ret;

}

template <class ElementType>
ElementType* VOList<ElementType>::retrieveP(int pos) const throw(ExceptionNotFound){

	ElementType* ret = NULL;

	if (!(pos >= elementCount)){
		ret = &stock[pos];
	}

	if (ret == NULL){
		throw ExceptionNotFound("VOList retrieve data out of range");
	}

	return ret;

}

template <class ElementType>
void VOList<ElementType>::printList(){

	cout << endl;
	for (int i = 0; i < elementCount; i++){
		cout << "	" << i+1 << ". ";
		cout << stock[i];
		cout << endl;
	}

}