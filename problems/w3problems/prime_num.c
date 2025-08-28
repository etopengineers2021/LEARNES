#include<stdio.h>
int main(){
    int n = 0, isprime = 1;
    printf("Enter a number");
    scanf("%d",&n);
    if(n <= 0){ //check is nagtive numbers.
        isprime = 0;
    }
    else {
        for(int i = 2 ;i <= n / 2; i++){ // n is divided by 2 .ex 20 /2 .2,4,5,10. 
    //for(int i = 2  ; i < n ; i++ ) { // slow ,  because itd search all numbers.
            if( n % i ==0){
                isprime = 0; 
                  break;
            }
        }
    }
    if(isprime)
    printf("number is prime");
   else 
   printf("not prime number");
}