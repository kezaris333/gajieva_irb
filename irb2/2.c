//Через аргументы командной строки программе подаются флаг(первым аргументом), строка
//(вторым аргументом); и(только для флага - c) целое число типа unsigned int и далее произвольное
//количество строк.Флаг определяет действие, которое необходимо выполнить над переданными
//строками :
//● - l подсчёт длины переданной строки, переданной вторым аргументом;
//● - r получить новую строку, являющуюся перевёрнутой(reversed) переданной вторым
//аргументом строкой;
//● - u получить новую строку, идентичную переданной вторым аргументом, при этом каждый
//символ, стоящий на нечётной позиции(первый символ строки находится на позиции 0),
//должен быть преобразован в верхний регистр;
//● - n получить из символов переданной вторым аргументом строки новую строку так, чтобы в
//начале строки находились символы цифр в исходном порядке, затем символы букв в исходном
//порядке, а в самом конце – все остальные символы, также в исходном порядке;
//● - c получить новую строку, являющуюся конкатенацией второй, четвёртой, пятой и т.д.
//переданных в командную строку строк; строки конкатенируются в псевдослучайном порядке;
//для засеивания генератора псевдослучайных чисел функцией srand используйте seed равный
//числу, переданному в командную строку третьим аргументом.
//Для каждого флага необходимо реализовать соответствующую ему собственную функцию,
//выполняющую действие.Созданные функциями строки должны располагаться в выделенной из
//динамической кучи памяти.При реализации функций запрещено использование функций из
//заголовочного файла string.h.Продемонстрируйте работу реализованных функций



#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


//функция для подсчета длины строки (-l)
int calculate_lenght(char* str) 
{
	int len = 0;
	while (str[len] != '\0') {
		len++;
	}
	return len;
}


//функ переворота (-r)
char* reverse(char* str) 
{
	int len = calculate_lenght(str);
	char * reverse_string = (char*)malloc((len+1)*sizeof(char));
	if (reverse_string == NULL) {
		printf("ошибка выделения памяти");
			return - 1;
	}

	for (int i = 0; i < len; i++) 
	{
		str[i] = reverse_string [len - i - 1];
		reverse_string[len] = '\0';
	}
	return reverse_string;
}


//функция преобразования нечетных символов в верхний регистр (-u)
char* top(const char* str) 
{

	int len = calculate_lenght ((char*)str) ;
	char * newtopstr = (char*)malloc((len + 1) * sizeof(char));
	if (newtopstr == NULL) {
		printf("ошибка выделения памяти");
		return -1;
	}
	for (int i = 0; i < len; i++) 
	{
		if (i % 2 == 0) 
			newtopstr[i] = str[i];
		else {
			newtopstr[i] = toupper(str[i]);
		}
	}
	newtopstr [len] = '\0';
	return newtopstr;
}


//функция сначала цифры , буквы, потом остальное (-n)

char* sortstr(char* str)
{
	int len = calculate_lenght(str);

	char* result = ((char*)malloc((len + 1) * sizeof(char)));
	if (result == NULL) {
		printf("ошибка выделения памяти");
		return NULL;
	}
	int j = 0;
	int i = i;


	for (i = 0; str[i] != '\0'; i++)

	{

		if (str[i] >= '0' && str[i] <= '9') { //цифры
			result[j++] = str[i];
			i++;

		}
	}
		
	for (i = 0; str[i] != '\0'; i++)
	{

		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
			result[j++] = str[i]; //буквы
			i++;
		}
	}

	for (i = 0; str[i] != '\0'; i++) 
	{

		if (!((str[i] >= '0' && str[i] <= '9') ||
			(str[i] >= 'A' && str[i] <= 'Z') ||
			(str[i] >= 'a' && str[i] <= 'z'))) 
		{
			result[j++] = str[i]; //остальные символы
		}

	}
	result[j] = '\0';



	return result;
}


//● - c получить новую строку, являющуюся конкатенацией второй, четвёртой, пятой и т.д.
//переданных в командную строку строк; строки конкатенируются в псевдослучайном порядке;
//для засеивания генератора псевдослучайных чисел функцией srand используйте seed равный
//числу, переданному в командную строку третьим аргументом.
char* randseed (int count, char **strings, int seed) 
{//count - колво строк в массиве

	strand(seed); //инициализация семени
	
	//создадим массив символов чтоб перемешать их
	int* index = (int*) malloc(count * sizeof(int));
	if (index == NULL) 
	{
		printf("ошибка выделения памяти");
		return -1;
	}


	//инициализация массива индексов
	for (int i = 0; i < count; i++) 
	{
		index[i] = i;
	}
	 
	//перемешиваем  индексы по  алгритму фишера йейейейеейтса
	for (int i = count - 1; i > 0; i--) 
	{
		int j = rand() % (i + 1); //гарантирует что j будет между 0 и i+1

		//обмен индексов 
		int temp = index [i];
		index[i] = index[j];
		index[j] = temp;
	}

	int total_len = 1; //считаем длину строки + \0
	for (int i = 0; i < count; i++) 
	{
		int len = 0;
		while (strings[i][len] != '\0') {
			len++;
		}
		total_len = total_len + len;
	}

	//памяц
	char* result = (char*)malloc(total_len * sizeof(char));
	if (result == NULL) {
		printf("ошибка памяти");
		return -1;
	}

	int pos = 0;  // позиция в результирующей строке
	for (int i = 0; i < count; i++) {
		char* current_string = strings[index[i]];

		//копируем строку посимвольно
		for (int j = 0; current_string[j] != '\0'; j++) {
			char current_char = current_string[j];
			result[pos] = current_char;
			pos++;
		}
	}
	result[pos] = '\0';

	// Освобождаем временную память
	free(index);

	return result;
}



int main(int argc, char* argv[]) 
{
	if (argc < 3) {
		printf("недостаточное колчество аргументов");
		return 1;
	}


}
