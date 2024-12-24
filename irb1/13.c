//Имеется строка. Используя указатель типа char *, преобразовать каждый элемент, стоящий на нечётной позиции, в верхний регистр.

#include<stdio.h>

int main() {
    char str[] = "hello wrld";

    char* ptr = str;

    for (int i = 0; *ptr != '\0'; i++, ptr++) {
        if (i % 2 == 1) {
            if (*ptr >= 'a' && *ptr <= 'z') {
                *ptr = *ptr - 32;
            }
        }
    }
    printf("%s", str);

    return 0;
}