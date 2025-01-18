//Реализовать функцию с переменным числом аргументов, вычисляющую сумму переданных целых
//неотрицательных чисел в заданной системе счисления с основанием[2..36].Параметрами
//функции являются основание системы счисления, в которой производится суммирование,
//количество переданных чисел, строковые представления чисел в заданной системе счисления.
//Десятичное представление переданных чисел может быть слишком велико и не поместиться во
//встроенные типы данных; для решения возникшей проблемы также реализуйте функцию
//«сложения в столбик» двух чисел в заданной системе счисления, для её использования при
//реализации основной функции.Результирующее число не должно содержать ведущих нулей.
//Продемонстрируйте работу функции.

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* column(const char* num1, const char* num2, int base) 
{
    int len1 = strlen(num1);
    int len2 = strlen(num2);

    int max_len; //максимальная длина
    if (len1 > len2)
        max_len = len1;
    else
        max_len = len2;

    char* result = (char*)malloc((max_len + 2) * sizeof(char)); //для нуля и переносa
    if (result == NULL) 
    {
        printf("ошибка выделения памяти");
        return NULL;
    }
    result[max_len + 1] = '\0';

    int car = 0; //перенос
    int i = len1 - 1;
    int j = len2 - 1;
    int k = max_len;

    while (i >= 0 || j >= 0 || car > 0) 
    { //работть пока есть цифры для лсожения или для переноса
        
            int d1 = 0; //текущая цифра из num1 
            if (i >= 0) 
            { //если индекс за пределами num1 
                if (num1[i] >= '0' && num1[i] <= '9')  //если символ цифра
                    d1 = num1[i] - '0';
                
                else if (num1[i] >= 'a' && num1[i] <= 'z')  //если символ маленькая буква
                    d1 = num1[i] - 'a' + 10;
                
                else if (num1[i] >= 'A' && num1[i] <= 'Z')  //если символ большая буква
                    d1 = num1[i] - 'A' + 10;
                
            }

            int d2 = 0; //текущая цифра из num2 
            if (j >= 0) 
            {
                if (num2[j] >= '0' && num2[j] <= '9')  //если символ цифра
                    d2 = num2[j] - '0';
                
                else if (num2[j] >= 'a' && num2[j] <= 'z')  //если символ маленькая буква
                    d2 = num2[j] - 'a' + 10;
                
                else if (num2[j] >= 'A' && num2[j] <= 'Z')  //если символ большая буква
                    d2 = num2[j] - 'A' + 10;
                
            }

            int sum = d1 + d2 + car;
            car = sum / base; //вычисляем новый перенос 
            sum = sum % base; //остаток 
            result[k--] = (sum < 10) ? (sum + '0') : (sum - 10 + 'a'); //обратно в символ 
            i--; j--; //следующая цифра 
        

       
    }
    //возвращаем указатель на начало числа без нулей 
    return result + k + 1;
}





char* sum_numbers_in_base(int base, int count, ...) {
    va_list args;
    va_start(args, count);
    if (base < 2 || base > 36)
    {
        return NULL;
    }

    char* sum = strdup("0"); //сумма ноль
    for (int i = 0; i < count; ++i) { 
        const char* num = va_arg(args, const char*); //след число
        char* new_sum = column(sum, num, base); 
        free(sum); 
        sum = new_sum; 
    }

    va_end(args); 

    //удаление  нулей
    while (*sum == '0' && *(sum + 1) != '\0') {
        sum++;
    }

    return sum; 
}

int main() {
    int base = 16;
    char* result = sum_numbers_in_base(base, 3, "1a", "2b", "3c");
    printf("Результат: %s\n", result);
    free(result);
    return 0;
}
