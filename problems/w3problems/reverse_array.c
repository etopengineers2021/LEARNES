#include<stdio.h>
int main(){
    int array[5];
    int i = 0;
    printf("Enter the 5 members of the array:");
    for( i = 0 ; i < 5; i++ ){
        scanf("%d",&array[i]);
    }
      i = 0;
    for(int y = 4; y > i; y--){
      
        int temp = array[i];
        array[i]= array[ y ];
        array[ y ] = temp;

      //  printf("array[%d]=%d\n",i,array[i]);
        i++;
    }
    printf("final array :");
    for(i = 0 ; i< 5 ; i++){
        printf("%d\n", array[i]);
    }
    return 0;
}