/*
 * PolyTerm.cpp
 *
 *  Created on: Jan 15, 2016
 *      Author: chris
 */

#include "../term/PolyTerm.h"

PolyTerm::PolyTerm() : Term::Term(){

}

PolyTerm::PolyTerm(double coefficient, int exponent) : Term::Term(coefficient, exponent) {

}

double PolyTerm::evaluate(double x) {
	return this->getCoefficient() * Utilities::exponentiationBySquaring(x, this->getExponent());
}

PolyTerm* PolyTerm::derivative() {
	PolyTerm* polyTerm = new PolyTerm();
	polyTerm->setExponent(this->getExponent() - 1);
	polyTerm->setCoefficient(this->getCoefficient() * this->getExponent());
	return polyTerm;
}

std::string PolyTerm::printDerivative() {
	PolyTerm* polyTerm = this->derivative();
	std::string polyTermString = Utilities::convertDoubleToString(polyTerm->getCoefficient()) + "x^" +
			Utilities::convertDoubleToString(polyTerm->getExponent());
	delete polyTerm;
	return polyTermString;
}

PolyTerm* PolyTerm::integral() {
	PolyTerm* polyTerm = new PolyTerm();
	polyTerm->setExponent(this->getExponent() + 1);
	polyTerm->setCoefficient(this->getCoefficient() / polyTerm->getExponent());
	return polyTerm;
}

std::string PolyTerm::printIntegral() {
    PolyTerm* polyTerm = this->integral();
	std::string polyTermString = Utilities::convertDoubleToString(polyTerm->getCoefficient()) + "x^" +
			Utilities::convertDoubleToString(polyTerm->getExponent());
	delete polyTerm;
	return polyTermString;
}

PolyTerm::~PolyTerm() {

}

