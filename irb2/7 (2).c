//Реализовать функцию с переменным числом аргументов, находящую среди переданных
//строковых представлений целых неотрицательных чисел, заданных в системе счисления с
//основанием base, передаваемым как параметр функции, чисел, являющихся в системе счисления с
//основанием base числами Капрекара.Продемонстрируйте работу функции.


#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

////отбираем половинку и переводим ее в число 
    //числа делаем в десятичную систему и прибавляем 
    // потом смотрим на соответствие изначального числа и этого 

unsigned int calculation_unsigned_pow(unsigned int base, unsigned int exponent) {
    unsigned int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result *= base;
        }
        base *= base;
        exponent /= 2;
    }
    return result;
}

int change_to_ten(const char* value, int sys) {
    int value_in_ten = 0;
    int power = 1;
    int len = strlen(value);

    for (int i = len - 1; i >= 0; i--) {
        if (value[i] >= '0' && value[i] <= '9') {
            value_in_ten += (value[i] - '0') * power;
        }
        else if (value[i] >= 'A' && value[i] <= 'Z') {
            value_in_ten += (value[i] - 'A' + 10) * power;
        }
        else {
            printf("Error value\n");
            return -1;
        }
        power *= sys;
    }
    return value_in_ten;
}

void reverse(char str[], int length) {
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

char* change_to_base_sys(int value, int base) {

    char* buffer =(char*) malloc (33* sizeof(char)); //массив для хранения результата
    if (buffer == NULL) {
        printf("error buffer memory");
        return NULL;
    }
    int index = 0;


    do {
        buffer[index++] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[value % base];
        value /= base;
    } while (value > 0);

    buffer[index] = '\0'; 

    //переворачиваем строку
    reverse(buffer, index);

    return buffer;
}

void isKramer(int count, unsigned int base, ...) {
    va_list args;
    va_start(args, base);

    if (base < 2 || base > 32) {
        printf("Error: invalid base\n");
        va_end(args);
        return;
    }

    for (int i = 0; i < count; i++) {
        char* str_num = va_arg(args, char*);
        int num = change_to_ten(str_num, base);

        if (num < 0) {
            printf("Error: invalid number %s in base %u\n", str_num, base);
            continue; //пропускаем некорректные числа
        }

        int num_squared = calculation_unsigned_pow(num, 2);
        char* num_squared_str = change_to_base_sys(num_squared, base);

        int len = strlen(num_squared_str);
        int mid = len / 2;

        //выделение памяти для левой и правой части
        char* left = malloc(mid + 1);
        char* right = malloc(len - mid + 1);

        if (!left || !right) {
            printf("Memory allocation error\n");
            break;
        }

        strncpy(left, num_squared_str, mid);
        left[mid] = '\0'; 

        strcpy(right, num_squared_str + mid);
        right[len - mid] = '\0';

        int left_sum = change_to_ten(left, base);
        int right_sum = change_to_ten(right, base);

        if (num == left_sum + right_sum) {
            printf("%s is a Kaprekar number in base %u\n", str_num, base);
        }

        //освобождение выделенной памяти
        free(left);
        free(right);
    }

    va_end(args);
}

int main() {
    isKramer(3, 10, "35", "5", "45");
    return 0;
}
