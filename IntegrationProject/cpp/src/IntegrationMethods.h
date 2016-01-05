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
#include <sstream>

namespace MathFunctions {
   class IntegrationMethods {
      public:

         /**
          * rectangleMethod - produces an approximation of the integral from a to b with
          * n number of columns from the function. This rectangle method uses the midpoint rule
          *
          * param a - starting point to take integral from
          * param b - ending point to take integral to
          * param n - number of columns to divide the integral up
          * param function - the function to integrate using this method
          *
          * returns - returns the approximation of the integral double value
          */
         template <typename E, typename C>
         static double rectangleMethod(double a, double b, int n, Function<E, C> &function);

         /**
          * trapezoidalMethod - produces an approximation of the integral from a to b with
          * n number of columns from the function.
          *
          * param a - starting point to take integral from
          * param b - ending point to take integral to
          * param n - number of columns to divide the integral up
          * param function - the function to integrate using this method
          *
          * returns - returns the approximation of the integral double value
          */
         template <typename E, typename C>
         static double trapezoidalMethod(double a, double b, int n, Function<E, C> &function);

        /**
         * symbolicMethodForPolynomial - produces exact solution of the function.
         *
         * param a - starting point to take integral from
         * param b - ending point to take integral to
         * param function - the function to integrate using this method
         *
         * returns - returns the value of the integral double value
         */
         template <typename E, typename C>
         static double symbolicMethodForPolynomial(double a, double b, Function<E, C> &function);

         /**
          * integralToString - produces a string of the integral function.
          *
          * param function - the function to integrate using this method
          *
          * returns - returns the value of the integral double value
          */
         template <typename E, typename C>
         static std::string integralToString(Function<E, C> &function);
   };
}

#endif /* INTEGRATIONMETHODS_H_ */
