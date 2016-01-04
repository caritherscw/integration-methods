/*
 * Function.h
 *
 *  Created on: Dec 26, 2015
 *      Author: chris
 */
 
#ifndef FUNCTION_H_
#define FUNCTION_H_

#include <string>
#include <map>

namespace Props {
class Properties {
	public:
		Properties();
	
		bool read(const std::string &strFile);
		std::string getValue(const std::string &strKey, const std::string stringArray[], const int numberOfElements) const;
		std::string getValue(const std::string &strKey) const;
	
	protected:
		std::map<std::string, std::string> mapKeyToValue;
		
	private:
		std::string convertInt(int number);
};
}
#endif /* FUNCTION_H_ */