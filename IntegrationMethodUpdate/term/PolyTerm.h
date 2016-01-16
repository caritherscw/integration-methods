/*
 * PolyTerm.h
 *
 *  Created on: Jan 15, 2016
 *      Author: chris
 */

#ifndef TERM_POLYTERM_H_
#define TERM_POLYTERM_H_

#include <string>
#include "../term/Term.h"
#include "../Utilities.h"

class PolyTerm: public Term {
public:
	PolyTerm();
	PolyTerm(double coefficient, int exponent);

	virtual double evaluate(double x);
	virtual PolyTerm* derivative();
	virtual std::string printDerivative();
	virtual PolyTerm* integral();
	virtual std::string printIntegral();

	virtual ~PolyTerm();
};

#endif /* TERM_POLYTERM_H_ */
