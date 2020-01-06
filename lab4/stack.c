#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100


int getop(char[]);
int getch(void);
void ungetch(int);
void push(double);
double pop(void);
void clear(void); 
double top(void);

int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;

main() {
	
	
	int type;
	double op1;
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
			op2=(int)pop();
			if (op2 != 0)
				push((int)pop()%(int)op2);
			else
				printf("Error: ZERO divisor\n");
			break;
		case'p':
			op2=pop();
			push(op2);
		    break;
		case'c':
		    clear();
		    break;
		case'd':
		    op2=pop();
		    push(op2);
		    push(op2);
		    break;
		case's':
		    op1=pop();
		    op2=pop();
		    push(op1);
		    push(op2);
		    break;
		case'o':
		    for(int i=0;i<sp;i++)
			 printf("%g\t",val[i]);
		case '\n':
			printf("\t%.8g\n", top());
			break;
		default:
			printf("Error: Unknown command %d\n", s);
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


void clear(void)
{
	sp=0;
}

int getop(char s[]) {
	int i, c;
	while ((s[0] = c = getch()) == ' ' || c == '\t');
	s[1] = '\0';
	i=0;
	if (!isdigit(c) && c != '.'&&c !='-')
		return c;
	
	if (c=='-')
	    if(isdigit(c = getch())|| c =='.')
		 s[++i]=c;
	    else{
			if(c!=EOF)
			  ungetch(c);
			return '-';
		} 
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

double top(){
	double op2;
    op2=pop();
	push(op2);

	return op2;

}
