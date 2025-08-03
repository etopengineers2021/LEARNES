#include<stdio.h> //call  by reference
void fun(int* ,int*);
 int main(){
    int a = 10 , b = 20;
    fun(&a, &b);
    return 0;
 }
 void fun(int *p ,int *c){
    printf("Sum of A and B is: %d",*p + *c);

 }