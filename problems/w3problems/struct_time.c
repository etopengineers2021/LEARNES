#include<stdio.h>
struct Time {
    int member;
    int hours;
    int mint;
    int sec;

};
struct Time t1;
struct Time t2;
struct Time result ;
int main(){
   // puts("try again");
printf("Input the first time(hours minutes seconds):");   scanf("%d%d%d",&t1.hours,&t1.mint,&t1.sec);
printf("Input the second time(hours minutes second):");   scanf("%d%d%d",&t2.hours,&t2.mint,&t2.sec);

printf("hour: %d mint: %d second: %d\n",t1.hours,t1.mint,t1.sec);
      printf("\n");
printf("Hour: %d mint: %d second: %d\n",t2.hours,t2.mint,t2.sec);
result.sec = t1.sec + t2.sec;
result.mint = t1.mint + t2.mint + result.sec / 60;
result.hours = t1.hours + t2.hours + result.mint / 60;
 result.mint %= 60;
 result.sec %= 60;
puts("***********************************************************\n");
printf("Result :%d:%d:%d \n",result.hours,result.mint,result.sec);
}