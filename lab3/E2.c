#include<stdio.h>



int main()
{
	int nums[100] = {0};
	unsigned int num = 0, i = 0,j=0;
	printf("请输入一个十六进制的非负整数:");
	char temp;
	while ((temp=getchar()) && temp!= '\n') {
		nums[i] = temp;
		i++;
	};


	if (nums[6]!=0) {
		printf("超过最大值%u", -1);	
		return 0;
	}


	if (nums[0]!=48 ||(nums[1]!=88 && nums[1]!=120)) {
		printf("非法输入");
		return 0;
	}
	for (j = 2; j < i; j++) {

		if (nums[j] >= 48 && nums[j] <= 57) num = num * 16 + nums[j] - 48;
		else if (nums[j] >= 65 && nums[j] <= 70) num = num*16+ nums[j] - 55;
		else if (nums[j] >= 97 && nums[j] <= 102) num = num * 16+ nums[j] - 87;
		else {
			printf("非法输入");	
			return 0;
		}
	}

	printf("十进制转换结果:%d\n", num);
	
}