//Задача  6. Дана квадратная матрица произвольного размера. Необходимо найти определитель
//матрицы
#include <stdio.h>

int oprdel(int arr[3][3]) {
    int result = (arr[0][0] * arr[1][1] * arr[2][2]) + (arr[0][1] * arr[1][2] * arr[2][0])
        + (arr[0][2] * arr[1][0] * arr[2][1]) - (arr[0][2] * arr[1][1] * arr[2][0])
        - (arr[0][1] * arr[1][0] * arr[2][2]) - (arr[0][0] * arr[1][2] * arr[2][1]);

    return result;
}

int main() {
    int result;

    int arr[3][3];

    for (int i = 0; i < 3; i++) {
        for (int g = 0; g < 3; g++) {
            printf("Enter value [%d][%d]:", i, g);
            scanf_s("%d", &arr[i][g]);
            puts("");
        }
    }

    result = oprdel(arr);


    printf("Result opedeliteeeeeel %d", result);

    return 0;
}