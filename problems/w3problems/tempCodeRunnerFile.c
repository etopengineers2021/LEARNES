#include<stdio.h>
#include<string.h>
int main(){
    char name[50];
    char arry[40] ={0};
    printf("Enter your name :");
    scanf("%s",&name);
    int len = strlen(name);
    printf("%d",len);
    for(int o = 0 ; o < 40; o++ ){
        arry[name[o]]++;
    }
    for(int c = 0; c < 50; c++  ){
        printf("varied %d -%d\n",c,arry[c]);
    }


}