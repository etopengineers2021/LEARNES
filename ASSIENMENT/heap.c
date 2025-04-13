#include<stdio.h>
#include<stdlib.h>
#define num 5
int main(){
    //int ptr;
    int var=10;
    int* ptr=malloc(sizeof(int) *  num);
    if(ptr==NULL){
        printf("the ptr memory null");
        return -1;
    }
    printf("memory allocate succfully\n");
    
 
    
    printf("after initilze\n ");
   for(int y = 0; y < num; y++) {
        *(ptr + y) = 10 * (y + 1);  // Store value in array using pointer
        printf("the content at y = %d is %d\n", y, *(ptr + y)); // Corrected to show value at current index
    }
    printf("the content at y* = %d \n", *ptr);
       for(int y = 0;y < num; y++){
      
        printf("the content is y %d\n ",*(ptr + y));
}
    
    free(ptr);
    
    for(int i=0;i<num;i++){
      printf("after free\n");
        printf("the pointer content%d\n",*(ptr +i));
   
    }
    
    
}