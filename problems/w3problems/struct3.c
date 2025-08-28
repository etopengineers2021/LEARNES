#include<stdio.h>
struct book{
    int a;
    int b;
    char van[100];
};


int main(){
struct book g1;
struct book *pointer;
pointer  = &g1;
pointer -> a = 100;
pointer -> b = 2000;
strcpy(pointer -> van,"harikrishan" );
printf(" %d",pointer ->a );
printf(" %d",pointer ->b);
printf("%s\n",pointer->van);
return 0 ;
}

