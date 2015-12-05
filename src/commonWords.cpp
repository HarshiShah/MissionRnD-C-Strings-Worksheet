/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include <malloc.h>

#define SIZE 31

int isPresent(char* str1, char* str2);
char ** commonWords(char *str1, char *str2) {
	if (str1 == '\0' || str2 == '\0')
		return NULL;
	char **list = (char**)malloc(sizeof(char*)* 31);
	for (int i = 0; i < 31; i++)
		list[i] = (char*)malloc(sizeof(char)* 31);
	int i = 0, j = 0, k = 0;
	while (str1[i] != '\0'){
		if (str1[i] != ' '){
			list[j][k++] = str1[i];
		}
		else{
			list[j][k] = '\0';
			if (k>0 && isPresent(list[j], str2) == 1)
				j++;
			else
				list[j][0] = '\0';
			k = 0;
		}
		i++;
	}
	if (j == 0)
		return NULL;
	if (isPresent(list[j], str2) == 1)
		j++;
	else
		list[j][0] = '\0';
	list = (char**)realloc(list, sizeof(char*)*j);
	return list;
}


int isPresent(char* str1, char* str2){
	int cnt = 0, i = 0, compare = 1;
	while (str2[i] != '\0' &&  str1[cnt] != '\0'){
		if (str2[i] == ' ')
			compare = 1;
		else if (compare == 1){
			if (str1[cnt] == str2[i])
				cnt++;
			else{
				cnt = 0;
				compare = 0;
			}
		}
		i++;
	}
	if (str1[cnt] == '\0')
		return 1;
	else
		return 0;

}