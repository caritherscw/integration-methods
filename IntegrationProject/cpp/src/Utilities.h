/*
 * Utilities.h
 *
 * Utilty methods for the program. Such methods include converting
 * a decimal to fraction, fraction to decimal, and converting
 * numbers to strings.
 *
 *  Created on: Jan 3, 2016
 *      Author: chris
 */

#ifndef UTILITIES_H_
#define UTILITIES_H_

#include <string>

namespace MathFunctions {
   class Utilities {
      public:
         /*
          * fraction - converts a decimal to a fraction
          *
          * param decimal - double value to convert to fraction
          * param tolerance - accuracy of the fraction
          *
          * return - the string version of the decimal
          */
         static std::string fraction(double decimal, double tolerance);

         /*
          * fractionToDouble - converts a string fraction to a double
          *
          * param fraction - a string to convert to double
          *
          * return - the double version of the fraction
          */
         static double fractionToDouble(std::string fraction);

         /*
          * convertDouble - converts a double to string
          *
          * param number - double value to convert to string
          *
          * return - the string version of double
          */
         static std::string convertDouble(double number);

         /*
          * convertInt - converts an int to string
          *
          * param number - int value to convert to string
          *
          * return - the string version of int
          */
         static std::string convertInt(int number);

      private:
         /*
          * isInteger - validates that the string is an integer
          *
          * param number - string to validate
          *
          * return - true if valid else false
          */
         static bool isInteger(const std::string &number);
         /*
          * isDouble - validates that the string is a double
          *
          * param number - string to validate
          *
          * return - true if valid else false
          */
         static bool isDouble(const char* str);
   };
}


#endif /* UTILITIES_H_ */
