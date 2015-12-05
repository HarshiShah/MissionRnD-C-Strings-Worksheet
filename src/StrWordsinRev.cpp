/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void rev_word(char* str, int start, int end);

void str_words_in_rev(char *input, int len){
	int start = 0, i = 0;
	while (i < len){
		if (input[i] == ' '){
			if (input[i - 1] != ' ')
				rev_word(input, start, i - 1);
			start = i + 1;
		}
		i++;
	}
	if (start != 0){
		rev_word(input, start, len - 1);
		rev_word(input, 0, len - 1);
	}

}

void rev_word(char* str, int start, int end){
	char temp;
	while (start < end){
		temp = str[start];
		str[start++] = str[end];
		str[end--] = temp;
	}
}

