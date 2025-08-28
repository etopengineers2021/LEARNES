/*******************************************************************
determine the perimeter of the triangle if the given input is valid.
********************************************************************/
#include<stdio.h>
int main(){
    int n1,n2,n3;
    for(int i =1  ; i <= 3; i++){
 
        if( i == 1){
            printf("input the fist number:");
            scanf("%d",&n1);
        //break;
        continue; 
       }
        else if(i == 2){
           printf("input the second number:");
        scanf("%d",&n2);
        continue;
        }
        else if(i==3){
           printf("input the thired number:");
        scanf("%d",&n3);
        continue;
        }
    }
 
   float  triangle = n1 + n2 + n3;
    printf("The perimeter of traingle: %.2f\n",triangle);
}
