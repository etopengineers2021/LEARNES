/****************************************************************************************************
This program we find the frequence of array elements.
****************************************************************************************************** */
//frequence counting.
#include<stdio.h>
int main(){
    int arry[50] ={1,2,3,4,1,6,7,2,2,5,6,7,8,9,0,4,5,8,9};
    int aro[10]={0};
    int i = 0;
    //int aro[50];
    for( ; i <= 10 ; i++){
       aro[arry[i]]++; //MASTER
    } 
    for(i = 0 ; i< 10 ;i++){  
    printf(" value %d = %d\n",i,aro[i]);
    }
    return 0;
}