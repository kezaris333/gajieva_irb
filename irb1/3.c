//Задача 3. Реализовать функцию, меняющую местами значения двух чисел типа int. Входными параметрами функции считать указатели типа int*



#include <stdio.h>

void function(int* aptr, int* bptr) {
	int g = *bptr;
	int* ptr = bptr;
	*ptr = *aptr;
	*aptr = g;
}

int main() {
	int a;
	int b;
	printf("Укажите значение переменной a: ");
	scanf("%d", &a);
	printf("\nУкажите значение переменной b: ");
	scanf("%d", &b);
	int* aptr = &a;
	int* bptr = &b;

	function(aptr, bptr);

	printf("\nЗначения переменных поменялись местами.\na = %d\nb = %d", a, b);

	return 0;
}