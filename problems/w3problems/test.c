#include<stdio.h>
#include<string.h>
struct student {
    int num  ;
    char name[100]
};
struct student t1;
int main(){
  
   t1.num = 100;
   printf("%d\n",t1.num);
  strcpy(t1.name,"harikrishna");
  printf("%s",t1.name);
}