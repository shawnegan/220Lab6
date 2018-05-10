/* Names : Shawn Egan, Justin Schnee
 * TA : Ajith Vemuri
 * Date : 5/9/18
 * Lab : 7
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "makeSeuss.hpp"

using namespace std;
int main() {
	srand(time(NULL));
	makeSeuss("DrSeuss.txt", "H1C1.txt", true, true); //hash 1 and collision 1
	makeSeuss("DrSeuss.txt", "H1C2.txt", true, false); //hash 1 and collision 2
	makeSeuss("DrSeuss.txt", "H2C1.txt", false, true); //hash 2 and collision 1
	makeSeuss("DrSeuss.txt", "H2C2.txt", false, false); //hash 2 and collision 2

}
