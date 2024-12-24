//.Реализовать функцию подсчета длины строки, аналогичную стандартной функции strlen.
#include<stdio.h>

int strlenme(const char* str) {
    int cnt = 0;
    while (*str != '\0') {
        cnt++;
        str++;
    }
    return cnt;
}

int main() {
    char str[] = "Hello world!"; 

    int result = strlenme(str);

    printf("%d", result);

    return 0;
}