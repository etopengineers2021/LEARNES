/*************************************************************

check integer range.

****************************************************************/
#include<stdio.h>
int main(){ 
    int  c = 1 ;
    while(c <5){
        c++;
    int i ;
    printf("%d\n",c);
    printf("enter the numbers:");
    scanf("%d",&i);
    if( i>=0 && i<= 20){
   printf("[0,20]\n");
    }
    else if( i >=21 && i <= 40) {
        printf("[21,40]\n");
     }
     else if( i>= 41 && i<= 60)
     printf("[41,60]\n");
     else if(i >= 61 && i<=80)
     printf("[61,80]\n");

    
    else 
    printf("nagtive number\n");
    }

 return 0;
}