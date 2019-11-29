#include<stdio.h>
#define X 0.54
 

 int main()  { 


 float f;
 float m;
 float son;

 printf("请输入父亲的身高:\n");
 scanf("%f",&f);

 printf("请输入母亲的身高:\n");
 scanf("%f",&m);

 son=(f+m)*X;

 printf("儿子的预测身高为:%f\n",son);

 return son;

 }