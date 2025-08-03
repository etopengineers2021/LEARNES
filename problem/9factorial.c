#include<stdio.h>
int main(){
    int num = 5, n = 0;
    for(int  i= 0; i<=5 ;i++){
        int a=num * (num - 1);   
         
        n += a;
        
    }
    printf("factorial %d is %d",num,n);
}