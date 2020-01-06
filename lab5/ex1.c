#include<stdio.h>
#include<string.h>
#define length 100


void reverser(char s[],int i,int len);


int main()
{
    char s[length];
    gets(s);
    reverse(s);
    printf("%s\n", s);

}

void reverse(char s[])
{

    reverser(s,0,strlen(s));

}


void reverser(char s[],int i,int len)
{
    int c,j;

    j=len-(i+1);
    if(i<j){
        c=s[i];
        s[i]=s[j];
        s[j]=c;
        reverser(s,++i,len);
    }
}