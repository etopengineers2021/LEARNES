#include<stdio.h>
int main(){
    const int x = 51;
    int a = 0 ;
    int t = 0 ;
    printf("Enter a  number:");
    scanf("%d",&a);
    for( ; a < x ; t++){
  
 a++;    
}
  printf("The difference is %d\n",t);
    return 0;
}