/*
 * Utilities.h
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
			static std::string fraction(double decimal, double tolerance);
			static double fractionToDouble(std::string fraction);
			static std::string convertDouble(double number);
		
		private:
			static bool isInteger(const std::string &number);
			static bool isDouble(const char* str);
	};
}


#endif /* UTILITIES_H_ */
