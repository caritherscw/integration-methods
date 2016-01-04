package com.project.math.utilities;

import com.project.math.Function;
import com.project.math.Polynomial;

public class IntegrationMethods {

	public static <E, C> double rectangleMethod(double a, double b, int n, Function<E, C> function) {
		//double range = checkParamsGetRange(a, b, n);
		double range = b - a;
		double modeOffset = (double) 1 / 2.0;
		double nFloat = (double) n;
		double sum = 0.0;
		
		for(int index = 0; index < n; index++) {
			double x = a + range * ((double) index + modeOffset) / nFloat;
			sum += function.evaluate(x);
		}
		
		return sum * range / nFloat;
	}
	
	public static <E, C> double trapezoidalMethod(double a, double b, int n, Function<E, C> function) {
		//double range = checkParamsGetRange(a, b, n);
		double range = b - a;
		double nFloat = (double) n;
		double sum = 0.0;
		
		for(int index = 1; index < n; index++) {
			double x = a + range * (double) index / nFloat;
			sum += function.evaluate(x);
		}
		
		sum += (function.evaluate(a) + function.evaluate(b)) / 2.0;
		
		return sum * range / nFloat;
	}
	
	public static double symbolicMethod(double a, double b, Function<Integer, Double> function) {
		Function<Integer, Double> newFunction = new Polynomial((Polynomial) function);

		for(int index = 0; index < newFunction.getCoefficient().size(); index++) {
			newFunction.getCoefficient().set(index, newFunction.getCoefficient().get(index)/(newFunction.getExponent().get(index) + 1));
		}
		
		newFunction.getCoefficient().add(newFunction.getCoefficient().size(), 0.0);
		return newFunction.evaluate(b) - newFunction.evaluate(a);
	}
	
	public static String integralToString(Function<Integer, Double> function) {
		Function<Integer, Double> newFunction = new Polynomial((Polynomial) function);
		
		for(int index = 0; index < newFunction.getCoefficient().size(); index++) {
			newFunction.getCoefficient().set(index, newFunction.getCoefficient().get(index)/(newFunction.getExponent().get(index) + 1));
		}
		
		newFunction.getCoefficient().add(newFunction.getCoefficient().size(), 0.0);
		return newFunction.toString();
	}
	
	public static double checkParamsGetRange(double a, double b, int n) {
		if(n <= 0)
			throw new IllegalArgumentException("Invalid value of n");
		double range = b - a;
		if(range <= 0)
			throw new IllegalArgumentException("Invalid range");
		return range;
	}
}
