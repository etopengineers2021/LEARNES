/*****************************************************************
sum all numbers between two integers , excluding multiples of 15
****************************************************************** */

#include<stdio.h>
int main(){
    int a = 0,sum = 0;
    int  b =0 ;
    int temp = 0;
    printf("Enter input 1 :");
    scanf("%d",&a);
    printf("Enter input 2 :");
    scanf("%d",&b);
    if(a > b){
      temp = a;
      a = b;
      b = temp;
    }
 

    for(int i = a ; i <= b; i++){
        if((i % 15 )!= 0){
        sum += i;
        }
    }
    printf("%d\n",sum);
}