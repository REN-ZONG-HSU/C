#include "stdio.h"
#include "stdlib.h"

int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize){
    int *arr = (int *)calloc(matSize * (*matColSize), sizeof(int));
    int axisSum = 0;
    int rowPtr = 0;
    int colPtr = 0;
    while(rowPtr < matSize && colPtr < *matColSize){
        arr[*returnSize] = mat[rowPtr][colPtr];
        *returnSize += 1;
        if(axisSum & 1){
            if(rowPtr == axisSum || rowPtr == matSize - 1){
                axisSum++;
                if(rowPtr < *matColSize - 1){
                    rowPtr++;
                }
                colPtr = axisSum - rowPtr;
            }
            else{
                colPtr--;
                rowPtr++;
            }
        }
        else{
            if(colPtr == axisSum || colPtr == *matColSize - 1){
                axisSum++;
                if(colPtr < *matColSize - 1){
                    colPtr++;
                }
                rowPtr = axisSum - colPtr; 
            }
            else{
                colPtr++;
                rowPtr--;
            }
        }
    }
    return arr;
}

int main(){
    int mat[2][2] = {
        {1, 2},
        {4, 5},
    };
    int col = sizeof(mat[0]) / sizeof(mat[0][0]);
    int returnSize = 0;
    int *ptr[3] = {mat[0], mat[1], mat[2]};
    int *out = findDiagonalOrder(ptr, sizeof(mat) / sizeof(mat[0]), &col, &returnSize);
    for(int axis = 0; axis < returnSize; axis++){
        printf("%d\t", out[axis]);
    }
    free(out);
    return 0;
}