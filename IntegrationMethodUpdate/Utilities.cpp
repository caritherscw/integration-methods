/*
 * Utilities.cpp
 *
 *  Created on: Jan 15, 2016
 *      Author: chris
 */

#include "Utilities.h"

Utilities::Utilities() {

}

double Utilities::exponentiationBySquaring(double x, int n) {
	if(n < 0) {
		x = 1 / x;
		n = -n;
	}

	if(n == 0) {
		return 1;
	}

	double y = 1;
	while (n > 1) {
		if(n % 2 == 0) {
			x = x * x;
			n = n /2;
		}
		else {
			y = x * y;
			x = x * x;
			n = (n - 1) / 2;
		}
	}

	return x * y;
}

std::string Utilities::convertIntToString(int number) {
	std::stringstream ss;
	ss.clear();
	ss << number;
	return ss.str();
}

std::string Utilities::convertDoubleToString(double number) {
	std::stringstream ss;
	ss.clear();
	ss << number;
	return ss.str();
}

Utilities::~Utilities() {

}

