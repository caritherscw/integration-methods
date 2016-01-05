/*
 * Properties.cpp
 *
 * This class is so that we can load a config properties file.
 * This config properties file can be used for multiple projects.
 *
 *  Created on: Dec 30, 2015
 *      Author: chris
 */

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Utilities.h"

class Properties {
   public:
   Properties() {
   }

   /*
    * read - loads and creates the mapping from the
    * config properties file when giving the name of the file.
    *
    * param strFile - name of the config file
    */
   bool read(const std::string &strFile) {
      // open file to read from
      std::ifstream is(strFile.c_str());
      if(!is.is_open()) {
         return false;
      }

      // create the mapping from key to value from the config
      // properties file
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

   /*
    * getValue - returns the string value from a key.
    *
    * param strKey - string key to look up value
    * returns - a string which is the value of the key
    */
   std::string getValue(const std::string &strKey) const {
      std::map<std::string, std::string>::const_iterator i;

      i = mapKeyToValue.find(strKey);

      if(i != mapKeyToValue.end()) {
         return i->second;
      }

      return "";
   }

   /*
    * getValue - returns the string value from a key with the update string values
    *
    * param strKey - string key to look up value
    * param stringArray - array of strings which are parameters to replace {} within text
    * return - a string which is the value of the key and replacement of {}
    */
   std::string getValue(const std::string &strKey, const std::string stringArray[],
         const int numberOfElements) const {
      
      std::map<std::string, std::string>::const_iterator i;

      i = mapKeyToValue.find(strKey);

      if(i != mapKeyToValue.end()) {
         std::string matching = i->second;
         if(!matching.rfind("{0}")) {
            return matching;
         }
         else {
            // This adds the string values from the array to the text
            // in order receive values from parameters which are known
            // during runtime
            for(int index = 0; index < numberOfElements; index++) {
               std::string indexString = "{" + MathFunctions::Utilities::convertInt(index) + "}";
               size_t f = matching.find(indexString);
               matching.replace(f, indexString.length(), stringArray[index]);
            }

            return matching;
         }
      }

      return "";
   }

   protected:
      std::map<std::string, std::string> mapKeyToValue;
};
