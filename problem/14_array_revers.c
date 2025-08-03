#include<stdio.h>
#define SIZE 6
void fun(int arry[],int start, int end){
    if(start >= end){
        return ;
    }
     int  temp =arry[start];
     arry[start]= arry[end];
     arry[end]=temp;
                 
    
     return fun(arry, start+1, end-1);
      
   
}
int main(){
    int array[SIZE]={0,10,20,30,40,50};
//     int i=0,y=0;
//     printf("BEFORE REVERSE:\n");
//     for(;i<SIZE;i++){
//         printf("array[%d]= %d\n",i,array[i]);
// }
//   printf("AFTER REVERSE\n");
//     for(y=SIZE-1;y >= 0;y--){
//          printf("array[%d]= %d\n",y,array[y]);
//     }
    fun(array,0,SIZE - 1);
     printf("AFTER REVERSE\n");
     int y =0;
     for(y=SIZE-1;y >= 0;y--){
          printf("array[%d]= %d\n",y,array[y]);
  }
  puts("Exection is done");
    return 0;
}