#include <stdio.h>


int main() {


	int cnt = 0;
	unsigned int num = -1;


	printf("Max value of unsigned int %u\n", num);

	
	while (num != 0) {

		cnt++;  
		num /= 2; 
	};

	printf("Max bit of unsigned int %d\n", cnt);
	system("pause");
	return 0;
}
