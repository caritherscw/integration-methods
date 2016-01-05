/*
 * Function.h
 *
 * Function - relation between a set of inputs and a set of
 * outputs. Each input is related to exactly one output. 
 * 
 * param <E> - coefficients
 * param <C> - exponents
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
         // constructors
         Function();
         Function(const std::vector<E> &exponents, const std::vector<C> &coefficients);

         // setters
         void setCoefficient(const int index, const C coefficient);
         void setExponent(const int index, const E exponent);
         void setCoefficients(const std::vector<C> &coefficients);
         void setExponents(const std::vector<E> &exponents);

         // getters
         C getCoefficient(const int index) const;
         E getExponent(const int index) const;
         std::vector<C> getCoefficients() const;
         std::vector<E> getExponents() const;

         // get the max degree of function
         E getDegree() const;

         // virtual because different implementation depending on type of function 
         virtual double evaluate(double x);

         // destructor
         ~Function();

      protected:
         std::vector<E> exponents;
         std::vector<C> coefficients;
   };

   /*
    * overloading << operator to print out the function in a readable format.
    *
    * param out - out buffer store the string
    * param function - function to display
    */
   template <typename E, typename C>
   std::ostream &operator <<(std::ostream &out, Function<E, C> &function);
}



#endif /* FUNCTION_H_ */
