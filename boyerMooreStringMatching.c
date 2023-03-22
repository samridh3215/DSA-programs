
# include <limits.h>
# include <string.h>
# include <stdio.h>


int max (int a, int b) { return (a > b)? a: b; }

void initTable( char *str, int size,int table[256])
{
	int i;
	for (i = 0; i < 256; i++)
		table[i] = -1;
	for (i = 0; i < size; i++)
		table[(int) str[i]] = i;
}

void search( char *text, char *pattern)
{
	int patternSize = strlen(pattern);
	int textSize = strlen(text);

	int table[256];
	initTable(pattern, patternSize, table);

	int start = 0; 
	while(start <= (textSize - patternSize))
	{
		int j = patternSize-1;

		while(j >= 0 && pattern[j] == text[start+j])
			j--;
		if (j < 0)
		{
			printf("pattern occurs at %d", start);

			start += (start+patternSize < textSize)? patternSize-table[text[start+patternSize]] : 1;

		}

		else
			start += max(1, j - table[text[start+j]]);
	}
}

int main()
{
    char str[100], pattern[100];
    printf("Enter string: ");
    scanf("%s",str);
    fflush(stdin);
    printf("enter pattern: ");
    scanf("%s", pattern);
    search(str, pattern);
	return 0;
}
