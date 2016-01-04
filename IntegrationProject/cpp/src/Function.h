/*
 * Function.h
 *
 *  Created on: Dec 26, 2015
 *      Author: chris
 */

#ifndef FUNCTION_H_
#define FUNCTION_H_

#include <vector>
#include <iostream>
#include <cmath>

namespace MathFunctions {
	template <typename E, typename C>
	class Function {

	public:
		Function();
		Function(const std::vector<E> &exponents, const std::vector<C> &coefficients);

		void setCoefficient(const int index, const C coefficient);
		void setExponent(const int index, const E exponent);
		void setCoefficients(const std::vector<C> &coefficients);
		void setExponents(const std::vector<E> &exponents);

		C getCoefficient(const int index) const;
		E getExponent(const int index) const;
		std::vector<C> getCoefficients() const;
		std::vector<E> getExponents() const;

		E getDegree() const;

		virtual double evaluate(double x);

		~Function();

	protected:
		std::vector<E> exponents;
		std::vector<C> coefficients;
	};

	template <typename E, typename C>
	std::ostream &operator <<(std::ostream &out, Function<E, C> &function);
}



#endif /* FUNCTION_H_ */
