/*
 * Main.cpp
 *
 *  Created on: Jan 15, 2016
 *      Author: chris
 */

#include <iostream>
#include "term/PolyTerm.h"

using namespace std;

int main() {

	PolyTerm polyTerm(2, 5);

	cout << polyTerm.evaluate(2) << endl;
	cout << polyTerm.printDerivative() << endl;
	cout << polyTerm.printIntegral() << endl;

	return 0;
}
