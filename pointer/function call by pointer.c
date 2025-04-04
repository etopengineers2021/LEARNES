#include<stdio.h>

void pass_ptr_fun(int a,int b){
int c=a+b;
    printf("the pointer can passed%d",c);
}

int main(){
    

  int var1=10;
  int var2=20;
   void (*pointer)()=&pass_ptr_fun;
    //pass_ptr_fun();
   (*pointer)(var1,var2);
    return 0;
}
