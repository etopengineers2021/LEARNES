#include<stdio.h>
int factorial(int c){
    if(c==1){
        return 1;
    }
    return (c)* factorial(c - 1);
}
int main(){
    int num =5;
    printf("%d",factorial(num));
}