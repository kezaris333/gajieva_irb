//Реализовать функцию перевода числа из десятичной системы счисления в систему счисления с 
//основанием 2^𝑟, 𝑟 = 1, …, 5 (системы 2,4,8,16,32).При реализации функции разрешается использовать битовые  
//операции и операции обращения к памяти, запрещается использовать стандартные 
//арифметические операции.Продемонстрируйте работу реализованной функции. 

#pragma warning(disable: 4996) 
#include <stdio.h> 
#include <string.h> 


int plus(int number, int carry) 
{
	//int carry = 1; //унжно прибавить единицу 
	while (carry != 0) { //операция продолжается, пока есть перенос 
		int sum = number ^ carry;  //101^001 = 100  
		carry = (number & carry) << 1; //считаем перенос 101 & 001 == 001 (умнож)  carry = 001 
		number = sum;  //число = 100 
	}
	return number;
}



int minus(int number, int min) 
{
	int temp = plus(~min, 1); //конвертация в отррицательное

	return plus(number,temp);
}


void reverse_string(char* str, int length) 
{
	int start = 0;
	int end = minus(length, 1);

	while (start < end) {
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start = plus (start, 1);
		end = minus (end, 1); //-1 
	}
}



void convert_to_r(int r, int num)  //например num =1900, r=5 
{ //маска для полуечния остатка от деления на 2^r 
	if (r < 1 || r > 5) {
		printf("Неверное основание системы счисления! Должно быть от 2 до 32.\n");
		return;
	}

	unsigned int mask = minus(1 << r, 1); //получим маску 11111 илии 31 
	char result[65];
	int index = 0;

	//если число 0, обрабатываем отдельно 
	if (!num) {
		result[index] = '0';
		index = plus(index, 1);
		result[index] = '\0';
		printf("число в системе основания 2^%d: %s\n", r, result);
		//free 
		return;
	}

	while (num > 0) {//получаем остаток при делении с помощью побитовой операции . деление на 2 = убрать последний бит, на 4 = последние два бита и тд 
		unsigned int balance = num & mask; //12345 & 31 = 13 (1101) 

		if (balance < 10)

		{
			result[index] = '0' | balance; //если остаток меньше 10, то это цифра 
			//попробовать поменять + на | 
		}
		else
		{
			result[index] = 'A' | minus (balance, 10); //если остаток больше 10, то это символ 
		}

		index = plus(index, 1);
		num = num >> r; //сдвиг для деления на 2^r/ после первого итерация num станет 385  12345>>5 

	}
	result[index] = '\0';

	//реверс строки 
	reverse_string(result, index);

	printf("число в системе основания 2^%d  %s ", r, result);


}


int main() {

	int num;
	int r;

	printf("Введите число в десятичной системе");
	scanf("%d", &num);
	printf("\nВведите степень числа r от 1 до 5 (2^r)\n");
	scanf("%d", &r);
	if (r < 1 || r > 5)
	{
		printf("/n неправильная степень");
		return -1;
	}

	convert_to_r(r, num);

	return 0;

}

