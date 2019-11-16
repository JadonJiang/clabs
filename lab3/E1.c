#include<stdio.h>

#define length 20
int strrindex(char str[],char  flag) {
	int i = 0;
	int res = -1;
	for (i = 0; i < length; i++) {
		if (str[i] == flag) res = i;
	}
	return res;
}

int main()
{
	char str[length] = { 0 };

	int i = 0;
	char word;
	printf("请输入一串字符:\n");
	char temp;
	while ((temp = getchar()) && temp != '\n') {
		str[i] = temp;
		i++;
	};//判断是否读到数字
	printf("请输入一个字符:\n");
	scanf("%c", &word);


	printf("结果:%d", strrindex(str,word));
	
	return 0;
}