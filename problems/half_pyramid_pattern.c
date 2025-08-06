#include<stdio.h> //half pyramid pattern right side.
int main(){
    int num[50];
    int count = 0;
    printf("how many line wants:");
    scanf("%d" ,&count);
    for(int i =1 ; i <= count; i++){ //nested loop
        for(int y = 0 ; y < i; y++ ){
            printf("%d",1);
        }
        printf("\n");
    }
   
    return 0;
}