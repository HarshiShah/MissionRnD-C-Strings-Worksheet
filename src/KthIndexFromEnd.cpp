/*
OVERVIEW: Given a string, return the Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/

char KthIndexFromEnd(char *str, int K) {
	if ((str == '\0') || (K<0))
		return '\0';
	int len, cnt = 0;
	while (str[cnt] != '\0')
		cnt++;
	if (K>cnt - 1)
		return '\0';
	return str[cnt - K - 1];
}