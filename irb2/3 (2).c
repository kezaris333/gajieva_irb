//Реализовать функцию с переменным числом аргументов, выполняющую возврат ресурсов в
//контекст запроса :
//● возврат в кучу ранее выделенной динамической памяти
//● закрывающую ранее открытые под файлы файловые переменные
//Для конфигурирования действий по возврату ресурса, для каждого ресурса в функцию
//необходимо передать два параметра : указатель на ресурс и флаг действия.При получении из
//списка аргументов переменной длины указателя на ресурс со значением NULL, обработка списка
//аргументов переменной длины должна быть прекращена.Передача количества аргументов в
//функцию при этом не допускается.Продемонстрируйте работу реализованной функции.


//функция чтоб сразу закрывала все открытые файлы и очищала память

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

void cleanup (int flag, ...)
{
	va_list args; //указатель на ва_лист
	va_start (args, flag);
	void* pointer; //указатель на следующую переменную


	while ((pointer = va_arg (args, void *)) != NULL) //повторяем пока укзатель не будет равен нулю
	{

	int current_flag = va_arg(args, int);
	switch (current_flag)
		{
		case 1: //очистка памяти
				free(pointer);
				break;

		case 2: //закрытие файла
				fclose ((FILE*)pointer); 
				break;

		default: //иные неправильные флаги
				printf ("ошибка флага\n");
				break;

		}

	}
	va_end(args);

	return NULL;
}



int main()
{
	
		FILE* fi = fopen("123.txt", "w");
		if (fi == NULL) 
		{
			printf("ошибка открытия файла");
			return 1;
		}

		char* dynamic_array_of_char = NULL;

		dynamic_array_of_char = (char*)malloc(10 * sizeof(char));

		if (dynamic_array_of_char == NULL)
		{
			printf("ошибка выделения памяти");
			return 1;
		}

		cleanup(0, fi, 2, dynamic_array_of_char, 1, NULL);


	return 0;
}
