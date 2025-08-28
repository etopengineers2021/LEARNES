#include<stdio.h>
#include<string.h>
void FUN_CALL(int* n);
int  FUN_CALL_REFERENCE(struct *data  e1);
struct data {
    int num;
    char name[100];

}d1;
int main(){
    strcpy(d1.name,"harikrishnan");
    d1.num = 1000;
    FUN_CALL(d1.num);
    FUN_CALL_REFERENCE(&d1);
    return 0 ;
}
void FUN_CALL(int *n){
    printf("the number: %d",*n);

}
int FUN_CALL_REFERENCE(struct *data  e1){
    
    printf("reference call : %d",e1->num);

}