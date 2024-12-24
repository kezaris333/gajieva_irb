//Задана строка символов. Используя указатели, 
// исключить из строки все символы

#include <stdio.h>

void delete(char* str) {
    char* ptr = str; //ук на начало

    //
    while (*ptr) {
        ptr++; //падем по строке
    }

    //устанавливаем нулевой символ в начало строки
    str[0] = '\0'; 
}

int main() {
    char str[100]; 
    printf("введите строку: ");
    fgets(str, sizeof(str), stdin); 

    delete(str); 

    printf("строка после удаления всех символов: '%s'\n", str);
    return 0;
}