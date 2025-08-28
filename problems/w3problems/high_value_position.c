/*************************************************
FING THE HIGH VALUE POSITION .
************************************************* */
#include<stdio.h>
int main(){
     int array[5],pos = 0;
     printf("Enter the five integeres\n");
    for(int i = 1; i <=5 ; i++){
    scanf("%d",&array[i]);
}
int temp = array[0];
for(int p = 1 ; p <=5; p++ ){
    if(temp < array[p]){
        temp = array[p];
        pos = p;

    }
} 
printf("highest value: %d\n",temp );
printf("positon: %d\n",pos);
}