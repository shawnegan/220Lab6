#ifndef HASHMAP_HPP_
#define HASHMAP_HPP_

#include "hashNode.hpp"

class hashMap {
	friend class makeSeuss;
	hashNode **map;  //a single dimensional dynamically allocated array of pointers to hashNodes

/* NOTE HERE: the map is a dynamically allocated array of nodes.  Meaning it’s a pointer to an array of
pointers to nodes.  I did this so that I could move the addresses around without having to recreate
nodes each time I rehashed.  It looks complicated, but it’s not.  We’ve seen this.
To make the map, you’ll do something to the effect of:
map = new hashNode*[mapSize];
and then you can either set map[i] = NULL or map[i] = new hashNode(k,v);
Make sure you originally set every address in the map array to NULL, and then when you rehash.
 */
	string first; // for first keyword for printing to a file
	int numKeys;
	int mapSize;
	bool h1; // if true, first hash function used, otherwise second hash function is used
	bool c1; //if true, first collision method used, otherwise second collision method is used.
	int collisionct1;  //count of original collisions (caused by the hashing function used)
	int collisionct2; //count of secondary collisions (caused by the collision handling method used)
public:
	hashMap(bool hash1, bool coll1);
	void addKeyValue(string k, string v);
	int getIndex(string k);
	int calcHash(string k);
	int calcHash2(string k);
	void getClosestPrime();
	bool isPrime(int i);
	void reHash();
	int collHash1(int h, string k);
	int collHash2(int h, string k);
	int findKey(string k);
	void printMap();
};

#endif /* HASHMAP_HPP_ */
