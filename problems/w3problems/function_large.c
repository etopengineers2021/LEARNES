/*******************************************************************************
find the maximum by using function.
********************************************************************************** */

#include<stdio.h>
int fun(int b[],int sizee);
int main(){
    int size = 5 ; 
    int a[size];
    printf("Enter the number of elements to be store in array :\n");
    //scanf("%d",&size);
    printf("inputs %d elements in array :\n",size);
    for(int i =0; i < size; i++ ){
        printf("element- %d- ",i);
        scanf("%d",&a[i]); 
    }
     fun(a,size);
    return 0 ;
}
 int fun(int b[],int sizee){ // array can
    int temp = b[0];
    
    for(int i = 1; i <= sizee ; i++){
        if (temp <= b[i]){
            temp = b[i];
        }
    }
    printf(" the maximumvalue :%d",temp);
    return 0;
}
