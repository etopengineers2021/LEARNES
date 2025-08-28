/*********************************************************************************
swap a number with  out temp.
************************************************************************************/


#include<stdio.h>
int swap(int x,int y);
  int a ,b;
int main(){
  
  printf("input 1st numbers ");
  scanf("%d",&a);
  printf("input 2st  number");
  scanf("%d",&b);
  swap(a,b);
}
int swap(int x,int y){
      x = x ^ y;  
      y = y ^ x;
      x = x ^ y;
      printf("X = %d, Y = %d\n",x,y);
      return x,y;
}