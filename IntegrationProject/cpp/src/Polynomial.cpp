/*
 * Polynomial.cpp
 *
 *  Created on: Dec 26, 2015
 *      Author: chris
 */

#include "Polynomial.h"

using namespace std;

namespace MathFunctions {
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
      double y = this->coefficients[this->coefficients.size() - 1];
      for(int index = this->coefficients.size() - 2; index >= 0; index--) {
         y = this->coefficients[index] + y * x;
      }

      return y;
   }

   template<typename E, typename C>
   Polynomial<E, C>::~Polynomial() {

   }
}
