package com.project.math;
import java.text.MessageFormat;
import java.text.ParseException;
import java.util.InputMismatchException;
import java.util.Scanner;

import com.project.math.utilities.IntegrationMethods;
import com.project.math.utilities.PropertiesFile;
import com.project.math.utilities.Utilities;

public class IntegrationMain {
   public static void main(String[] args) {
      Scanner keyboard = new Scanner(System.in);
      PropertiesFile propertiesFile = new PropertiesFile();

      int degree = -1;
      double a = 0;
      double b = 0;
      int n = 0;
      String continueProgram = "";

      System.out.println(propertiesFile.getPropertyValue("WELCOME_TEXT"));
      do {
         Function<Integer, Double> polynomial = new Polynomial<Integer, Double>();

         do {
            degree = Utilities.validateInt(keyboard, "\n" 
               + propertiesFile.getPropertyValue("ASK_FOR_DEGREE"), 
            propertiesFile.getPropertyValue("INVALID_POSITIVE_INTEGER"));
         } while(degree < 0);

         for(int index = degree; index >= 0; index--) {
            polynomial.addToExponent(index);
         }

         int index = 0;
         MessageFormat messageFormat = new MessageFormat(propertiesFile
            .getPropertyValue("ASK_FOR_COEFFICIENT"));
         while(index <= degree) {
            double coe;
            String[] stringVariable = {"" + index};
            coe = Utilities.validateDouble(keyboard, messageFormat.format((stringVariable)), 
            propertiesFile.getPropertyValue("INVALID_DOUBLE"));
            polynomial.addToCoefficient(0, coe);
            index++;
         }

         a = Utilities.validateDouble(keyboard, "\n" + propertiesFile.getPropertyValue("ASK_FOR_A"), 
            propertiesFile.getPropertyValue("INVALID_DOUBLE"));
         b = Utilities.validateDouble(keyboard, "\n" + propertiesFile.getPropertyValue("ASK_FOR_B"), 
            propertiesFile.getPropertyValue("INVALID_DOUBLE"));

         int choosenMethod = 0;
         messageFormat = new MessageFormat("\n" + propertiesFile
            .getPropertyValue("ASK_FOR_INTEGRATION_METHOD"));
         String[] stringArray = {polynomial.toString()};
         do {
            choosenMethod = Utilities.validateInt(keyboard, messageFormat.format(stringArray) 
               + "\n" + propertiesFile.getPropertyValue("CHOOSE_METHOD_MENU"), 
               propertiesFile.getPropertyValue("INVALID_POSITIVE_INTEGER"));
         } while(choosenMethod <= 0 || choosenMethod >= 4);

         double answer = 0.0;
         String[] stringArrayParams;
         switch(choosenMethod) {
            case 1:
               do {
                  n = Utilities.validateInt(keyboard, "\n" + propertiesFile
                     .getPropertyValue("ASK_FOR_N"), propertiesFile.getPropertyValue(
                     "INVALID_POSITIVE_INTEGER"));
               } while(n <= 0);
               answer = IntegrationMethods.rectangleMethod(a, b, n, polynomial);
               stringArrayParams = new String[]{polynomial.toString(), "" + a, "" + b, "" 
                  + answer, "" + n};
               messageFormat = new MessageFormat(propertiesFile.getPropertyValue("SOLVE_RECTANGLE"));
               System.out.println("\n" + messageFormat.format(stringArrayParams));
               break;
            case 2:
               do {
                  n = Utilities.validateInt(keyboard, "\n" + propertiesFile
                     .getPropertyValue("ASK_FOR_N"), propertiesFile.getPropertyValue(
                     "INVALID_POSITIVE_INTEGER"));
               } while(n <= 0);
               answer = IntegrationMethods.trapezoidalMethod(a, b, n, polynomial);
               stringArrayParams = new String[]{polynomial.toString(), "" + a, "" + b, "" 
               + answer, "" + n};
               messageFormat = new MessageFormat(propertiesFile.getPropertyValue(
                  "SOLVE_TRAPEZOIDAL"));
               System.out.println("\n" + messageFormat.format(stringArrayParams));
               break;
            case 3:
               answer = IntegrationMethods.symbolicMethod(a, b, polynomial);
               stringArrayParams = new String[]{polynomial.toString(), "" + a, "" + b, "" + answer};
               messageFormat = new MessageFormat(propertiesFile.getPropertyValue("SOLVE_SYMBOLIC"));
               System.out.println(messageFormat.format(stringArrayParams));
               stringArrayParams = new String[]{IntegrationMethods.integralToString(polynomial)};
               messageFormat = new MessageFormat("\n" + propertiesFile.getPropertyValue(
                  "SHOW_INTEGRAL"));
               System.out.println(messageFormat.format(stringArrayParams));
               break;
            default:
               System.out.println("\n" + propertiesFile.getPropertyValue("INVALID_POSITIVE_INTEGER"));
               break;
            }

            do {
               System.out.println("\n" + propertiesFile.getPropertyValue("CONTINUE_PROGRAM"));
               continueProgram = keyboard.nextLine();
         } while(!continueProgram.equalsIgnoreCase("Y") && !continueProgram.equalsIgnoreCase("N"));
      } while(continueProgram.equalsIgnoreCase("Y"));
   keyboard.close();
   }
}
