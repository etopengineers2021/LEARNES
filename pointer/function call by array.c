#include<stdio.h>

int array(int num[]){
    int size;
    //the array value is consider as pointer
  // printf("\nthe size parameter%ld",sizeof(num)+sizeof*(num +1));
  for(int i=0; i<10;i++){
     size= size + sizeof(num[i]);
  
    printf("\nthe size parameter%ld",size);
}
 printf("\nthe size parameter is pointer %ld",sizeof(num));
 printf("\nthe size parameter is array%ld",sizeof(num[0]));
}
int main(){
    int numm;
    int arr[]={10,20,30,40,50,60};
     printf("the size arr%ld",sizeof(arr[0]));
     numm = sizeof(arr);
     array(arr);
     return 0;
    
}
