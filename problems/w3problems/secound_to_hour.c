#include<stdio.h>
int main(){ 
    //find sec 
    int a = 25300 ;
    int temp = a / 60 ; //total minite

    int hour = temp / 60 ;
   
    int sec = temp % 60 ;
    printf("HOUR  %d\n",hour);
    printf("MINITE %d\n",temp);
    printf("seconds %d\n",sec);
}