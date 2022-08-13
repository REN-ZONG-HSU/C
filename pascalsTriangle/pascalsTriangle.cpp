#include "stdio.h"
#include "stdlib.h"

int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int **mat = (int **)calloc(numRows, sizeof(int *));
    *returnColumnSizes = (int *)calloc(numRows, sizeof(int));
    for(int row = 0; row < numRows; row++){
        mat[row] = (int *)calloc(row + 1, sizeof(int));
        (*returnColumnSizes)[row] = row + 1;
        if(row == 0){
            mat[row][0] = 1;
        }
        else if(row == 1){
            mat[row][0] = 1;
            mat[row][1] = 1;
        }
        else{
            int col = 0;
            mat[row][col] = 1;
            for(col = 1; col < row; col++){
                mat[row][col] = mat[row - 1][col - 1] + mat[row - 1][col];
            }
            mat[row][col] = 1;
        }
    }
    *returnSize =  (1 + numRows) * numRows / 2;
    return mat;
}

int main(){
    int numRows = 5;
    int **colSize = (int **)calloc(1, sizeof(int *));
    int returnSize;
    int **mat = generate(numRows, &returnSize, colSize);
    for(int axis = 0; axis < numRows; axis++){
        for(int axis2 = 0; axis2 < axis + 1; axis2++){
            printf("%d\t", mat[axis][axis2]);
        }
        free(&mat[axis][0]);
        printf("\n");
    }
    return 0;
}