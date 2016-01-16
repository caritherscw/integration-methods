/*
 * Term.cpp
 *
 *  Created on: Jan 15, 2016
 *      Author: chris
 */

#include "../term/Term.h"

Term::Term() {

}

Term::Term(double coefficient, double exponent) {
	this->coefficient = coefficient;
	this->exponent = exponent;
}

void Term::setCoefficient(double coefficient) {
	this->coefficient = coefficient;
}

void Term::setExponent(double exponent) {
	this->exponent = exponent;
}

double Term::getCoefficient() {
	return this->coefficient;
}

double Term::getExponent() {
	return this->exponent;
}

Term::~Term() {

}

