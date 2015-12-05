/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/

char removeSpaces(char *str) {
	if (str == '\0')
		return '\0';
	int cnt1 = 0, cnt2 = 0;
	while (str[cnt1] != '\0'){
		if (str[cnt1] != ' '){
			if (cnt1 != cnt2)
				str[cnt2] = str[cnt1];
			cnt2++;
		}
		cnt1++;
	}
	str[cnt2] = '\0';
	return str[0];
}
