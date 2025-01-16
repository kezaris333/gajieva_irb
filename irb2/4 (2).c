#include <stdio.h> 
#include <stdarg.h> 
#include <stdlib.h> 

int strlenme(const char* str) { //подсчет длины строки 
    int cnt = 0;
    while (*str != '\0') { //прохожим до конца
        cnt++;
        str++;
    }
    return cnt;
}

//функция поиска подстроки, итог: номер символа 
int find_the_index(const char* str, const char* substr) {
    for (int i = 0; i < strlenme(str); i++) { //проверяем совпадает ли первый символ подстиоки с текущ симвл строки
        if (str[i] == substr[0]) {
            int g = 0; //проверяем остальные
            while (substr[g] != '\0' && str[i + g] == substr[g]) {
                g++;
            }//если дошли до конца строки значит найденоо
            if (substr[g] == '\0') {
                return i + 1; //возвращаем индекс
            }
        }
    }
    return -1;
}

void find_substr(const char* substr, int count, ...) {
    va_list args;
    va_start(args, count);

    //проходим по каждому файлу переданному в аргументах
    for (int i = 0; i < count; i++) {
        const char* filename = va_arg(args, const char*); //получаем имя файла
        FILE* file = fopen(filename, "r");

        if (file == NULL) {
            printf("нельзя открыть файл: %s\n", filename);
            continue;
        }

        printf("поиск в файле: %s\n", filename);

        char buffer[1024]; //буф для чтения строк из файла
        int line_number = 1;//счетсичк номеров строк
        int pos_in_file = 0; //счетчик позиций в файлк

        while (fgets(buffer, sizeof(buffer), file)) { //считываем построчно
            int pos = 0; //счетч позиции в строке
            while (buffer[pos] != '\0') {
                int match = 1;
                for (int j = 0; substr[j] != '\0'; j++) {
                    if (buffer[pos + j] != substr[j]) {
                        match = 0; //если не совпадает то флаг 0

                        break;
                    }
                }
                if (match) { //если совпдение найдено 
                    printf("Строка %d, позиция %d\n", line_number, pos + 1);
                }
                pos++; //след символ в строке
            }
            line_number++; //увелич номер строки
            pos_in_file += strlenme(buffer); //обновл позицию в файле
        }

        fclose(file);
    }

    va_end(args);
}

int main() {
    find_substr("test", 2, "file1.txt", "file2.txt");
    return 0;
}



