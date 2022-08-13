#include "stdio.h"
#include "stdlib.h"

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    *returnSize = *matrixColSize * matrixSize;
    int *arr = (int *)calloc(*returnSize, sizeof(int));
    int row = 0, col = 0, startRow = 0, startCol = *matrixColSize - 1, endRow = matrixSize - 1, endCol = 0;
    for(int axis = 0; axis < *returnSize; axis++){
        arr[axis] = matrix[row][col];
        if(row == startRow && col != startCol){
            ++col;
            if(col == startCol){
                if(++startRow == endRow){
                    --startRow;
                }
            }
        }
        else if(col == startCol && row != endRow){
            ++row;
            if(row == endRow){
                if(--startCol == endCol){
                    ++startCol;
                } 
            }
        }
        else if(row == endRow && col != endCol){
            --col;
            if(col == endCol){
                if(--endRow == startRow){
                    ++endRow;
                }
            }
        }
        else if(col == endCol && row != startRow){
            --row;
            if(row == startRow){
                if(++endCol == startCol){
                    --endCol;
                }
            }
        }
    }
    return arr;
}

int main(){
    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    int col = sizeof(mat[0]) / sizeof(mat[0][0]);
    int returnSize = 0;
    int *ptr[3] = {mat[0], mat[1], mat[2]};
    int *out = spiralOrder(ptr, sizeof(mat) / sizeof(mat[0]), &col, &returnSize);
    for(int axis = 0; axis < returnSize; axis++){
        printf("%d\t", out[axis]);
    }
    free(out);
    return 0;
}