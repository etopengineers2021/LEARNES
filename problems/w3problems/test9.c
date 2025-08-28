#include<stdio.h>// pending
struct Data{
    int day;
    int month;
    int year;
};
struct Data d1;
struct Data d2;
int main(){
    printf("Enter data one order(day, month, year):");
    scanf("%d%d%d",&d1.day,&d1.month,&d1.year);
    printf("data two order(day, month,year )");
    scanf("%d%d%d",&d2.day,&d2.month,&d2.year);
int result = daycounter(d1,d2);
  
    return 0;
}