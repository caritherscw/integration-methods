package com.project.math.utilities;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.File;
import java.io.FileInputStream;
import java.net.URL;
import java.util.Properties;

/**
 * PropertiesFile - this class gets the strings to display to the user
 * from a properties file. This allows easier changes to text and 
 * if needed to translate for other langauges. 
 */
public class PropertiesFile {

   public static final String CONFIG_FILENAME = "/config.properties";
   private Properties properties;

   // Constructor
   public PropertiesFile() {
      properties = new Properties();
   }

   /**
    * getPropertyValue - gets the property value or string from the 
    * properties configuration file using a key.
    *
    * @param propertiesKey - the key to look up in config.properties file
    * @return - returns the string that maps to the key
   */
   public String getPropertyValue(String propertiesKey) {

      String result = "";
      InputStream inputStream = null;

      try {
         // get ready the properties file
         inputStream = toURLFromString(CONFIG_FILENAME).openStream();
      }
      catch (IOException e1) {
         e1.printStackTrace();
      }

      try { 
         if (inputStream != null) {
            properties.load(inputStream);
         }
         else {
            throw new FileNotFoundException("property file '" + CONFIG_FILENAME 
               + "' not found in the classpath");
         }
 
         // get the property value
         result = properties.getProperty(propertiesKey); 
         }
         catch (IOException e) {
            System.out.println("Exception: " + e);
         }
         finally {
            try {
               inputStream.close();
            }
            catch (IOException e) {
               System.out.println("Exception: " + e);
            }
         }

      return result;
   }

   /**
    * Both of these methods below help in load the properties file when running
    * from the IDE or when in jar file.
    */
   public String getURLString(String stringLocation) {
      Class<? extends PropertiesFile> classLocation = this.getClass();
      String absoluteURLString = "/" + classLocation.getPackage().getName();
      absoluteURLString = absoluteURLString.replace('.', '/');
      absoluteURLString += stringLocation;

      return absoluteURLString;
   }

   public URL toURLFromString(String urlString)
   {
      String urlLocation = getURLString(urlString);
      Class<?extends PropertiesFile> classLocation = this.getClass();

      return classLocation.getResource(urlLocation);
   }
}
