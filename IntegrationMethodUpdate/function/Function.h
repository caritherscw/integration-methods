/*
 * Function.h
 *
 *  Created on: Jan 15, 2016
 *      Author: chris
 */

#ifndef FUNCTION_FUNCTION_H_
#define FUNCTION_FUNCTION_H_

#include <vector>
#include "../term/Term.h"

class Function {
public:
	Function();
	Function(std::vector<Term*> terms);

	virtual double evaluate(double x) = 0;
	virtual Function* integrate() = 0;
	virtual Function* derivative() = 0;

	virtual ~Function();

private:
	std::vector<Term*> terms;
};

#endif /* FUNCTION_FUNCTION_H_ */
