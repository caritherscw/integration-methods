/*
 * IntegrationMethods.cpp
 *
 *  Created on: Dec 29, 2015
 *      Author: chris
 */
#include "IntegrationMethods.h"

namespace MathFunctions {
template <typename E, typename C>
double IntegrationMethods::rectangleMethod(double a, double b, int n, Function<E, C> &function) {
	double range = b - a;
	double modeOffset = 0.5;
	double sum = 0.0;

	for(int index = 0; index < n; index++) {
		double x = a + range * (index + modeOffset) / n;
		sum += function.evaluate(x);
	}

	return sum * range / n;
}

template <typename E, typename C>
double IntegrationMethods::trapezoidalMethod(double a, double b, int n, Function<E, C> &function) {
	double range = b - a;
	double sum = 0.0;

	for(int index = 1; index < n; index++) {
		double x = a + range * index / n;
		sum += function.evaluate(x);
	}

	sum += (function.evaluate(a) + function.evaluate(b)) / 2.0;

	return sum * range / n;
}


template <typename E, typename C>
double IntegrationMethods::symbolicMethodForPolynomial(double a, double b, Function<E, C> &function) {
	MathFunctions::Polynomial<E, C> newFunction(function.getCoefficients().size());

	for(int index = 0; index < function.getCoefficients().size(); index++) {
		newFunction.setCoefficient(index + 1, function.getCoefficient(index)/(index + 1));
	}

	newFunction.setCoefficient(0, 0.0);

	return (newFunction.evaluate(b) - newFunction.evaluate(a));
}
}