/*
 * Term.h
 *
 *  Created on: Jan 15, 2016
 *      Author: chris
 */

#ifndef TERM_H_
#define TERM_H_

#include <string>

class Term {
public:
	Term();
	Term(double coefficient, double exponent);

	//setters
	void setCoefficient(double coefficient);
	void setExponent(double exponent);

	//getters
	double getCoefficient();
	double getExponent();

	virtual double evaluate(double x) = 0;
	virtual Term* derivative() = 0;
	virtual std::string printDerivative() = 0;
	virtual Term* integral() = 0;
	virtual std::string printIntegral() = 0;

	virtual ~Term();

private:
	double coefficient;
	double exponent;
};

#endif /* TERM_H_ */
