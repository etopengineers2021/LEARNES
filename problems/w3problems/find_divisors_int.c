/*********************************************************
find the given number is divisble by  given integer.
******************************************************** */
#include<stdio.h>
int main(){
    int n1 = 0, i= 1;
    printf("Enter the input:");
    scanf("%d", &n1);
     for(; i <= n1 ; i++){
        if((n1 % i) == 0){
            printf("%d\n\n",i);

        }
     }
}