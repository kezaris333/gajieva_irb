////Реализовать функцию с переменным числом аргументов, принимающую координаты 
//(вещественного типа, пространство двумерное) вершин многоугольника и определяющую, 
//является ли этот многоугольник выпуклым.Продемонстрируйте работу функции. 


#include <stdio.h> 
#include <stdarg.h> 
#include <stdlib.h> 

int polygon(int count, ...) { //х, у, count количество введенных координат 
    va_list coor;
    va_start(coor, count);

    int n;
    if (count % 2 == 0 && count >= 6) //если колво координат верное (четное) то рассчитываем количество вершин многоугольника 
        n = count / 2;
    else {
        printf("неправильное (нечетное) количество введеных координат");
        va_end(coor);
        return 1;
    }

    double* x = malloc(n * sizeof(double)); //массив для хранения координат 
    if (x == NULL)
    {
        printf("ошибка выделения памяти");
        return -1;
    }
    double* y = malloc(n * sizeof(double)); //массив для хранения координат 
    if (y == NULL)
    {
        free(x);
        printf("ошибка выделения памяти");
        return -1;
    }

    printf("вееденные координаты:\n");
    for (int i = 0; i < n; ++i) {
        x[i] = va_arg(coor, double); //получаем и записываем в массив координаты
        y[i] = va_arg(coor, double);
        printf("Точка %d: (%.4f, %.4f)\n", i + 1, x[i], y[i]);
    }

  
    double* multiplication = malloc(n * sizeof(double));
    if (multiplication == NULL)
    {
        free(x);
        free(y);
        printf("ошибка выделения памяти");
        va_end(coor);
        return -1;
    }

    int k = 0;
    

    //находим векторные произведения 
    for (int i = 0; i < n; i++)
    {
        int next = (i + 1) % n;
        int next_next = (i + 2) % n;

        //вычисляем векторы 

        double v1x = x[next] - x[i];
        double v1y = y[next] - y[i];
        double v2x = x[next_next] - x[next];
        double v2y = y[next_next] - y[next];

        //вычисляем векторное произведение 
        multiplication[k] = v1x * v2y - v1y * v2x;
       
        printf("произведение %d = %.4f\n", k + 1, multiplication [k]);
        k++;

    }

        

    int all_positive = 1;
    int all_negative = 1;

    for (int i = 0; i < n; i++) {
        if (multiplication[i] < 0)
            all_positive = 0;
        if (multiplication[i] > 0)
            all_negative = 0;
    }

    free(x);
    free(y);
    free(multiplication);
    va_end(coor);

    if (all_positive || all_negative) //если хоть одно условие выполнилось, то есть осталось равно 1  
    {
        printf("выпуклый");
        return 1;
    }
    else {
        printf("невыпуклый");
        return 0;
    }

}


int main() {

    polygon(6, 38.23, 42.2, 94.1, -11.3, 23.234, 79.0);


    return 0;
}
