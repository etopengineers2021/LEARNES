#include<stdio.h>
#include<stdlib.h>
union test{
    unsigned int sum ;
    char name[100]; // 0 - 4,294,967,295

};

union test t1;
 union test *t2 ;
 union test *t3;
// union test *t2=&t1;
int main(){
    puts("NEVER GIVE UP BRO ");
    printf("you will won soon\n");
    printf("%zu\n",sizeof(union test));
        t1.sum = 100;
t2 = &t1;
t2->sum=1000;
    //printf("sum: %d",t1.sum);
printf("union: %d\n",t2 -> sum);
t3=malloc(sizeof(union test));
printf("%zu\n",sizeof(t3));
t3->sum =5000;
printf("after malloc pointer%d",t3->sum);
}