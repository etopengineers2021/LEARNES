/**********************************************************************************************************
This  program we find the simple array reverse.
*********************************************************************************************************** */
#include<stdio.h>
#define SIZE 5
int main(){
    int arr[SIZE], i = 0 ;
    printf("Ente a inputs:");
    for(i = 0 ; i < SIZE ; i++){
        scanf("%d",&arr[i]);
    }
    for( int y = 0 ; y < SIZE ; y++ ){
    printf(" the array[%d] %d\n",y,arr[y]);
    }
    puts("array revers");
    for(int o= SIZE - 1 ; o >= 0 ; o-- ){
        printf("the revers arr[%d]%d\n", o,arr[o]);
    }
    return 0;
}