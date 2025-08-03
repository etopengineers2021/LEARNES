#include<stdio.h> // compound intrest.
#include<math.h>
int main(){
    float principal = 10000;
    float rate = 5;
    float year = 2;
    double rat = rate / 100; 
     float amout = principal * (pow((1 + rat),year)); //compound intrest formula
      double compound_intrest = amout - principal;
        printf("Compond intrest:%.2lf",compound_intrest);
}