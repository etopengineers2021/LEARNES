#include<string.h>
#include<stdio.h>
struct student{
   char roll ;
    char name[100];

};
struct student d1;
int main(){
 d1.roll= 21;
 strcpy(d1.name,"harikrsihn\n");
 printf("%s",d1.name);
 printf("The ROll number:%d",d1.roll);
}