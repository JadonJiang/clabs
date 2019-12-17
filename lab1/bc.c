#include<stdio.h>

int main() {
    int num;
    int cout= 0;
    scanf("%d",&num);
    if(num<=99999){
    while(num) {
        if(num%2==1)cout++;
        num/=2;
    }
    printf("%d",cout);}
    else{
        printf("number too large");
    }

    return 0;
}