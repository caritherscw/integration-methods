package com.project.math.utilities;
import java.math.BigDecimal;
import java.math.MathContext;
import java.text.ParseException;
import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Scanner;

/**
 * Utilities - methods to help with what could be duplicate code
 * within the main method. Suche methods include convert fraction to double,
 * double to fraction, and validate input. 
 */
public class Utilities {
   /**
    * Converts a decimal to a fraction using continued fractions.
    * 
    * @param decimal - the decimal value to convert
    * @param - tolerance the accuracy of the conversion 
    * @return - a representation of the decimal as a fraction
    */
   public static String fraction(double decimal, double tolerance) 
   {
      int sign = (decimal<0.0) ? -1 : 1;
      decimal = Math.abs(decimal);

      if (decimal == (int)decimal)
      {
         return (sign * (int)decimal + "");
      }

      double res = decimal, num=0.0, denom=1.0, lastdenom=0.0, temp;
      do {
         res = 1.0 / (res - (int)res);
         temp = denom;
         denom = denom * (int)res + lastdenom;
         lastdenom = temp;

         num = Math.round(decimal * denom);
      } while (res!=(int)res && Math.abs(decimal - (num/denom)) > tolerance);

      return (sign * (int) num + "/" + (int) denom);
   }

   /**
    * Converts a fraction to a double
    * 
    * @param fraction - the fraction as a string
    * @return - a decimal representation of the fraction
    */
   public static Double fractionToDouble(String fraction) 
      throws ParseException, NumberFormatException {
      
      Double d = null;
      if (fraction != null) {
         if (fraction.contains("/")) {
            String[] numbers = fraction.split("/");
            if (numbers.length == 2) {
               BigDecimal d1 = BigDecimal.valueOf(Double.valueOf(numbers[0]));
               BigDecimal d2 = BigDecimal.valueOf(Double.valueOf(numbers[1]));
               BigDecimal response = d1.divide(d2, MathContext.DECIMAL128);
               d = response.doubleValue();
            }
         }
         else {
            d = Double.valueOf(fraction);
         }
      }
      if (d == null) {
         throw new ParseException(fraction, 0);
      }
      return d;
   }

   public static List<Integer> createExponentsFromMaxDegree(int maxDegree) {
      List<Integer> exponents = new ArrayList<Integer>();
      for(int index = 0; index <= maxDegree; index++) {
         exponents.add(maxDegree - index);
      }
      return exponents;
   }

   /**
    * squaringFunction - used to provide a quicker way of evaluating an exponent
    * This is not used in the program because Horner's rule is quicker. When dealing 
    * with polynomials.
    *
    * @param x - value to evaluate
    * @param n - the exponent
    * @param return - a double value of the x^n
    */
   public static Double squaringFunction(Double x, Integer n) {
      if(n < 0) {
         return squaringFunction(1/x, -n);
      }
      else if(n == 0) {
         return 1.0;
      }
      else if(n == 1) {
         return x;
      }
      else if(n % 2 == 0) {
         return squaringFunction(x * x, n / 2);
      }
      else {
         return x * squaringFunction(x * x, (n - 1) / 2);
      }
   }

   /**
    * validateDouble - validates that a user has entered a correct value such as
    * a fraction, decimal, or integer. Re-ask user if invalid.
    *
    * @param keyboard - the scanner class to recieve input from user
    * @message - the message that will ask user for input
    * @error - the error to display if invalid
    *
    * @return - returns the double value if valid
    **/
   public static double validateDouble(Scanner keyboard, String message, String error) {
      double returnValue = 0.0;
      boolean isError = true;
      do {
         try {
            System.out.println(message);
            returnValue = Utilities.fractionToDouble(keyboard.nextLine());
            isError = false;
         }
         catch(InputMismatchException | ParseException | NumberFormatException 
               | ArithmeticException e) {

            System.out.println("\n" + error + "\n");
         }
      } while(isError);

      return returnValue;
   }

   /**
    * validateInt - validates that a user has entered a correct value such as
    * an integer. Re-ask user if invalid.
    *
    * @param keyboard - the scanner class to recieve input from user
    * @message - the message that will ask user for input
    * @error - the error to display if invalid
    *
    * @return - returns the integer value if valid
    **/
   public static int validateInt(Scanner keyboard, String message, String error) {
      int returnValue = 0;
      boolean isError = true;
      do {
         try {
            System.out.println(message);
            returnValue = keyboard.nextInt();
            keyboard.nextLine();
            isError = false;
         }
         catch(InputMismatchException e) {
            System.out.println("\n" + error + "\n");
            keyboard.nextLine();
         }
      } while(isError);

      return returnValue;
   }
}
