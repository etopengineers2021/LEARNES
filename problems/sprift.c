#include<string.h>
#include<stdio.h>
int main(){
//    char *num[40];
      char num= 100;
    //sprintf(chat)
  /*  const int num =100; // only read ,not over write.
    printf("const :%d",num);
   num =200;
   printf(" over write :%d",num);
    */
    char* hex;
    sprintf(hex,"%x",num);    // main (destation ,formate specifier ,source);
    printf("hexadesimal :%s",hex);
}