/**********************************************************************
populate  an array where each element is triple the previous.
*********************************************************************** */
#include<stdio.h>
int main(){
   int array[7];
  
    printf("Enter the first number of array: ");
    scanf("%d",&array[0]);
    int triple = array[0];
    for(int i = 0 ; i <= 7 ; i++  ){
        printf("array[%d]=%d\n",i,array[i]);
       triple = triple * 3; 
       // triple += triple * 3; 
    
       array[i + 1] = triple;
    }
    return 0;
}