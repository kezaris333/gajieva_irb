//Реализовать функцию с переменным числом аргументов, находяющую значение многочлена
//степени n в заданной точке.Входными параметрами являются точка(вещественного типа), в
//которой определяется значение многочлена, степень многочлена(целочисленного типа), и его
//коэффициенты(вещественного типа, от старшей степени до свободного коэффициента в порядке
//	передачи параметров функции слева направо).Продемонстрируйте работу функции.

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

float calculation_unsigned_pow(unsigned int pow, float value) 
{
	if (pow == 0) 
	{
		value = 1;
		return value;
	}

	float original_value = value;

	if ( pow % 2 == 0) 
	{
		//(x^2)^n/2
		for (int half_pow = pow / 2, i = 0; i < half_pow; i++) {
			value *= value;
		}
		return value;
	}


	if (pow % 2 == 1)
	{ //x (x^2) ^((n-1)/2)
		for (int half_pow = (pow - 1) / 2, i = 0; i < half_pow; i++) {
			if (i == 0) {
				value = value * value * original_value;
			}
			else {
				value *= value;
			}
			
		}
		return value;

	}

}


int foo(float dot, int power, float coefficient, ...) 
{
	va_list args;
	va_start(args, coefficient);

	//p(x) = 2(x^3) - 4(x^2) +6(x) - 8
	//user enters dot (x), power(^) and coef 
		
	if (power < 0) {
		printf("enter right value power (more than 0)");
		return 0;
	}

	float result = coefficient * calculation_unsigned_pow(power, dot);

	for (int i = power-1; i >= 0; i--)
	{
		float coef = va_arg(args, double) * calculation_unsigned_pow(i, dot);
		result += coef * calculation_unsigned_pow(i, dot);
	}
	printf(" %.4f\n", result);

	va_end(args);
	return 0;

}


int main() {

	foo(2.0, 7, 9.8, 9.9, 8.0, 4.3);

	return 0;
}
