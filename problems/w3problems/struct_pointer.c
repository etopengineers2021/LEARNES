#include<stdio.h>
struct data{
    unsigned int n ;
    long long int  roll;
    char *name;
};
void FUN_POINTER(struct data *t1);
struct data d1;
int main(){
    d1.roll = 513322107;
    puts("Before function ");
    printf("%d\n",d1.roll);
    FUN_POINTER(&d1);
    puts("after function");
    printf("%d\n",d1.roll);
}
void FUN_POINTER(struct data *t1){
    puts("Inside the function:");
    t1->roll= 1234567;
    printf("%d\n",t1->roll );
    
}