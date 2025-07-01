
#include <stdio.h>
//global variable
int global_var;
void fun()
{
    int text;
   printf("the value of auto=%d\n",text);
   //  printf("its with out static%d",test);
   printf("its using static=%d\n",global_var);
    
    
}
int main()
{  
    
    //local variable
     int global_var;
     fun();
  printf("addres of mainfunction=%d\n",main);
  printf("address of global_var=%d",&global_var);
  return 0;
}
