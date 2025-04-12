#include<stdio.h>
int fun(int arr[])
{
    for(int i=0;i<4;i++){
        printf("the array to pointr%lx\n",arr[i]);
    }
}
int main(){
    int tree[]={10,20,30,40};
    int* ptr=tree;
    printf("the addres of ptr%p\n",ptr);
    printf("the addres of arrray%p\n",tree);
    fun(ptr);
}
