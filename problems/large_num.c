#include<stdio.h>
#define MAX 6
int main(){
    int n1[20];
    for(int i = 0; i < MAX ;i++){
    printf("Enter a Number %d:",i);
    scanf("%d",&n1[i]);
    }
    int max =0;
    int temp = n1[0];
    int min =temp;
    for(int y = 1 ; y < MAX;y++){
        if(n1[y] > temp){
        max = n1[y];
    }
     if(n1[y] < min){
         min =  n1[y];
     }
}
    printf("Largest number is: %d\n",max);
    printf("minimu in list%d\n",min);
    return 0;

}