#include<stdio.h>
int factorial(int c){
    if(c==1){  // base condition used for terminate recursion.
        return 1;
    }
    return (c)* factorial(c - 1);  //recursion call
}
int main(){
    int num =5;
    printf("%d",factorial(num));

}
