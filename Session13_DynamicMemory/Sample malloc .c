#include<stdio.h>
#include<stdlib.h>
int main(){
  
    int *ptr=malloc(sizeof(int)*10);
  //  printf("the contet of ptr%d\n",*ptr);
  //  printf("the starting addres of ptr%p\n",ptr);
    for(int i=0 ;i <=9 ;i++){
       
       *(ptr + i)= 10 * i;
     
         
    }
    
   for(int i=0 ;i<9 ;i++){
        printf("the i value %d ,the addres %p\n",*(ptr + i) ,(ptr + i));
        
    }
    free(ptr);
    printf("after free:\n");
      for(int i=0 ;i<9 ;i++){
        printf("the i value %d ,the addres %p\n",*(ptr + i) ,(ptr + i));
        
    }

    return 0;
}