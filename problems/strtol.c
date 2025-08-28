#include<stdio.h>
#include<stdlib.h>
int main(){
    char *str= "12334harikrishnan";
    char *end;
    long num = strtol(str,&end,10);
    printf("%ls\nṇ",num);
}