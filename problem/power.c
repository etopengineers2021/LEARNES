#include<stdio.h>
#include<math.h>
int power(int c,int v){
   // return pow(c,v);
   if(v==0){
       return 1;
   }
  return c *(power(c , v - 1));
    
}
int main(){
    int a =10;
    int b =2;
    int p =power(a,b);
    printf("a%d^b%d=%d",a,b,p);
}