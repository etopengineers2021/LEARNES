#include<stdio.h>
#define SIZE 10

int main(){
    int array[SIZE]= {10,20,10,50,30,40,40,50,30,30};
 
 
int size=SIZE;
    for(int i = 0;i < size ;i++){
     int isDuplicatePrinted = 0;
       
     for (int k = 0; k < i; k++) {
        if (array[i] == array[k]) {
        isDuplicatePrinted = 1;
        break;
    }
}

 if (isDuplicatePrinted)
    continue;
      
        for(int x = i + 1;x < size ;x++ ){
  
   if(array[i]==array[x]){
        array[i] = array[i + 1];
    // printf("array[%d]=%d array[%d]=%d\n",i,array[i],x,array[x]);
      //break;
    }
   size--;
    x--;
   
}

}
for(int i =0 ; i < SIZE ;i++){
    printf("%d\n",array[i]);
}
}
   
