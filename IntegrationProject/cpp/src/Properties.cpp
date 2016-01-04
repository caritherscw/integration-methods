/*
 * Properties.cpp
 *
 *  Created on: Dec 30, 2015
 *      Author: chris
 */

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

class Properties {
public:
	Properties() {

	}

	bool read(const std::string &strFile) {
		std::ifstream is(strFile.c_str());
		if(!is.is_open()) {
			return false;
		}

		while(!is.eof()) {
			std::string strLine;
			getline(is, strLine);
			int nPos = strLine.find('=');

			if(std::string::npos == nPos) {
				continue;
			}

			std::string strKey = strLine.substr(0, nPos);
			std::string strVal = strLine.substr(nPos + 1, strLine.length() - nPos + 1);
			mapKeyToValue.insert(std::map<std::string, std::string>::value_type(strKey, strVal));
		}

		is.close();
		return true;
	}

	std::string getValue(const std::string &strKey) const {
		std::map<std::string, std::string>::const_iterator i;

		i = mapKeyToValue.find(strKey);

		if(i != mapKeyToValue.end()) {
			return i->second;
		}

		return "";
	}

	std::string getValue(const std::string &strKey, const std::string stringArray[], const int numberOfElements) const {
		std::map<std::string, std::string>::const_iterator i;

		i = mapKeyToValue.find(strKey);

		if(i != mapKeyToValue.end()) {
			std::string matching = i->second;
			if(!matching.rfind("{0}")) {
				return matching;
			}
			else {
				for(int index = 0; index < numberOfElements; index++) {
					std::string indexString = "{" + convertInt(index) + "}";
					size_t f = matching.find(indexString);
					matching.replace(f, indexString.length(), stringArray[index]);
				}

				return matching;
			}
		}

		return "";
	}

	std::string convertInt(int number) const {
		std::stringstream ss;
		ss << number;
		return ss.str();
	}

protected:
	std::map<std::string, std::string> mapKeyToValue;
};
