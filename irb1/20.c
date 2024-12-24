//Реализовать функцию преобразования числа типа int, заданного в системе счисления с
//основанием 10, в строковое представление числа в системе счисления с основанием из
//диапазона[2..36]


#include <stdio.h>
#include <stdlib.h>

void foo(int value, int base) {
	char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWYZ"; 
	char buffer[33]; //32 бкувы и ноль
	int index = 0;

	//отрицталеьнык числа
	if (value < 0 && base == 10) {
		printf("-");
		value = -value;
	}

	do {
		buffer[index++] = digits[value % base]
		value = value / base;

	} while (value > 0)
		//выводим результат в обратном порядке
		for (int i = index - 1; i >= 0; i--) {
			printf("%c", buffer[i]);
		}
}

int main() {
	int value = -255; 
	int base = 16;
	printf("число %d в системе счисления с основанием %d: ", value, base);
	foo(value, base); 
	printf("\n"); 

	return 0;
}
