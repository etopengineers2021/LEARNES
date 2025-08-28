/*Write a program in C to find the sum of the series 1!/1+2!/2+3!/3+4!/4+5!/5 using the function.*/
#include<stdio.h>//pending .....
int sum = 0;
int fun(int n ){
int num = 0 ,f = 1;
 if(n >= 0){
    while( num <= n-1){
        f = f + f * num;
        num++;
    } 
   fun((n - 1) / n)  ;
    sum += f;
  //  return f, fun(n - 1) / n  ;
   return sum ;

}
}
int main(){
    int v = 5;
    //unsigned int a =fun(1)/1 +fun(2)/2+ fun(3)/3+ fun(4)/4 + fun(5)/5;
    unsigned int a = fun((v) / v);

    printf("%d",a);
}