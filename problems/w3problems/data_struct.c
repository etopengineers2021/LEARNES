#include<stdio.h>
struct data {
    int day;
    int month;
    int year;

};
struct data s1;
struct data s2;
int main(){
puts("Inputs details for data 1(day month year):");
scanf("%d %d %d",&s1.day,&s1.month,&s1.year);
puts("Inputs details for Data 2 (day month year):");
scanf("%d %d %d",&s2.day,&s2.month,&s2.year);

printf("check %d",s1.day);

}

