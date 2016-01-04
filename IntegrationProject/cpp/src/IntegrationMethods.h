/*
 * IntegrationMethods.h
 *
 *  Created on: Dec 29, 2015
 *      Author: chris
 */

#ifndef INTEGRATIONMETHODS_H_
#define INTEGRATIONMETHODS_H_

#include "Function.h"
#include "Function.cpp"
#include "Polynomial.h"
#include "Polynomial.cpp"

namespace MathFunctions {
   class IntegrationMethods {
      public:
         template <typename E, typename C>
         static double rectangleMethod(double a, double b, int n, Function<E, C> &function);
         template <typename E, typename C>
         static double trapezoidalMethod(double a, double b, int n, Function<E, C> &function);
         template <typename E, typename C>
         static double symbolicMethodForPolynomial(double a, double b, Function<E, C> &function);
   };
}

#endif /* INTEGRATIONMETHODS_H_ */
