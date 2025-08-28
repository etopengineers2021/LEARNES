#include<stdio.h>
int main(){
  
    char b = 0;
    printf("Enter a number:");
    scanf("%d",&b);
  int a = 1;
    while(a != 10){
        printf("%d * %d = %d;\n",a,b,a*b);
        a++;
    }
    printf("Table is ready");
    return 0 ;
}