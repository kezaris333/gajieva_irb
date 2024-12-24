//Реализовать функцию конкатенации строк, аналогичную стандартной функции strcat.

#include<stdio.h>

char* strcatmy(char* first, const char* second) {

	//создаем указатель на первую строку, чтобы еë прочесть и не потерять указатель на начало строки
	char* ptr = first;
	while (*ptr != '\0') {
		ptr++;
	}

	//не создаем доп. указатель, тк. мы просто читаем строку и в эьом нет необходимости
	while (*second != '\0') {
		*ptr = *second;
		ptr++;
		second++;
	}
	*ptr = '\0';

	return first;
}
int main() {
	char one[100] = "hello, ";
	char two[] = "world!!";

	char* result = strcatmy(one, two);

	printf("%s", result);

	return 0;
}