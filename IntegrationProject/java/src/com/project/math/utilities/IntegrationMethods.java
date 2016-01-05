package com.project.math.utilities;

import com.project.math.Function;
import com.project.math.Polynomial;

/**
 * IntegrationMethods - three types of integration in this class. Includes
 * Rectangle Method, Trapezoidal Method, and Symbolic Method.
 */
public class IntegrationMethods {

   /**
    * rectangleMethod - produces an approximation of the integral from a to b with
    * n number of columns from the function. This rectangle method uses the midpoint rule
    *
    * @param a - starting point to take integral from
    * @param b - ending point to take integral to
    * @param n - number of columns to divide the integral up
    * @param function - the function to integrate using this method
    *
    * @returns - returns the approximation of the integral double value
    */
   public static <E, C> double rectangleMethod(double a, double b, int n, Function<E, C> function) {
      double range = b - a;
      double modeOffset = (double) 1 / 2.0;
      double nFloat = (double) n;
      double sum = 0.0;

      for(int index = 0; index < n; index++) {
         double x = a + range * ((double) index + modeOffset) / nFloat;
         sum += function.evaluate(x);
      }

      return sum * range / nFloat;
   }

   /**
    * trapezoidalMethod - produces an approximation of the integral from a to b with
    * n number of columns from the function.
    *
    * @param a - starting point to take integral from
    * @param b - ending point to take integral to
    * @param n - number of columns to divide the integral up
    * @param function - the function to integrate using this method
    *
    * @returns - returns the approximation of the integral double value
    */
   public static <E, C> double trapezoidalMethod(double a, double b, int n, Function<E, C> function) {
      double range = b - a;
      double nFloat = (double) n;
      double sum = 0.0;

      for(int index = 1; index < n; index++) {
         double x = a + range * (double) index / nFloat;
         sum += function.evaluate(x);
      }

      sum += (function.evaluate(a) + function.evaluate(b)) / 2.0;

      return sum * range / nFloat;
   }

   /**
    * symbolicMethod - produces exact solution of the function.
    *
    * @param a - starting point to take integral from
    * @param b - ending point to take integral to
    * @param function - the function to integrate using this method
    *
    * @returns - returns the value of the integral double value
    */
   public static double symbolicMethod(double a, double b, Function<Integer, Double> function) {
      Function<Integer, Double> newFunction = new Polynomial((Polynomial) function);

      // each coefficient is divided by its exponent + 1
      for(int index = 0; index < newFunction.getCoefficient().size(); index++) {
         newFunction.getCoefficient().set(index, newFunction.getCoefficient().get(
            index)/(newFunction.getExponent().get(index) + 1));
      }

      // need to add extra value for the constant exponent since all 
      // exponents add 1
      newFunction.getCoefficient().add(newFunction.getCoefficient().size(), 0.0);

      // evaluate integral at point b and evaluate integral at a then subtract to obtain answer
      return newFunction.evaluate(b) - newFunction.evaluate(a);
   }

   /**
    * integralToString - produces a string of the integral function.
    *
    * @param function - the function to integrate using this method
    *
    * @returns - returns the value of the integral double value
    */
   public static String integralToString(Function<Integer, Double> function) {
      Function<Integer, Double> newFunction = new Polynomial((Polynomial) function);

      for(int index = 0; index < newFunction.getCoefficient().size(); index++) {
         newFunction.getCoefficient().set(index, newFunction.getCoefficient().get(
            index)/(newFunction.getExponent().get(index) + 1));
      }

      newFunction.getCoefficient().add(newFunction.getCoefficient().size(), 0.0);
      return newFunction.toString();
   }
}
