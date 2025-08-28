//function call by struct in Reference
#include<stdio.h>
struct data {
    int a ;
    char name;

};
int FUN_Call(struct data *o){
    printf("INside function %d\n",o->a);
    o-> a = 1000;
}
struct data d1;
int main(){
    d1.a= 100;
    printf("before funcall %d\n",d1.a);
    FUN_Call(&d1);
    printf("AFTER function %d",d1.a);
}