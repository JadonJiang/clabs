#include <stdio.h>
int main()
{
    int fahr,celsius;
    int lower,upper,step; 

    lower=0;
    upper=100;
    step=5;
    celsius=lower;
    printf("Celsius-Fahrenheit table\n");
    while (celsius<=upper)
    {
        fahr=celsius*5/9+32;
        printf("%d\t%d\n",celsius,fahr);
        celsius=celsius+step;
    }
    return 0;

}