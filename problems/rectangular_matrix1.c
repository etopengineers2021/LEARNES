#include<stdio.h> // we need make ractangular matrix M*N 2*3 
#define M 3
#define N 3
int main(){
    int a_matrix[M][N]={ { 1, 2, 3},
                          {9, 2, 3},
                            {1, 2, 3}};
    int b_matrix[M][N];                        
   for(int i = 0; i < M;i++){
    for(int y = 0; y < M; y++){
        b_matrix[i][y]=a_matrix[y][i]; //00 00 //01  10
        printf("%d",b_matrix[i][y]);
    }

    printf("\n");
   }
}