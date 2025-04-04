#include<stdio.h>
int main(){
    int var=10; //integer variable var
    int* ptr=&var; //intilize to pointer
    printf("the var%d\n",var);
    printf("the addres of var%p\n",&var);
    printf("the  intilie address of ptr%p\n ",ptr);
#if 0
int* ptr1=&ptr;
//that pointer1 is intilize to another pointer2 but unfortunately wrong.
    printf("The ptr1 addres%d",*ptr1);


#endif
     int** ptr1=&ptr; //that pointer1 is intilize to another pointer2
    printf("The ptr1 addres%d",**ptr1);
    return 0;
}
