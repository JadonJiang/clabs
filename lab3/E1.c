#include<stdio.h>
#define length 100
#define max(a,b) ((a)>(b)?(a):(b))

int fun(char s[], char t[])
{
	int res = -1;
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
			res = max(res, tarindex);
		}
		tarindex++;
	}
	return max(res, -1);
}
void main()
{
	char s[length], t[length];
	scanf("%s %s", s,t);
	printf("%d\n", fun(s, t));
	

}