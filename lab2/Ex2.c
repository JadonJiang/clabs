#include<stdio.h>

int cout_one_bits(unsigned int value)
{
	int cout = 0;
	while (value)
	{
		value = value & (value - 1);
		cout++;
	}
	return cout;
}

void main()
{	
	int nums[10];
	unsigned int num=0, i=0;
	printf("请输入一个数字:");

	while ((nums[i] = getchar()) && nums[i] != '\n')//判断是否读到数字
	{
		num = num * 10 + nums[i] - '0'; //这一步是关键，相当于<<
	}
	printf("%d",cout_one_bits(num));
	return 0;
}