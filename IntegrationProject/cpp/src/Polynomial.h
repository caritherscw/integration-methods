/*
 * Polynomial.h
 *
 *  Created on: Dec 26, 2015
 *      Author: chris
 */

#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include "Function.h"

namespace MathFunctions {
	template<typename E, typename C>
	class Polynomial : public Function<E, C> {

	public:
		Polynomial();
		Polynomial(int degree);
		Polynomial(const std::vector<E> &exponents, const std::vector<C> &coefficients);

		double evaluate(double x);
		
		~Polynomial();
	};
}

#endif /* POLYNOMIAL_H_ */
