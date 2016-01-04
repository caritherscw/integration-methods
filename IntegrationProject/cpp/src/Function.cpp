/*
 * Function.cpp
 *
 *  Created on: Dec 26, 2015
 *      Author: chris
 */

#include "Function.h"
#include "Utilities.h"

namespace MathFunctions {
	template <typename E, typename C>
	Function<E, C>::Function() {

	}

	template <typename E, typename C>
	Function<E, C>::Function(const std::vector<E> &exponents, const std::vector<C> &coefficients) {
		this->exponents = exponents;
		this->coefficients = coefficients;
	}

	template <typename E, typename C>
	void Function<E, C>::setCoefficient(const int index, const C coefficient) {
		this->coefficients[index] = coefficient;
	}

	template <typename E, typename C>
	void Function<E, C>::setExponent(const int index, const E exponent) {
		this->exponents[index] = exponent;
	}

	template <typename E, typename C>
	void Function<E, C>::setCoefficients(const std::vector<C> &coefficients) {
		this->coefficients = coefficients;
	}

	template <typename E, typename C>
	void Function<E, C>::setExponents(const std::vector<E> &exponents) {
		this->exponents = exponents;
	}

	template <typename E, typename C>
	C Function<E, C>::getCoefficient(const int index) const {
		return this->coefficients[index];
	}

	template <typename E, typename C>
	E Function<E, C>::getExponent(const int index) const {
		return this->exponents[index];
	}

	template <typename E, typename C>
	std::vector<C> Function<E, C>::getCoefficients() const {
		return this->coefficients;
	}

	template <typename E, typename C>
	std::vector<E> Function<E, C>::getExponents() const {
		return this->exponents;
	}

	template<typename E, typename C>
	E Function<E, C>::getDegree() const {
		return this->exponents[exponents.size() - 1];
	}

	template <typename E, typename C>
	Function<E, C>::~Function() {

	}

	template <typename E, typename C>
	double Function<E, C>::evaluate(double x) {}
	
	template <typename E, typename C>
	std::ostream &operator <<(std::ostream &out, Function<E, C> &function) {
		if(function.getDegree() == -1) {
			out << 0;
			return out;
		}
		else if(function.getDegree() == 0) {
			out << Utilities::fraction(function.getCoefficient(0), 0.00001);
			return out;
		}
		else {
			// do nothing and continue
		}

		int indexFirstNonZero = function.getCoefficients().size() - 1;
		while(function.getCoefficient(indexFirstNonZero) == 0) {
			indexFirstNonZero--;
		}

		if(function.getCoefficient(indexFirstNonZero) < 0.0 && function.getCoefficient(indexFirstNonZero) != -1) {
			out << "-" << Utilities::fraction(std::abs(function.getCoefficient(indexFirstNonZero)), 0.00001);
		}
		else if(function.getCoefficient(indexFirstNonZero) > 0.0 && function.getCoefficient(indexFirstNonZero) != 1) {
			out << Utilities::fraction(function.getCoefficient(indexFirstNonZero), 0.00001);
		}
		else if(function.getCoefficient(indexFirstNonZero) < 0.0 && function.getCoefficient(indexFirstNonZero) == -1) {
			out << "-";
		}
		else if(function.getCoefficient(indexFirstNonZero) > 0.0 && function.getCoefficient(indexFirstNonZero) == 1) {
			out << "";
		}
		else {
			// coefficient is 0 do nothing
		}

		if(function.getExponent(indexFirstNonZero) == 0) {
			// exponent 0 do not print x
		}
		else if(function.getExponent(indexFirstNonZero) == 1) {
			out << "x";
		}
		else {
			out << "x^" << Utilities::fraction(function.getExponent(indexFirstNonZero), 0.00001);
		}

		for(int index = indexFirstNonZero - 1; index >= 0; index--) {
			if(function.getCoefficient(index) != 0) {
				if(function.getCoefficient(index) < 0.0 && function.getCoefficient(index) != -1) {
					out << " - " << Utilities::fraction(std::abs(function.getCoefficient(index)), 0.00001);
				}
				else if(function.getCoefficient(index) > 0.0 && function.getCoefficient(index) != 1) {
					out << " + " << Utilities::fraction(function.getCoefficient(index), 0.00001);
				}
				else if(function.getCoefficient(index) < 0.0 && function.getCoefficient(index) == -1 && index != 0) {
					out << " - ";
				}
				else if(function.getCoefficient(index) > 0.0 && function.getCoefficient(index) == 1 && index != 0) {
					out << " + ";
				}
				else if(function.getCoefficient(index) < 0.0 && function.getCoefficient(index) == -1 && index == 0) {
					out << " - 1";
				}
				else {
					out << " + 1";
				}

				if(function.getExponent(index) == 0) {
					// exponent 0 do not print x
				}
				else if(function.getExponent(index) == 1 && function.getCoefficient(index) != 0) {
					out << "x";
				}
				else {
					out << "x^" << Utilities::fraction(function.getExponent(index), 0.00001);
				}
			}
		}

		return out;
	}
}
