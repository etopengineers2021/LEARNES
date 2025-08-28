/******************************************************************************
fird max^ min using function.
********************************************************************************* */

#include<stdio.h>
# define SIZE 5

int fun(int arrayy[],int size);
int main(){
    int array[SIZE];
    printf("Enter a  %d numbers: ",SIZE);
   for(int i = 0; i < SIZE ; i++){
    scanf("%d",&array[i]);
   }
   fun(array,SIZE);
}
int fun(int arrayy[],int size){
    // printf("The array[0] =%d", arrayy[0]);
    int  temp = arrayy[0];
    int crash =arrayy[0];
    for(int i = 1 ; i <size ;i++ ){
     if(temp < arrayy[i]){
        temp = arrayy[i];
     }
     if(crash > arrayy[i]){
         crash = arrayy[i];
      }

    }
    printf("MAX %d\n",temp);
    printf("MIN %d\n",crash);
}