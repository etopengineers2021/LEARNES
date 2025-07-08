#include<stdio.h>
struct student{
    char name[55];
      float gpa;
    int age;

};
int main(){
  struct student t1={"John doe",3.50};
  t1.age=20;
  printf("Student Name: %s\n",t1.name);
  printf("Age: %d\n",t1.age);
  printf("GPA: %.2f\n",t1.gpa);
  
}
