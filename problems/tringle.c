#include<stdio.h>
int main(){
    int count = 0; int let=65;
    printf("Enter the inputs");
    scanf("%d",&count);
    for(int i = 0 ; i < count;i++){
        for( int y = 0; y <=2*(count - i - 1);y++ )printf(" ");
        for(int p = 0; p <=i ; p++){
             printf(" %c ",let);
             let++; 
        }
        printf("\n");
    } 
}