#include<stdio.h>
int main(){
    int a = 0 ;
    printf("Enter a number :");
    scanf("%d",&a);
    if(a % 400 ==0)
        printf("it a leep year:");
else if(a % 100 == 0)
printf("its not leep year");
        else if( a % 4 == 0)
            printf("Leap year");
    

    else 
    {
        printf("Not a Leap year:");

     }  return 0;
}