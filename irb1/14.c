//.В текстовом файле задан целочисленный массив. Разделительный символ между
//значениями – пробел.Файл корректный.Необходимо считать данные из файла, заполнить
//массив и найти в этом массиве максимальный и минимальные элементы.При реализации
//используйте функцию из задания 4

#include <stdio.h>


int main() {
    FILE* file;
    int numbers [100];
    int max;
    int min;
    int count = 0;

    
    file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("ошибка чтения файла.\n");
        return 1;
    }

   
        while ((count < 100) && (fscanf_s(file, "%d", &numbers[count]) == 1)) {
            count++;
        }

    int max = numbers[0];
    int min = numbers[0];
    
    puts("��� ������:");
    for (int g = 0; g < count; g++) {
        if (numbers[g] > max) {
            max = numbers[g];
        }
        if (numbers[g] < min) {
            min = numbers[g];
        }
        printf("%d ", numbers[g]);
    }
    puts("");
   
    printf("максимум %d\n", max);
    printf("минимум %d\n", min);

    fclose(file);
    return 0;
}