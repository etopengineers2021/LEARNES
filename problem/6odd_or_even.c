#include<stdio.h>
int main(){
    while(1){

    
    int num = 0;
    printf("Enter a number :");
    scanf("%d",&num);
    if( num >= 0&&num%2 == 0){
        printf("Even\n");
    }
     else if(num %2 != 0 )
       printf("odd\n");
     else 
     printf("invalid input\n");
        }    return 0;
}