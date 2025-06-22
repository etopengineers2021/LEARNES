#include<stdio.h>
#include<stdlib.h>
int main(){
  
    int *ptr=malloc(sizeof(int)*10);
  //  printf("the contet of ptr%d\n",*ptr);
  //  printf("the starting addres of ptr%p\n",ptr);
  if(ptr==NULL){
    printf(" memory is not allocated");
    return 1; //with out this if condition pass but not print anything reason system in cresh.
  }
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
