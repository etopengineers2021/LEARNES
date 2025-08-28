#include<stdio.h>
int main(){
    int days = 0;
    printf("Enter days:");scanf("%d",&days);
    int year= days/365 ;
    int week  = (days % 365) /  7;
     days = days -((year*365) + (week*7));
    printf("DAY =%d TO YEAR  %d\n",days,year);
    printf("week %d\n",week);
     printf("days %d\n",days);
    return 0;
}