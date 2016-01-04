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

   @Override
   public String toString() {
      StringBuilder polyString = new StringBuilder();

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

   @Override
   protected String coefficientToString(Double coefficient) {
      if(coefficient == 0) {
         return "";
      }
      else {
         return Utilities.fraction(Math.abs(coefficient), 10e-8);
      }
   }

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

   //@Override
   public Double evaluateExponentiationBySquaring(Double x) {
      double y = 0.0;
      for(int index = 0; index < coefficients.size(); index++) {
         if(coefficients.get(index) != 0) {
            y += coefficients.get(index) * Utilities.squaringFunction(x, exponents.get(index));
         }
      }

      return y;
   }

   @Override
   public Double evaluate(Double x) {
      double y = coefficients.get(0);
      for(int index = 1; index < coefficients.size(); index++) {
         y = coefficients.get(index) + y * x;
      }

      return y;
   }

   @Override
   public Polynomial clone() throws CloneNotSupportedException {
      return (Polynomial) super.clone();
   }
}
