/*
 * hashNode.cpp
 *
 *  Created on: May 6, 2018
 *      Author: shawn
 */

#include "hashNode.hpp"
#include <stdlib.h>
#include <iostream>
#include <math.h>

// constructor-initializes keyword to “” , valuesSize to 0, and currSize to
// 0 and values to NULL
hashNode::hashNode() {
	keyword = "";
	values = NULL;
	valuesSize = 0;
	currSize = 0;

}
// initializes keyword to s, the valuesSize to 100 (or whatever you like for
// starting), the currSize to 0, and the values to be a dynamically allocated
// array of valuesSize
hashNode::hashNode(string s){
	keyword = s;
	valuesSize = 100;
	currSize = 0;
	values = new string[valuesSize];
}

// in addition, puts a value in the values array and initializes currSize to 1
hashNode::hashNode(string s, string v){
	keyword = s;
	valuesSize = 100;
	currSize = 1;
	values = new string[valuesSize];
	values[0] = v;
}

// adds a new value to the end of the values array, increases currSize,
// checks to make sure there’s more space, and, if not, calls dblArray()
void hashNode::addValue(string v){
	values[currSize] = v;
	currSize ++;
	if(currSize == valuesSize){
		dblArray();
	}
}

// creates a new array, double the length, and copies over the values.
// Sets the values array to be the newly allocated array.
void hashNode::dblArray(){
	string *newArray = new string[valuesSize*2];
	for(int i = 0; i < currSize ; i++){
		newArray[i] = values[i];
	}
	values = newArray;
	valuesSize *= 2;
}

// returns a random string from the values array.  If there’s no values
// in the value array, then it returns an empty string.
string hashNode::getRandValue(){
	if(currSize == 0){
		return "";
	}
	int x = rand()%currSize;
	return values[x];
}

void hashNode::printHNode(){
	cout << keyword << ":";
	for(int i=0;i<currSize;i++){
		cout << values[i] << ",";
	}
	cout << endl;
}
