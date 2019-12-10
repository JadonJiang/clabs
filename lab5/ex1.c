#include <stdio.h>
#include <stdlib.h>

void revserse(char str[]);


int main(int argc)
{
	char str[100];
	gets(str);
	revserse(str);
	printf("%s\n", str);
	
}

void revserse(char str[]){
	int begin = 0;
	int end = strlen(str) - 1;
	for (begin = 0; begin < end; begin++) {
		char temp = str[begin];
		str[begin] = str[end];
		str[end] = temp;
		end--;
	}

}
