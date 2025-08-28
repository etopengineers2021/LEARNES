/*Fing duplicate*/

#include<stdio.h>
int main(){
    int num[100];
    puts("Input numbers(stop if you input a duplicate):");
    for(int i = 0 ; i < 100; i++  ){
   printf("Input a number :");
   scanf("%d",&num[i]);
   for(int y = 0 ; y < i ; y++ ){
    int arr= num[y];
    if(arr == num[i]){
        printf("Duplicate number entered. program will stop");
        return 0 ;   
      }
     }
     
    }
}