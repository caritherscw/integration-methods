/*
 * Utilities.h
 *
 *  Created on: Jan 15, 2016
 *      Author: chris
 */

#ifndef UTILITIES_H_
#define UTILITIES_H_

#include <sstream>

class Utilities {
public:
	Utilities();

	static double exponentiationBySquaring(double x, int n);
	static std::string convertIntToString(int number);
	static std::string convertDoubleToString(double number);

	virtual ~Utilities();
};

#endif /* UTILITIES_H_ */
