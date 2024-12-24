//Задача 4. Заполнить массив фиксированного размера превдослучайными числами в диапазоне [-1000... 1000]. 
// Реализовать алгоритм поиска максимального и минимального элемента массива и индекса этих элементов, за один проход по массиву.

#include <stdio.h>

int main() {
    int arr[10] = { 199, 838, 109, 12, 2998, 4673, 56, 82, 555, 9876 };
    int min = arr[0];
    int max = arr[0];
    int min_index = 0;
    int max_index = 0;

    for (int i = 1; i < 10; i++)

    {
        if (arr[i] > max) {
            max = arr[i];
            max_index = i;
        }


        if (arr[i] < min) {
            min = arr[i];
            min_index = i;
        }
    }

    printf("min =%d (index %d)\n", min, min_index);
    printf("max =%d (index %d)\n", max, max_index);

    return 0;
}