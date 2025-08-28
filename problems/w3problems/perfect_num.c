/****************************************************************************
find a perfect numbers.
**************************************************************************** */

#include<stdio.h>
int main(){
 while(1){ 
    int num =0 ,add = 0;
 
printf("Enter a numbers:");
scanf("%d",&num);
    for(int i = 1 ; i < num; i++){
        if( num % i == 0){ // alway the divide number os always left -diviser is right.other is make error
              add += i;
        }
     }
   printf("%d\n",add);
    }
}