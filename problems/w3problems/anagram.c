/***************************************************************************************************
This program we find the length of two strings. same or not
**************************************************************************************************** */

#include<stdio.h>
#include<string.h>
int main(){
        char a[100];
        char b[100];
        printf("ENter the 1 string:");scanf("%s",a);
        printf("Enter string 2:");    scanf("%s",b);
    //  printf("%d",strlen(a));
    //  printf("%d",strlen(b));
    if(strlen(a) == strlen(b))        printf("both are same length");
    else                              printf("Both are different ");
    
    return 0 ;
    }
