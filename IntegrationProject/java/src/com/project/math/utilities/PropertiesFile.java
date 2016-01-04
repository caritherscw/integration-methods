package com.project.math.utilities;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.File;
import java.io.FileInputStream;
import java.net.URL;
import java.util.Properties;

public class PropertiesFile {

   public static final String CONFIG_FILENAME = "/config.properties";
   private Properties properties;

   public PropertiesFile() {
      properties = new Properties();
   }

   public String getPropertyValue(String propertiesKey) {

      String result = "";
      InputStream inputStream = null;

      try {
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
