#include<stdio.h>
int main(){
    unsigned int  num =  1,con = 0 ;
   printf(" Enter a  number :");
    scanf("%d",&con);
    while( con > 0 ){

      num *= con;
      con--;
    }
     printf("%d\n",num);
}