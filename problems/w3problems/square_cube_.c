/*****************************************************************************
find  n number for square and cube.
**************************************************************************** */

#include<stdio.h>
int main(){
    int n = 0 ;
    printf("Enter the inputs :");
    scanf("%d",&n);
    for(int i = 1; i <=n  ; i++){
        for(int y = 0 ; y < 1; y++){
            printf("%d ",i);
            printf("%d ",i*i);
            printf("%d ",i*i*i);


        }
        printf("\n");
    }
}