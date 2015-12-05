/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>

void number_to_str(float number, char *str, int afterdecimal){
	int len = 0, cnt, i = 0;
	int num = number / 1;
	if (number < 0.0)
		num = -num;
	while (num >= 1){
		num = num / 10;
		len++;
	}
	if (number < 0.0){
		cnt = len++;
		str[0] = '-';
		i = 1;
		number = -number;
	}
	else
		cnt = len - 1;
	num = number / 1;
	while (cnt >= i){
		str[cnt--] = (num % 10) + '0';
		num = num / 10;
	}
	if (afterdecimal > 0)
		str[len++] = '.';
	while (afterdecimal>0){
		number = number * 10;
		num = number / 1;
		str[len++] = (num % 10) + '0';
		afterdecimal--;
	}
	str[len] = '\0';
}
