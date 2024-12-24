//Реализовать функцию преобразования строкового представления числа в системе 
//счисления с основанием из диапазона[2..36] в число типа int, заданного в системе 
//счисления с основанием 10. 


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void reverse(char str[]) 
{
	int sizestr = strlen(str);
	for (int i = 0; i < sizestr / 2; i++)
	{
		char temp = str[i];
		str[i] = str[sizestr - i - 1]; //еще минус один, так завершающий ноль
		str[sizestr - i - 1] = temp;
	}
}


	 int change_to_ten(char* value, int sys)
 {
	 reverse(value);
	 int len = strlen(value);

	 int value_in_ten = 0;
	 for (int i = 0; i < len; i++) {
		 if (value[i] >= '0' && value[i] <= '9')
		 {
			 value_in_ten = (value[i] - '0') * pow(sys, i);
		 }

		 else if (value[i] >= 'A' && value[i] <= 'Z')
		 {
			 value_in_ten = (value[i] - 'A') * pow(sys, i);
		 }

		 else 
		 {
			 printf("Error value");
			 return -1;
		 }
	 }
	 return value_in_ten;
 }

 int main () {
	 char* value = (char*)malloc(50 * sizeof(char);
	 if (value == NULL)
	 {
		 printf("error with memory");
	 return 1;
	 }

	 int sys;
	 printf("enter the number");
	 scanf("%s", value);
	 puts("");

	 printf("enter the system");
	 scanf("%d", &sys);
	 if (sys < 2 || sys>36) 
	 {
		 printf("error system value");
		 return 1;
	 }

	 int num_in10 = change_to_ten(value, sys);
	 if (num_in10 != -1) {
		 printf("number in 10 system: %d\n", num_in10);
	 }

	 free(value);

	 return 0;
 }



        
   