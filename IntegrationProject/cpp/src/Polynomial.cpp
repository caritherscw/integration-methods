/*
 * Polynomial.cpp
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

#include "Polynomial.h"

using namespace std;

namespace MathFunctions {
   // constructors
   template<typename E, typename C>
   Polynomial<E, C>::Polynomial() {
   }

   template<typename E, typename C>
   Polynomial<E, C>::Polynomial(int degree) {
      for(int index = 0; index <= degree; index++) {
         this->exponents.push_back(index);
         this->coefficients.push_back(0);
      }
   }

   template<typename E, typename C>
   Polynomial<E, C>::Polynomial(const std::vector<E> &exponents, const std::vector<C> &coefficients) {
      this->exponents = exponents;
      this->coefficients = coefficients;
   }

   template <typename E, typename C>
   double Polynomial<E, C>::evaluate(double x) {
      // take the coefficient with highest degree
      double y = this->coefficients[this->coefficients.size() - 1];
      // then each time before adding next coefficient to sum must multiply by x value
      for(int index = this->coefficients.size() - 2; index >= 0; index--) {
         y = this->coefficients[index] + y * x;
      }

      return y;
   }

   // destructor
   template<typename E, typename C>
   Polynomial<E, C>::~Polynomial() {

   }
}
