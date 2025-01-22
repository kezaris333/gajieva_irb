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
#include <string.h>


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
	char* reverse_string = (char*)malloc((len + 1) * sizeof(char));
	if (reverse_string == NULL) {
		printf("ошибка выделения памяти\n");
		return NULL;
	}

	for (int i = 0; i < len; i++)
	{
		reverse_string[i] = str[len - i - 1];
	}
	reverse_string[len] = '\0';
	return reverse_string;
}


//функция преобразования нечетных символов в верхний регистр (-u) 
char* top(const char* str)
{

	int len = calculate_lenght((char*)str);
	char* newtopstr = (char*)malloc((len + 1) * sizeof(char));
	if (newtopstr == NULL) {
		printf("ошибка выделения памяти");
		return NULL;
	}
	for (int i = 0; i < len; i++)
	{
		if (i % 2 == 0)
			newtopstr[i] = str[i];
		else {
			newtopstr[i] = toupper(str[i]);
		}
	}
	newtopstr[len] = '\0';
	return newtopstr;
}


//функция сначала цифры , буквы, потом остальное (-n) 

char* sortstr(char* str)
{
	int len = calculate_lenght(str);

	char* result = (char*)malloc((len + 1) * sizeof(char));
	if (result == NULL) {
		printf("ошибка выделения памяти");
		return NULL;
	}
	int j = 0;


	//попрововать   isdigit isalpha isalnum

	for (int i = 0; str[i] != '\0'; i++)

	{
		if (str[i] >= '0' && str[i] <= '9') { //цифры 
			result[j++] = str[i];

		}
	}

	for (int i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
		{
			result[j++] = str[i]; //буквы 
		}
	}

	for (int i = 0; str[i] != '\0'; i++)
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
char* randseed(int count, char** strings, int seed)
{//count - колво строк в массиве 

	srand(seed); //инициализация семени 

	//создадим массив символов чтоб перемешать их 
	int* index = (int*)malloc(count * sizeof(int));
	if (index == NULL)
	{
		printf("ошибка выделения памяти");
		return NULL;
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
		int temp = index[i];
		index[i] = index[j];
		index[j] = temp;
	}

	int total_len = 1; //считаем длину строки + \0 
	for (int i = 0; i < count; i++)
	{
		total_len += calculate_lenght(strings[index[i]]);
	}

	//памяц 
	char* result = (char*)malloc(total_len * sizeof(char));
	if (result == NULL) {
		printf("ошибка памяти");
		free(index);
		return NULL;
	}

	int pos = 0;  // позиция в результирующей строке 
	for (int i = 0; i < count; i++) {
		char* current_string = strings[index[i]];

		//копируем строку посимвольно 
		for (int j = 0; current_string[j] != '\0'; j++) {
			result[pos++] = current_string[j];

		}
	}
	result [pos] = '\0';

	free(index);

	return result;
}



int main(int argc, char* argv[])
{
	if (argc < 3) {
		printf("недостаточно аргументов\n");
		return 1;
	}


	char flag = argv[1][0]; // флаг передан первым символом 
	char* input_string = argv[2];
	char* result = NULL;

	switch (flag) {
	case 'l': //длинка строки 
		printf("Длина строки: %d\n", calculate_lenght(input_string));
		break;

	case 'r': //реверс 
		result = reverse(input_string);
		if (result != NULL) {
			printf("перевёрнутая: %s\n", result);
			free(result);
		}
		break;

	case 'u': //верхний рег 
		result = top(input_string);
		if (result != NULL) {
			printf("Строка с нечётными буквами в верхнем регистре: %s\n", result);
			free(result);
		}
		break;

	case 'n': //сортировка 
		result = sortstr(input_string);
		if (result != NULL) {
			printf("Отсортированная строка: %s\n", result);
			free(result);
		}
		break;

	case 'c':
		//конкатенация строк в псевдослучайном порядке 
		if (argc < 4) {
			printf("Недостаточное количество аргументов для флага -c\n");
			return 1;
		}
		unsigned int seed = (unsigned int)atoi(argv[3]); // seed находится в argv[3], конвертируем из символа  в цифру 

		//определяем количество строк для обработки 2, 4, 5... 
		int count = 0;
		for (int i = 0; i < argc; i++)
		{
			if (i >= 3)  //конкатенируем сид??? в условии написано про второй аргумент
			{ //учитываем второй аргумент и дальше от 4 
				count++;
			}
		}

		//создаем массив указателей на строки, которые нужно обработать 
		char** selected_strings = (char**)malloc(count * sizeof(char*));
		if (selected_strings == NULL) {
			printf("ошибка выделения памяти\n");
			return 1;
		}

		int index = 0;
		for (int i = 0; i < argc; i++) {
			if (i >= 3) { // спросить про конкатенацию сид
				selected_strings[index++] = argv[i];
			}
		}

		result = randseed(count, selected_strings, seed);
		if (result != NULL) {
			printf("конкатенированная строка: %s\n", result);
			free(result);
		}

		free(selected_strings);
		break;

	default:
		printf("неправильный флаг %c\n", flag);
		return 1;
	}

	return 0;


}
