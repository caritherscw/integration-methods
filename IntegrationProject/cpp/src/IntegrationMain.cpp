/*
 * IntegrationMain.cpp
 *
 *  Created on: Dec 28, 2015
 *      Author: chris
 */

#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include <cctype>
#include "Polynomial.h"
#include "Function.h"
#include "Utilities.h"
#include "Properties.cpp"
#include "IntegrationMethods.h"
#include "IntegrationMethods.cpp"

using namespace std;
using namespace MathFunctions;

double validateFraction(string message, string errorMessage) {
   bool isValid = false;
   string fraction;
   double decNum = 0.0;
   do {
      int count = 0;
      cin.clear();
      cout << message << flush;
      cin >> fraction;

      for(int i = 0; i < fraction.size(); i++) {
         if(fraction[i] == '/') {
            count++;
         }
      }

      if(count == 1 || count == 0) {
         isValid = true;
         decNum = Utilities::fractionToDouble(fraction);
      }
      else {
         cin.clear();
         cout << errorMessage << endl;
      }

      if(decNum != decNum || isinf(decNum)) {
         isValid = false;
         cin.clear();
         cout << "\n" + errorMessage + "\n" << endl;
      }

   } while(!isValid);

   return decNum;
}

int validatePositiveInt(string message, string errorMessage) {
   bool isValid = false;
   int integerValue = 0;

   do {
      cout << message << flush;
      cin >> integerValue;

      if(cin.good() && integerValue >= 0) {
         isValid = true;
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
      else {
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
         cout << "\n" + errorMessage + "\n" << endl;
      }
   } while(!isValid);

   return integerValue;
}

string convertInt(int number) {
   stringstream ss;
   ss.clear();
   ss << number;
   return ss.str();
}

string convertDouble(double number) {
   stringstream ss;
   ss.clear();
   ss << number;
   return ss.str();
}

template <typename E, typename C>
string convertPolynomial(Function<E, C> polynomial) {
   stringstream ss;
   ss.clear();
   ss << polynomial;
   return ss.str();
}

int main() {
   int degree = 0;
   int numberOfColumns = 0;
   int optionChosen = 0;
   double coefficient = 0.0;
   double a = 0.0;
   double b = 0.0;
   char continueProgram = 'N';

   Properties props;
   string configFileName = "./config.properties";
   props.read(configFileName);

   cout << props.getValue("WELCOME_TEXT") << endl;

   do {
      degree = validatePositiveInt("\n" + props.getValue("ASK_FOR_DEGREE"), 
         props.getValue("INVALID_POSITIVE_INTEGER"));

      Polynomial<int, double> newPolynomial(degree);

      cout << endl;

      for(int index = 0; index < newPolynomial.getCoefficients().size(); index++) {
         string stringArray[] = {convertInt(index)};
         coefficient = validateFraction(props.getValue("ASK_FOR_COEFFICIENT", 
            stringArray, 1), props.getValue("INVALID_DOUBLE"));
         newPolynomial.setCoefficient(index, coefficient);
      }

      a = validateFraction("\n" + props.getValue("ASK_FOR_A"), props.getValue("INVALID_DOUBLE"));
      b = validateFraction("\n" + props.getValue("ASK_FOR_B"), props.getValue("INVALID_DOUBLE"));

      do {
         optionChosen = validatePositiveInt("\n" + props.getValue("CHOOSE_METHOD_MENU"), 
            props.getValue("INVALID_OPTION"));
         if(optionChosen < 1 || optionChosen > 3) {
            cout << props.getValue("INVALID_OPTION") << endl;
         }
      } while(optionChosen < 1 || optionChosen > 3);

      cout << "\n" << endl;

      double answer;
      switch(optionChosen) {
         case 1: {
            numberOfColumns = validatePositiveInt("\n" + props.getValue("ASK_FOR_N"), 
               props.getValue("INVALID_POSITIVE_INTEGER"));
            answer = IntegrationMethods::rectangleMethod(a, b, numberOfColumns, newPolynomial);
            const string stringArray[] = {convertPolynomial(newPolynomial), 
               Utilities::fraction(a, 0.0001), Utilities::fraction(b, 0.0001), 
               Utilities::convertDouble(answer), convertInt(numberOfColumns)};
            cout << "\n" + props.getValue("SOLVE_RECTANGLE", stringArray, 5) << endl;
            break;
         }
         case 2: {
            numberOfColumns = validatePositiveInt("\n" + props.getValue("ASK_FOR_N"), 
               props.getValue("INVALID_POSITIVE_INTEGER"));
            answer = IntegrationMethods::trapezoidalMethod(a, b, numberOfColumns, newPolynomial);
            const string stringArray[] = {convertPolynomial(newPolynomial), 
               Utilities::fraction(a, 0.0001), Utilities::fraction(b, 0.0001), 
               Utilities::convertDouble(answer), convertInt(numberOfColumns)};
            cout << "\n" + props.getValue("SOLVE_TRAPEZOIDAL", stringArray, 5) << endl;
            break;
         }
         case 3: {
            answer = IntegrationMethods::symbolicMethodForPolynomial(a, b, newPolynomial);
            const string stringArray[] = {convertPolynomial(newPolynomial), 
               Utilities::fraction(a, 0.0001), Utilities::fraction(b, 0.0001), 
               Utilities::convertDouble(answer)};
            cout << "\n" + props.getValue("SOLVE_SYMBOLIC", stringArray, 4) << endl;
            break;
         }
         default:
            cout << "\n" + props.getValue("INVALID_OPTION") << endl;
      }

      do {
         cout << "\n" + props.getValue("CONTINUE_PROGRAM") << endl;
         cin >> continueProgram;
      } while(continueProgram != 'Y' && continueProgram != 'N'
           && continueProgram != 'y' && continueProgram != 'n');

   } while(continueProgram == 'Y' || continueProgram == 'y');

   return 0;
}
