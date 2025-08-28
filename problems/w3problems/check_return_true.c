#include<stdio.h>
int main(){
    int a = 0 , b = 0;
    const int c = 30;
    printf("Enter a inputs 1:");    scanf("%d",&a);
    printf("Enter a inputs 2:");    scanf("%d",&b);
    if((a==c||b==c) || ((a+b)==30)) printf("true\n");
    else printf("failed");
}