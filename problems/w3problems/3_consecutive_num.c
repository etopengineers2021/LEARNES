/********************************************************************************
தொடர்ச்சியாக print a number by consecutive of  N line.
**********************************************************************************/

#include<stdio.h>
int main(){
    int n= 0, i = 0, y = 1;
    printf("Enter the inputs :");
    scanf("%d",&n);
    for(; i < n ; i++){
        for(int t = 0 ; t < 3 ; t++ ){
            printf("%d ",y);
            y++;
        }
        printf("\n");
    }
    return 0;
}