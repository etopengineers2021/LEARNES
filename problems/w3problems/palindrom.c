#include<stdio.h>
int main(){
    int num = 0 ;
    printf("Enter a in put:");
    scanf("%d",&num);
    int temp = num ;
    int revers=  0;
    while (num != 0){
        int reminder = num %10;
        revers = revers * 10 + reminder;
        num /= 10;
    } 
    if(temp == revers){
        printf("%d is palindrome :",temp);
    }
    else {
        printf("Is not a palindrome :%d",temp);
    }
    return 0;
}