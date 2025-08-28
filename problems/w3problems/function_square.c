/*************************************************************************
Find tha square using finction call by value and call by reference .
************************************************************************* */


#include<stdio.h>
float  fun_square(float a);
float fun_squaree(float *b);
int main(){
    float num =0 ;
    printf("Enter a number :");
    scanf("%f",&num);
   fun_square(num);
  // fun_squaree(&num);//call by reference

    return 0 ;
}

float fun_square(float a){
     printf("The square of %f is :%.2f",a,a*a);
     return 0 ;
}
float fun_squaree(float *b){
    printf("The square of %f is %.2f",*b, *b * *b);
    return 0;
}