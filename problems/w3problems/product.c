#include<stdio.h>
int main(){
    int n1 = 1 , n2 = 1;
    int pro = 1;
    printf("product of number\n Enter number 1: ");
    scanf("%d",&n1);
    printf("Enter number 2:");
    scanf("%d",&n2);
  while ( n1 <=n2){
    pro *= n1;
    printf("current numbr: %d,current product ;%d\n",n1,pro);  
  n1++;
}
return 0;
}