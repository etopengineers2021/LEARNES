#include<stdio.h>
   int num ; 
    int temp ;
int main(){
    //  int num = 0; 
    // int temp =0  ;
 printf("Enter the number:");          scanf("%d",&num);
if(num > 0){
        temp= num / 100;
        printf("100 notes = %d\n",temp);
        num = num % 100;
     //   printf("moduls %d\n",num);
        temp  = num / 50;
        printf("50 rupies notes = %d\n",temp );
        num = num % 50; 
        temp = num / 20;
        printf("20 rupies notes = %d\n",temp);
        num = num % 20 ;
        temp = num / 10;
        printf("10 rupies notes = %d\n",temp);
        num = num % 10;
        temp = num / 5;
        printf(" 5 rupies notes = %d\n",temp);
        num = num % 5;
        temp =num/ 2;
        printf(" 2 rupie coin   = %d\n", temp);
        num = num % 2;
        temp = num / 1;
        printf("one roupie coin = %d\n",temp);
         
    }
   
}