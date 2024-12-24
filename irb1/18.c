#include <stdio.h>

int main() {
    int i = 4;
    int j = 4;
    int matrix[4][4] = {
        {64, 36, 90, 34},
        {65, 12, 87, 17},
        {92, 31, 45, 51},
        {33, 63, 46, 29}
    };
    int newmatrix[4][4];

    printf("дана матрица размером 4 на 4:\n");
    for (int row = 0; row < i; row++) {
        for (int col = 0; col < j; col++) {
            printf("%d ", matrix[row][col]);
        }
        printf("\n");
    }

    //nранспонирование
    for (int row = 0; row < i; row++) {
        for (int col = 0; col < j; col++) {
            newmatrix[col][row] = matrix[row][col]; //копируем значения с изменением индексов
        }
    }

    printf("транспонированная матрица:\n");
    for (int row = 0; row < j; row++) {
        for (int col = 0; col < i; col++) {
            printf("%d ", newmatrix[row][col]);
        }
        printf("\n");
    }

    return 0;
}