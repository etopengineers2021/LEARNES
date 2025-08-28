#include<stdio.h>
int main(){
    int a = 0,b = 0; 
    printf("Enter the numbers:\n");
    scanf("%d",&a);
    scanf("%d",&b);
     int result = ( (a == b ) ? ( (a+b)*3) :(a+b)) ;
     printf("%d",result);
     return 0;
}