#include<stdio.h> //Gold modulos
void main(){
    int  a = 28,b = a, sum = 0 , gum =0 ;
    for(int i = 1 ; i < a; i++ ){
         if(a % i == 0){
                  sum += i;
         }
    }
    for(int  i = 1 ; i < b ; i++){
            if(i % b == 0 ){
            gum += i;
         }
    }
 printf("the sum :%d\n",sum);
 printf("The gum :%d\n",gum);
}