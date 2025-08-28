/************************************************************************************************
//In this program we N its multiples of same number by digitd by digit.
************************************************************************************************ */
#include<stdio.h> 
int main(){    // 153,1634
while(1){    
    int n = 0, temp= 0, tri = 0 ;
    printf("Enter a number :");  scanf("%d",&n);
    int temp1 = n ;
while(n > 0) {
    temp = n % 10 ;                //gets last digit 
      tri += temp * temp *temp ; 
       n = n / 10;                  //remove last digit
    }
if(tri == temp1) printf("Arastrong : %d\n",tri);
   }
}