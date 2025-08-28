//call by value for struct
#include<stdio.h>
#include<string.h>
struct data{
    int n;
    int a;
    char name[200];
};
int FUN_string(struct data o){
printf("%d",o.n);
}
struct data d1;
int main(){
    d1.n =100;
   strcpy(d1.name,"harikrishnan");
   printf("%d %s",d1.n,d1.name);
   FUN_string(d1);
}
