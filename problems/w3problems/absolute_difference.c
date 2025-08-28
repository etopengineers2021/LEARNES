/****************************************************************************
check if given N to 51 difference. if N is greaterthen 51 ,triple the difference value.
***************************************************************************** */
#include<stdio.h>
int main(){
    char a = 0;
     char b = 51;
    int sum = 0,i = 0, amm = 0;
    printf("Enter the number:");
    scanf("%d",&a);
    if(b > a){
        for( i = 0; a <= b; i++ ){
            sum = i;
            a++;
        }
         
    printf("difference: %d",sum);
    }
    else if( a > b ){
        for(i = 0 ; a >= b;i++){
          amm = i;
          b++;
        }
         
    printf("difference: %d\n",amm);
    printf("triple %d",amm * 3);
    }
   
}