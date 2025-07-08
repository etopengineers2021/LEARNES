#include<stdio.h>
#define MAX 4
struct employee {
    char name[100];
    int salary;
};
    struct employee t1[MAX];
int main(){
    int i=0;
 
    for(; i<MAX; i++){
        scanf("%s",t1[i].name);
        scanf("%d",&t1[i].salary);
    }
    i=0;
for(int y=0 ;y<MAX; y++){
      i++;
    printf("Employee %d: Name = %s, Salary= %d\n",i,t1[y].name,t1[y].salary);
  
}
    
}
