#include<stdio.h>
typedef struct {
    int a ;
    int u ;
    char *name;
}data;
int FUN_UNIT(data e1){
    e1.name = "hari is good boy";
    printf("%s",e1.name);
}
// struct data d1;
int main(){
    data d1;
    d1. a = 10;
    printf("%d\n",d1. a);
    FUN_UNIT(d1);

}