//Заданы две матрицы произвольного размера. Реализовать алгоритм умножения матриц. В
//случае, если умножение невозможно, необходимо сообщить пользователю об ошибке



#include <stdio.h>
#include <stdlib.h>

void multiplyMatrices(int firstMatrix[10][10], int secondMatrix[10][10], int result[10][10], int rowFirst, int columnFirst, int rowSecond, int columnSecond) {
    // Инициализируем результирующую матрицу нулями
    for (int i = 0; i < rowFirst; i++) {
        for (int j = 0; j < columnSecond; j++) {
            result[i][j] = 0;
        }
    }

    // Умножение матриц
    for (int i = 0; i < rowFirst; i++) {
        for (int j = 0; j < columnSecond; j++) {
            for (int k = 0; k < columnFirst; k++) {
                result[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
}

int main() {
    int firstMatrix[10][10], secondMatrix[10][10], result[10][10];
    int rowFirst, columnFirst, rowSecond, columnSecond;

    // Ввод размеров первой матрицы
    printf("Введите количество строк и столбцов первой матрицы: ");
    scanf("%d %d", &rowFirst, &columnFirst);

    // Ввод первой матрицы
    printf("Введите элементы первой матрицы:\n");
    for (int i = 0; i < rowFirst; i++) {
        for (int j = 0; j < columnFirst; j++) {
            scanf("%d", &firstMatrix[i][j]);
        }
    }

    // Ввод размеров второй матрицы
    printf("Введите количество строк и столбцов второй матрицы: ");
    scanf("%d %d", &rowSecond, &columnSecond);

    // Проверка возможности умножения
    if (columnFirst != rowSecond) {
        printf("Ошибка: Умножение матриц невозможно. Количество столбцов первой матрицы должно совпадать с количеством строк второй матрицы.\n");
        return 1;
    }

    // Ввод второй матрицы
    printf("Введите элементы второй матрицы:\n");
    for (int i = 0; i < rowSecond; i++) {
        for (int j = 0; j < columnSecond; j++) {
            scanf("%d", &secondMatrix[i][j]);
        }
    }

    // Умножение матриц
    multiplyMatrices(firstMatrix, secondMatrix, result, rowFirst, columnFirst, rowSecond, columnSecond);

    // Вывод результата
    printf("Результат умножения матриц:\n");
    for (int i = 0; i < rowFirst; i++) {
        for (int j = 0; j < columnSecond; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}