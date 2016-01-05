/*
 * Polynomial.h
 *
 * Polynomial - expression consisting of variables and coefficients.
 * Only involves operations of addition, subtraction, multiplication, 
 * and non-negative integer exponents. 
 * 
 * Assumption single variable polynomial
 * Example: 5x^2 - 2/3x + 1
 * @param <E>
 * @param <C>
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
      // constructors
      Polynomial();
      Polynomial(int degree);
      Polynomial(const std::vector<E> &exponents, const std::vector<C> &coefficients);

      /*
       * evaluate - this evaluates the polynomial at the point x
       * using Horner's rule.
       *
       * param x - the point where polynomial is evaluated at
       * return - a double which is the evaluation of the polynomial at point x
       */
      double evaluate(double x);

      // destructors
      ~Polynomial();
   };
}

#endif /* POLYNOMIAL_H_ */
