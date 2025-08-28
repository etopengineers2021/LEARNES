#include<stdio.h>
#include<string.h>
#define M 5 //try to 4
int main(){

    char s[M]="hari";
    char e[M];
  int j=strlen(s) - 1;
  printf("%d\n",j);
    for(int i = 0;s[i]!='\0';i++){
     int temp= s[i];
     e[j]= temp;
     j--;
    //e[i]= s[M - i];
 printf("%c",s[i]);
 }
 printf("\n");
for(int i =0 ;i<M;i++) printf("%c",e[i]);

    return 0;
}