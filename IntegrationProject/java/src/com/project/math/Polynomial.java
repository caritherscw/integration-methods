package com.project.math;
import java.util.ArrayList;
import java.util.List;
import com.project.math.utilities.Utilities;

/**
 * Polynomial - expression consisting of variables and coefficients.
 * Only involves operations of addition, subtraction, multiplication, 
 * and non-negative integer exponents. 
 * 
 * Assumption single variable polynomial
 * Example: 5x^2 - 2/3x + 1
 * @param <E>
 * @param <E>
 * @param <C>
 * @param <C>
 */
public class Polynomial<E extends Integer, C extends Double> 
   extends Function<E, C> implements Cloneable{

   // Constructors
   public Polynomial() {
      super();
   }

   public Polynomial(List<E> exponents, List<C> coefficients) {
      super(exponents, coefficients);
   }

   public Polynomial(Polynomial polynomial) {
      this.exponents = new ArrayList<E>(polynomial.exponents);
      this.coefficients = new ArrayList<C>(polynomial.coefficients);
   }

   /**
    * toString - creates the polynomial as a readable string to print
    * to the screen.
    *
    * returns - polynomial as a readable string
    *
   */
   @Override
   public String toString() {
      StringBuilder polyString = new StringBuilder();

      // depending on value of the exponent and coefficient print correct value
      // example if coefficient was 1 and exponent was 1 it would print x instead of
      // 1x^1
      for(int index = 0; index < exponents.size(); index++) {
         if(polyString.length() == 0) {
            if(coefficients.get(index) != 0) {
               if(coefficients.get(index) > 1 || (coefficients.get(index) < 1 
                     && coefficients.get(index) > 0)) {
                  polyString.append(coefficientToString(coefficients.get(index)) 
                     + exponentToString(exponents.get(index)));
               }
               else if(coefficients.get(index) == 1 && exponents.get(index) != 0) {
                  polyString.append(exponentToString(exponents.get(index)));
               }
               else if(coefficients.get(index) == 1 && exponents.get(index) == 0) {
                  polyString.append(coefficientToString(coefficients.get(index)));
               }
               else if(coefficients.get(index) == -1 && exponents.get(index) != 0) {
                  polyString.append("-" + exponentToString(exponents.get(index)));
               }
               else if(coefficients.get(index) == -1 && exponents.get(index) == 0) {
                  polyString.append("-" + coefficientToString(coefficients.get(index)));
               }
               else {
                  polyString.append("-" + coefficientToString(coefficients.get(index)) 
                     + exponentToString(exponents.get(index)));
               }
            }
         }
         else {
            if(coefficients.get(index) != 0) {
               if(coefficients.get(index) > 1 || (coefficients.get(index) < 1 
                     && coefficients.get(index) > 0)) {
                  polyString.append(" + " + coefficientToString(coefficients.get(index)) 
                     + exponentToString(exponents.get(index)));
               }
               else if(coefficients.get(index) == 1 && exponents.get(index) != 0) {
                  polyString.append(" + " + exponentToString(exponents.get(index)));
               }
               else if(coefficients.get(index) == 1 && exponents.get(index) == 0) {
                  polyString.append(" + " + coefficientToString(coefficients.get(index)));
               }
               else if(coefficients.get(index) == -1 && exponents.get(index) != 0) {
                  polyString.append(" - " + exponentToString(exponents.get(index)));
               }
               else if(coefficients.get(index) == -1 && exponents.get(index) == 0) {
                  polyString.append(" - " + coefficientToString(coefficients.get(index)));
               }
               else {
                  polyString.append(" - " + coefficientToString(coefficients.get(index)) 
                     + exponentToString(exponents.get(index)));
               }
            }
         }
      }

      return polyString.toString();
   }

   /**
    * coefficientToString - detemine what needs to be printed for coefficient
    * this will allow to create the create fraction from double. Otherwise
    * if coefficient is 0 then should return empty string.
    *
    * @param coefficient - receives double value
    * @return - returns a string representation of the coefficient
    */
   @Override
   protected String coefficientToString(Double coefficient) {
      if(coefficient == 0) {
         return "";
      }
      else {
         return Utilities.fraction(Math.abs(coefficient), 10e-8);
      }
   }

   /**
    * exponentToString - detemine what needs to be printed for exponent. 
    * if exponent is 0 then should return empty string.
    * if exponent is 1 then return x, otherwise if exponent > 1 then
    * return the x^exponent
    *
    * @param exponent - receives integer value
    * @return - returns a string representation of the exponent
    */
   @Override
   protected String exponentToString(Integer exponent) {
      if(exponent == 0)
      {
         return "";
      }
      else if(exponent == 1) {
         return "x";
      }
      else {
         return "x^" + exponent;
      }
   }

   /**
    * evaluateExponentiationBySquaring - this solve the polynomial at point x.
    * To solve the polynomial at x it uses method called exponentiation by squaring.
    * This is not used in the program since the Horner's rule used in the evaluate function
    * is computationally better.
    *
    * @param x - receives a double value
    * @return - returns evaluation of polynomial at x as double
    */
   public Double evaluateExponentiationBySquaring(Double x) {
      double y = 0.0;
      for(int index = 0; index < coefficients.size(); index++) {
         if(coefficients.get(index) != 0) {
            y += coefficients.get(index) * Utilities.squaringFunction(x, exponents.get(index));
         }
      }

      return y;
   }

   /**
    * evaluate - evaluate a polynomial at the value x using the Horner's rule.
    *
    * @param x - receives a double value
    * @return - returns evaluation of polynomial at x as double
    */
   @Override
   public Double evaluate(Double x) {
      double y = coefficients.get(0);
      for(int index = 1; index < coefficients.size(); index++) {
         y = coefficients.get(index) + y * x;
      }

      return y;
   }

   /**
    * clone - allows a hard copy instead of shallow copy of the instance
    * of the polynomial.
    */
   @Override
   public Polynomial clone() throws CloneNotSupportedException {
      return (Polynomial) super.clone();
   }
}
