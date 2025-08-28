#include<stdio.h>

struct data{
    int a;
    int b ;
    char *name;
};
 int FUN_FUNCTION( struct data t1 );
struct data d1;
int main(){
   d1.a =10 ;
    puts("Welcome back bro");
    printf("Before function: %d\n",d1.a);
   FUN_FUNCTION(d1);
   printf("after function: %d\n",d1.a);
    return 0 ;

}
 int FUN_FUNCTION(struct data t1){
    t1.a =1000;
    printf("Inside function: %d\n",t1.a);
 }