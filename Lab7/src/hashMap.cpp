/*
 * hashMap.cpp
 *
 *  Created on: May 6, 2018
 *      Author: shawn
 */
#include <iostream>
#include <stdlib.h>
#include <string>
#include <math.h>
#include "HashMap.hpp"
#include <iostream>

// when creating the map, make sure you initialize the values to NULL so you know whether
// that index has a key in it or not already.  The Boolean values initialize the h1 and the
// c1 boolean values, making it easier to control which hash and which collision methods you use.
hashMap::hashMap(bool hash1, bool coll1){
	first = "";
	numKeys = 0;
	mapSize = 27;
	h1 = hash1;
	c1 = coll1;
	collisionct1 = 0;
	collisionct2 = 0;

	map = new hashNode*[mapSize];
	for(int i = 0; i < mapSize; i++){
		map[i] = NULL;
	}
}

// adds a node  to the map at the correct index based on the key string, and then inserts the value into the value field of the hashNode
// Must check to see whether there's a node at that location.  If there's nothing there (it's NULL), add the hashNode with the keyword and value.
// If the node has the same keyword, just add the value to the list of values.
//If the node has a different keyword, keep calculating a new hash index until either the keyword matches the node at that index's keyword, or until the
// map at that index is NULL, in which case you'll add the node there.
//This method also checks for load, and if the load is over 70%, it calls the reHash method to create a new longer map array and rehash the values
//if h1 is true, the first hash function is used, and if it’s false, the second is used.
//if c1 is true, the first collision method is used, and if it’s false, the second is used
void hashMap::addKeyValue(string k, string v){
	int index = getIndex(k);
	if(map[index] == NULL){
		map[index] = new hashNode(k, v);
		numKeys ++;

	}else{
		map[index]->addValue(v);
	}

	if(numKeys >= 0.7*mapSize){
		reHash();
	}
}

// uses calcHash and reHash to calculate and return the index of where the keyword k
// should be inserted into the map array=
int hashMap::getIndex(string k){
	int index;
	if(h1){
		index = calcHash(k);
	}else{
		index = calcHash2(k);
	}

	if(map[index] == NULL || map[index]->keyword == k){
		return index;
	}else{
		collisionct1++;
		if(c1){
			return collHash1(index, k);
		}else{
			return collHash2(index, k);
		}
	}
}

// hash function 1 treats first three characters as base-256 integers
int hashMap::calcHash(string k){
	int index = 0;
	for(int i = 0; i<3 && i<k.length(); i++){
		index += pow(256,i)*int(k[i]);
	}

	return index%mapSize;
}

// hash function 2 finds sum of ASCII values of string
int hashMap::calcHash2(string k){

	int index = 0;

	for(int i = 0; i <k.length(); i++){
		index += int(k[i]);
	}

	return index%mapSize;
}

// I used a binary search on an array of prime numbers to find the closest prime to
// double the map Size, and then set mapSize to that new prime.  You can include as
// one of the fields an array of prime numbers, or you can write a function that
// calculates the next prime number.  Whichever you prefer.
void hashMap::getClosestPrime(){
	int dblSize = 2*mapSize;
	int less = 0;
	int greater = 0;

	for(int i=dblSize-1;less==0;i--){
		if(isPrime(i)){
			less = i;
		}
	}

	for(int i=dblSize+1;greater==0;i++){
		if(isPrime(i)){
			greater = i;
		}
	}

	if(dblSize-less<greater-dblSize){
		mapSize = less;
	}
	else{
		mapSize = greater;
	}
}

bool hashMap::isPrime(int x){	//Helper function for finding closest prime
	bool a = true;
	int divisor = 2;
	if(x>1){
		while((divisor < x) && a){
				if (x % divisor == 0){
					a = false;
				}
				divisor++;
			}
	}
	else{
		a = false;
	}

	return a;
}

// double array size and rehash keys when size hits 70%
void hashMap::reHash(){
	int initSize = mapSize;
	int newIndex;

	getClosestPrime();

	hashNode **tmp = map;

	map = new hashNode*[mapSize];
	for(int i = 0; i < mapSize;i++){
		map[i] = NULL;
	}

	for(int i = 0; i <initSize; i++){
		if(tmp[i] != NULL){
			newIndex = getIndex(tmp[i]->keyword);
			map[newIndex] = tmp[i];
		}
	}
}

// getting index with collision method 1
// method is linear probing
int hashMap::collHash1(int h, string k){
	int index = h;

	while(map[index] != NULL){
		if(map[index]->keyword == k){
			break;
		}
		collisionct2++;
		if(index == mapSize-1){
			index = 0;
		}else{
			index++;
		}
	}
	return index;
}

// getting index with collision method 2
// method is
int hashMap::collHash2(int h, string k){
	int index = h;
	int i = 0;
	while(map[index] != NULL){
		if(map[index]->keyword == k){
			break;
		}

		collisionct2++;
		i++;
		index = (h+(i*i))%mapSize;
	}
	return index;
}

// finds the key in the array and returns its index.  If it's not in the array,
// returns -1
int hashMap::findKey(string k){
	if((getIndex(k) < numKeys) && (map[getIndex(k)] != NULL)){
		return getIndex(k);
	}else{
		return -1;
	}
}

// check
void hashMap::printMap(){
	cout << "First keyword: " << first << endl;
	cout << "numKeys: " << numKeys << endl;
	cout << "mapSize: " << mapSize << endl;
	cout << "h1: " << h1 << endl;
	cout << "c1: " << c1 << endl;
	cout << "collisionct1: " << collisionct1 << endl;
	cout << "collisionct2: " << collisionct2 << endl;
}
