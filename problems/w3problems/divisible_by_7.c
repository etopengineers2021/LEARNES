/***************************************************************
divide a two inputs between them add when its divisible reminder  2 or 3.
************************************************************* */

#include<stdio.h>
int main(){
int n1= 0 ,n2 = 0;
printf("Input the first integer:");
scanf("%d",&n1);
printf("Input the second integer:");
scanf("%d",&n2);
if(n1 > n2){
    int temp = n1;
    n1  = n2;
    n2 = temp ;
}
for(int i = n1 ;i  <= n2 ; i++ ){
  if(i % 7 == 2 ||  i % 7 == 3 ){
printf("%d\n",i);
  }
}

}