#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define length 100
int day[3]={0};
static char daytab[2][13] = {
	{0,31,28,31,30,31,30,31,31,30,31,30,31},
	{ 0,31,29,31,30,31,30,31,31,30,31,30,31 }
};

int day_of_year(int year, int month, int day) {
	int i, leap;
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

void  split(char str[]){
	int i = 0;
	day[0]=0;
	day[1]=0;day[2]=0;
	while (str[i]!= '/') day[0] = 10*day[0] + (str[i++] - '0');
	while (str[++i] != '/')day[1] = 10 *day[1] + (str[i] - '0');
	while (str[++i] != '/'&& str[i]!='\000') day[2] = 10 * day[2] + (str[i] - '0');
	

}

void main(char argc, char *argv[]) {
	
	split(argv[1]);
	int cnt1 = day_of_year(day[0], day[1], day[2]);
	
	
	split(argv[2]);
	int cnt2 = day_of_year(day[0], day[1], day[2]);
	printf("%d \n",cnt2-cnt1+1);



}