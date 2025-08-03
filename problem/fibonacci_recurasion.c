#include<stdio.h>
int sum(int c);
int main(){
    int result = sum(10);
    printf("%d",result);
}
int sum(int c){
    if(c >0){
        return c += sum(c -1);
    }
    else
    {
        return 0;
    }
}