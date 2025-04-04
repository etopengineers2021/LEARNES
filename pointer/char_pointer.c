#include<stdio.h>
int main(){
    int i=0;
    char *ptr="help";
    printf("the ptr=%c\n",*ptr);
    for(;i<5;i++){
        printf("the ptr=%c\n",(*ptr+ i));//i
        printf("the ptr=%p\n",(ptr+ i));//addres print by bit by bit
    }
    return 0;
}
