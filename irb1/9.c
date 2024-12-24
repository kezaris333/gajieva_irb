//Дан массив значений типа double. Скопировать его в новый массив, удаляя повторяющиеся
//значения



#include <stdio.h>
#include <math.h>

int main()
{
    double arr[10] = { 1.1, 2.2, 3.3, 2.2, 5.5, 5.6, 8.3, 10, 4.1, 3.3 };
    double arr1[10] = { 0 };

    //выведем изначальный массив
    puts("Изначальный массив");
    for (int i = 0; i < 10; i++)
    {
        printf("%.2f ", arr[i]);
    }
    int cnt = 0;
    for (int i = 0; i < 10; i++) {
        int duble = 0;
        for (int g = i + 1; g < 10; g++) {
            if (arr[i] == arr[g]) {
                duble++;
            }
        }
        if (duble == 0) {
            arr1[cnt] = arr[i];
            cnt++;
        }
    }

    //выведем нынешний массив
    puts("Итог:");
    for (int k = 0; k < cnt; k++) {
        printf("%.2f ", arr1[k]);
    }

    return 0;
}