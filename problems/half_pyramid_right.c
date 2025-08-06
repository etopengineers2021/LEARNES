#include<stdio.h>
int main(){
    int count = 0 ;
    printf("enter the count:");
    scanf(" %d",&count);
      for(int i = 0; i <=count; i++ ){ //outer loop , loop play main role.
    
        for(int r = 0; r <= 2*(count - i -1); r++)printf(" ");
        //for(int c = 0 ; c <=i ; c++ )printf(" * ");
        for(int c = 0; c<=i ;c++)printf("  %d ",i); 
        printf("\n");
        
    }
    return 0;
}