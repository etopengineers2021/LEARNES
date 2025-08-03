#include<stdio.h>
int main(){
    int a , b ;
    printf("Enter the num a:");
    scanf("%d",&a);
    printf("Enter the num b:");
    scanf("%d",&b);
    int temp = a ;
    a = b;
    b =temp;

    printf("Output: After Swapping: x = %d,y = %d",a,b);
}