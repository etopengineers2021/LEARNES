#include<stdio.h>
int fun(int x){
   
    if(x==0){
      return 0;
    }
    int temp = x % 10; 
  if(temp % 2== 0){
       

     
     return    temp + fun( x / 10);
    }
    else 
    return fun(x/10);
}

  

int main(){
    int n =123456;
    int temp=0; int result= 0;
    // for(int i = 0; i <=6; i++ ){
        
    //     temp = n % 10;
    //     n = n / 10;
    //     if(temp%2==0){
    //        result +=temp;
    //     } 
    // }
    result =fun(n);
    printf(" result:%d\n",result);
    return 0;
}