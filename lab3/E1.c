#include<stdio.h>
#define length 100
#include<string.h>
#include<stdlib.h>


int fun(char *s, char *t)
{
	int tarindex = 0;
	while (s[tarindex] != '\0')
	{
		int tarlen = tarindex;
		int patlen;
		for (patlen = 0; t[patlen] != '\0'; patlen++)
		{
			if (s[tarlen++] != t[patlen])
			{
				break;
			}
		}
		if (t[patlen] == '\0')
		{
			return tarindex;
		}
		tarindex++;
	}
	return -1;
}
void main()
{
	char s[length], t[length];
	scanf("%s %s", s,t);
	printf("%d\n",fun(s, t));

}
