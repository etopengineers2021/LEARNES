#include<stdio.h>
int main(){
    int  n1 = 0,n2 =0;
   
    printf("Enter a starting  number:");
    scanf("%d",&n1);
   printf("Enter ending number");
   scanf("%d",&n2);

   for(int i = n1 ; i <= n2; i++ ){
    int sum = 0 ;
       for(int y = 1; y < i ; y++){
         if( i% y == 0 ){
          sum += y;
       } 
         
   }    
   if(i == sum){
      printf("perfect_number in %d between %d: %d \n",n1,n2,sum);
   }
     

   }
     
}