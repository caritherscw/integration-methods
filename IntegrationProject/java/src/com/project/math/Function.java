package com.project.math;
import java.util.ArrayList;
import java.util.List;

public abstract class Function<E, C> implements Cloneable {
   protected List<E> exponents;
   protected List<C> coefficients;

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

   public void setExponent(List<E> exponents) {
      this.exponents = exponents;
   }

   public void setCoefficient(List<C> coefficients) {
      this.coefficients = coefficients;
   }

   public List<E> getExponent() {
      return exponents;
   }

   public List<C> getCoefficient() {
      return coefficients;
   }

   public void addToExponent(E exponent) {
      exponents.add(exponent);
   }

   public void addToExponent(int index, C exponent) {
      coefficients.add(index, exponent);
   }

   public void addToCoefficient(C coefficient) {
      coefficients.add(coefficient);
   }

   public void addToCoefficient(int index, C coefficient) {
      coefficients.add(index, coefficient);
   }
	
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

   @Override
   public Function clone() throws CloneNotSupportedException {
      return (Function) super.clone();
   }

   public abstract Double evaluate(Double x);

   protected abstract String exponentToString(E exponent);

   protected abstract String coefficientToString(C coefficient);

   public abstract String toString();
}
