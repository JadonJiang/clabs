#include <stdio.h>


int main () {
    char str[40];
    int remainder[32];
    int b,k,i,cnt=0;
    unsigned int a =-1;
    k=0;
	
// 	输出最大数-1
    printf("Max value of unsiened int %u\n",a);
	
	
	
//  转二进制	
    while (a!=0){
        b=a/2;
        k++;
        remainder[k]=a-b*2;
        a=a/2;
    };
    for (i=k;i>=1;i--){
	if (remainder[i]==1){
		cnt++;
		}
			       
    } 

	
    printf("Max bit of unsiened int %d\n",cnt);
    return 0;
}