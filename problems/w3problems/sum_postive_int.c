/**
this program collect data user and sum the data ,print until input is 0.
*/
#include<stdio.h>
int main(){
    int sum = 0 ;
    int num= 1;
    while( num > 0){
        printf("enter a number:");
        scanf("%d",&num);
    if(num == 0 ){
        break;
    }
    if(num > 0 ){
        sum += num;

    }

    }
    printf("%d",sum);
    return 0 ;
}