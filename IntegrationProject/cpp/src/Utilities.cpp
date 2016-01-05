/*
 * Utilities.cpp
 *
 *  Created on: Jan 1, 2016
 *      Author: chris
 */

#include <cmath>
#include <math.h>
#include <cstring>
#include <cstdlib>
#include <limits>
#include <iostream>
#include <sstream>
#include "Utilities.h"

namespace MathFunctions {
   std::string Utilities::fraction(double decimal, double tolerance) {
      // determin if negative or positive
      int sign = 1;
      if(decimal < 0.0) {
         sign = -1;
      }
      else {
         sign = 1;
      }

      decimal = std::abs(decimal);

      // if decimal is integer return it as whole number
      if(decimal == (int)decimal) {
         return (convertDouble(sign * (int)decimal));
      }

      double res = decimal, num = 0.0, denom = 1.0, lastdenom = 0.0, temp;
      // determine the fraction within the tolerance limits
      do {
         res = 1.0 / (res - (int)res);
         temp = denom;
         denom = denom * (int)res + lastdenom;
         lastdenom = temp;

         num = round(decimal * denom);
      } while(res != (int)res && std::abs(decimal - (num / denom)) > tolerance);
      num = sign * num;
      return (convertDouble(num) + "/" + convertDouble(denom));
   }

   double Utilities::fractionToDouble(std::string fraction) {
      std::string numerator;
      std::string denominator;

      // find the fraction symbol within string
      std::size_t position = fraction.find("/");
      double value = 0.0;

      // if found split the fraction into numerator and denominator
      if(position != std::string::npos) {
         std::size_t begin = 0;
         if(!(fraction.empty())) {
            while(begin != position) {
               numerator = fraction.substr(0, position);
               begin++;
            }

            while(begin != fraction.length()) {
               denominator = fraction.substr(position + 1, std::string::npos);
               begin++;
            }

            // check to make sure the numerator and denominators are integers
            // once done compute decimal and return
            double doubleNumerator = 0;
            double doubleDenominator = 1;
            if(isInteger(numerator)) {
               doubleNumerator = std::atof(numerator.c_str());
            }
            else {
               return std::numeric_limits<double>::quiet_NaN();
            }

            if(isInteger(denominator)) {
               doubleDenominator = std::atof(denominator.c_str());
            }
            else {
               return std::numeric_limits<double>::quiet_NaN();
            }

            value = (doubleNumerator / doubleDenominator);

            return value;
         }
         else {
            return std::atof(fraction.c_str());
         }
      }

      // if string not decimal then return not a number (NaN)
      if(!isDouble(fraction.c_str())) {
         return std::numeric_limits<double>::quiet_NaN();
      }

      // if decimal return string as float
      return std::atof(fraction.c_str());
   }

   bool Utilities::isInteger(const std::string &number) {
      // check to see if valid integer
      if(number.empty() || ((!isdigit(number[0])) && (number[0] != '-') && (number[0] != '+'))) {
         return false;
      }

      char *p;
      strtol(number.c_str(), &p, 10);

      return (*p == 0);
   }

   bool Utilities::isDouble(const char* str) {
      char* endptr = 0;
      strtod(str, &endptr);

      if(*endptr != '\0' || endptr == str) {
         return false;
      }

      return true;
   }

   std::string Utilities::convertDouble(double number) {
      std::stringstream ss;
      ss.clear();
      ss << number;
      return ss.str();
   }

   std::string Utilities::convertInt(int number) {
      std::stringstream ss;
      ss.clear();
      ss << number;
      return ss.str();
   }
}
