#include<stdio.h>
#include<string.h>
struct student {
    int num ;
    char name[100];
    char *ptr_name;
};
struct student t1;
int main(){
  
   t1.num = 100;
   printf("%d\n",t1.num);
  strcpy(t1.name,"harikrishna\n");
  printf("%s",t1.name);
  t1. ptr_name = "Everday coder";
  printf("pointer string : %s",t1.ptr_name); 
}