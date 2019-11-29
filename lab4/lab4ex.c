#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100
int getop(char[]);
int getch(void);
void ungetch(int);

void push(double);

double pop(void);

void PrintStack();

void CopyStack(); 

void ExchangeStack(); 

void ClearStack(); 

int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;

int main() {
	
	
	int type;
	double op2;
	char s[MAXOP];

	while ((type=getop(s))!=EOF)
	{
		switch (type)

		{
		case NUMBER:
			push(atof(s));
			break;
	
		case '+':
		
			push(pop() + pop());
			break;		
		case '*':
			push(pop()*pop());
			break;		
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else

				printf("ERROR : ZERO divisor\n");
			break;
		case '%':   
			op2 = (int) pop();
			if (op2 != 0)
				push((int)pop()%(int)op2);
			else
				printf("Error: ZERO divisor\n");
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default: 
			printf("Error: Unknown command \n");
			break;
		}

	}
	return 0;
}

void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("Error: stack full, cannnot push %g\n", f);
}
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else
		printf("Error: stack empty\n");
	return 0.0;
}

void PrintStack() {
	int temp = sp;
	if (temp > 0)
		printf("Top Stack Element: %.2f", val[--temp]);
	else
		printf("Error: stack empty\n");
}

void CopyStack() {
	
	int temp = sp;

	if (temp < MAXVAL)
		val[sp++] = val[--temp];
	else
		printf("Error: stack full");
}

void ExchangeStack() {
	double temp;
	if (sp >= 2) {
		double num1 = val[--sp];
		double num2 = val[--sp];
		val[sp++] = num1;
		val[sp++] = num2;
	}
	else
		printf("Error: Cannot exchange with empty");
}
void ClearStack() {
	if (sp > 0)
		while (sp) val[--sp] = 0.0;
	else
		printf("Error: stack empty");
}
int getop(char s[]) {
	int i, c;
	while ((s[0] = c = getch()) == ' ' || c == '\t');
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;
	i = 0;
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()));
	if (c == '.')
		while (isdigit(s[++i] = c = getch()));
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);

	return NUMBER;
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