#include<stdio.h>
int main(){
    int a = 100;
    int *ptr= &a;
    printf("%p\n",&a);
    printf("%p\n",*ptr);
    printf("%d\n",*ptr);
    int **ptrr = &ptr;
    printf("%p\n",**ptrr);
    printf("%d\n",**ptrr);

    return 0;
}