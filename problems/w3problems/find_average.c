/************************************
find postive numbers also their average.
***********************************/
#include<stdio.h>
int main(){
    int num = 0, totall= 0, postive = 0;
    printf("How many numbers:");
    scanf("%d",&num);
    int array[num]; 
    for(int i = 1; i <=num ;i++ ){
      printf("Enter number %d :",i);
      scanf("%d",&array[i]);
      if(array[i] > 0 ){
         postive++;
          totall+=array[i];
      }
    }
        printf("the total postive numbers :%d\n",postive);
       int average = totall / postive;
       printf("average:%d",average);
}