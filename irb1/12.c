//Реализовать функцию поиска подстроки в строке, аналогичную стандартной функции стрстр

#include<stdio.h>

char* strstrmy(const char* str, const char* substr) {
    if (*str == '\0') {
        return (char*)str;
    }//если изначальная строка пустая,тониче не выводим

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == substr[0]) {
            int k = 0;
            while (substr[k] != '\0' && str[i + k] == substr[k]) {
                k++;
            }//сравниваем строку и подстроку,покане дойдем до конца подстроки
            if (substr[k] == '\0') {
                return (char*)&str[i];
            }//класс,мы дошли,можно возвращать
        }
    }

    return NULL; //анлак, подстроки такой нема
}

int main() {
    char* str1 = "Hello world!";
    char* str2 = "world";
    char* result = strstrmy(str1, str2);

    if (result) {
        printf("%s\n", result);
    }
    else {
        puts("Подстрока не найдена(");
    }

    return 0;
}