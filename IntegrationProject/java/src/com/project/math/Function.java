package com.project.math;
import java.util.ArrayList;
import java.util.List;

/**
 * Function - relation between a set of inputs and a set of
 * outputs. Each input is related to exactly one output. 
 * 
 * @param <E> - coefficients
 * @param <C> - exponents
 */
public abstract class Function<E, C> implements Cloneable {
   protected List<E> exponents;
   protected List<C> coefficients;

   // Constructors
   public Function() {
      exponents = new ArrayList<E>();
      coefficients = new ArrayList<C>();
   }

   public Function(List<E> exponents, List<C> coefficients) {
      this.exponents = exponents;
      this.coefficients = coefficients;
   }

   public Function(Function function) {
      this.exponents = new ArrayList<E>(function.exponents);
      this.coefficients = new ArrayList<C>(function.coefficients);
   }

   // setters
   public void setExponent(List<E> exponents) {
      this.exponents = exponents;
   }

   public void setCoefficient(List<C> coefficients) {
      this.coefficients = coefficients;
   }

   // getters
   public List<E> getExponent() {
      return exponents;
   }

   public List<C> getCoefficient() {
      return coefficients;
   }

   /**
    * addToExponent - Add an exponent to the list
    *
    * @param exponent E
    */
   public void addToExponent(E exponent) {
      exponents.add(exponent);
   }

   /**
    * addToExponent - Add an exponent to the list at provided index
    *
    * @param index - integer of where to put the exponent
    * @param exponent E
    */
   public void addToExponent(int index, E exponent) {
      exponents.add(index, exponent);
   }

   /**
    * addToCoefficient - Add a coefficient to the list
    *
    * @param exponent C
    */
   public void addToCoefficient(C coefficient) {
      coefficients.add(coefficient);
   }

   /**
    * addToCoefficient - Add a coefficient to the list at provided index
    *
    * @param index - integer of where to put the coefficient
    * @param exponent C
    */
   public void addToCoefficient(int index, C coefficient) {
      coefficients.add(index, coefficient);
   }

   /**
    * getCoefficientList() - retrieve the coefficient list as string
    *
    * @return - returns the list of coefficients as a string
    */
   public String getCoefficientList() {
      String coefficientList = "";
      for(int index = 0; index < coefficients.size(); index++) {
         if(coefficientList.isEmpty()) {
            coefficientList += coefficients.get(index);
         }
         else {
            coefficientList += " " + coefficients.get(index);
         }
      }

      return coefficientList;
   }

   /**
    * getExponentList() - retrieve the exponent list as string
    *
    * @return - returns the list of exponents as a string
    */
   public String getExponentList() {
      String exponentList = "";
      for(int index = 0; index < exponents.size(); index++) {
         if(exponentList.isEmpty()) {
            exponentList += exponents.get(index);
         }
         else {
            exponentList += " " + exponents.get(index);
         }
      }

      return exponentList;
   }

   /**
    * clone - hard copy a function instead of shallow copy
    */
   @Override
   public Function clone() throws CloneNotSupportedException {
      return (Function) super.clone();
   }

   // abstract methods that may be different depending on type of function
   public abstract Double evaluate(Double x);

   protected abstract String exponentToString(E exponent);

   protected abstract String coefficientToString(C coefficient);

   public abstract String toString();
}
