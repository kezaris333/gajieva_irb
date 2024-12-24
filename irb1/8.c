//8. Задан числовой массив. Переписать в новый массив чётные числа.

#include <stdio.h>

int main() {

    int oldarr[10] = { 0,1,2,3,4,5,6,7,8,9 };
    int size = 10 / 2;
    int newarr[size];
    int j = 0;


    for (int i = 0; i < 10; i++) {
        if (oldarr[i] % 2 == 0) {
            newarr[j] = oldarr[i];
            j++;
        }
    }
    printf("нновый массив: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", newarr[i]);
    }


    return 0;
}