#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int main(){
  
  //  int *ptr=malloc(sizeof(int)*MAX);  //heap
      int *ptr=calloc(MAX,sizeof(int));
    if(ptr== NULL){
        printf("memory is not created\n");
        return -1;
    }
    printf("the ptr addres%p and content %d\n ",ptr,*ptr);
//    ptr=10;  error-  ptr go to point address 10 its invalid .

   // *ptr =10; //ptr go to put 10 in that dereference address
   // printf("the ptr addres%p and content %d\n ",ptr,*ptr);
    
    for(int i=0;i<MAX;i++){ 
        *(ptr +i )= 10* i;//initializing value or content.
    }
    for(int i=0;i<MAX; i++){
        printf("the i %d addres %p content%d\n",i,(ptr + i),*(ptr +i));
    }
    free(ptr);
    for(int i=0;i<MAX; i++){
        printf("the i %d addres %p content%d\n",i,(ptr + i),*(ptr +i));
    }
    ptr=realloc(ptr,10*sizeof(int));
    for(int i=0;i<MAX;i++){ 
        *(ptr +i )= 10* i;//initializing value or content.
    }
    for(int i=0;i<MAX; i++){
        printf("the i %d addres %p content%d\n",i,(ptr + i),*(ptr +i));
    }
    return 0;
}
