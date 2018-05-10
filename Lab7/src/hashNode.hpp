/*
 * hashNode.hpp
 *
 *  Created on: May 6, 2018
 *      Author: shawn
 */

#ifndef HASHNODE_HPP_
#define HASHNODE_HPP_
#include <string>
using namespace std;

class hashNode {
	friend class hashMap;
	string keyword;   // this is used as the key – each key is only inserted once!

	string *values;   // the dynamically allocated array (not linked list!) of words that
					 // follow the key in the Dr. Seuss text.  If this set of words gets
					// to be larger than the valuesSize of the array, then you must re-allocate
					//the array double in size and copy over all the old values
	int valuesSize;  // the size of the values array
	int currSize;  // the number of words in the values array so far
public:
	hashNode();
	hashNode(string s);
	hashNode(string s, string v);
	void addValue(string v);
	void dblArray();
	string getRandValue();
	void printHNode();
};

#endif /* HASHNODE_HPP_ */
