#include<stdio.h>
#define M 4

int main(){
    int a_matrix[M][M]={ { 1, 3, 1, 1},
                      { 9, 2, 2, 2 },
                       { 3, 3, 3, 3},
                    { 4, 4, 4, 4} };
 
 int b_matrix[M][M];
    //this function is used nested loop.
    // transpose a_matrix to b_matrix 

                
    for(int i = 0;i < M;i++){
        for(int y=0;y< M;y++){
        b_matrix[i][y]=a_matrix[y][i];   // wow
         

        }
         printf("\n");
    }
 
}

