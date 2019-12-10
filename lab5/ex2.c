#include<stdio.h>
#include<ctype.h>
#define N 100
#define BUFSIZE 100
int getfloat(float* p);

int getch(void) ;
void ungetch(int c);
char buf[BUFSIZE];
int bufp = 0;
int main(void)
{
	float arr[N] = { 0.0 };
	int i, r;
	for (i = 0; i<N; i++)
	{
		while ((r = getfloat(&arr[i])) == 0)
			getch();
		if (r == EOF || r ==10 || r==13)//'\n'的ASCII值
			break;
	}
	float sum=0.0;
	while (i>=0) {
		
		sum += arr[i];
		i--;
	}
	printf("Total sum:%f\n", sum);
	return 0;

}
int getfloat(float* p)
{
	float power;
	int c, sign;
	while (isspace(c = getch()));
	//读取了一个非数字的字符，如果这个字符不是数字，
	//且不是结束标志，那么把该字符放回到输入中，
	//保证getint下一次正确读入或其它函数,程序调用输入。
	if (!isdigit(c) && c != '+'&&c != '-'&&c != '.'&&c != EOF&&c != '\n')
	{
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();
	for (*p = 0.0; isdigit(c); c = getch())
		*p = 10 * *p + (c - '0');

	if (c == '.')
		c = getch();
	for (power = 1.0; isdigit(c); c = getch())
	{
		power *= 10;
		*p = 10 * *p + (c - '0');
	}
	*p *= (sign / power);
	if (c != EOF)
		ungetch(c);
	return c;

}
int getch(void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}