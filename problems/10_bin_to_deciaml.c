#include<stdio.h>
int main(){
    int n =0;
    int base =1, dec =0;
    printf("Enter the binary:");
    scanf("%d",&n);
    for(int i = 0 ;i<=4;i++){
        int last  = n % 10;
        n /=10;
        dec += last * base;
        base =base *2;
    }
    printf("%d",dec);
}