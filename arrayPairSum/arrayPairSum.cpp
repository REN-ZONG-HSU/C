#include <stdio.h>
#include "stdlib.h"
#include "string.h"
#include <math.h>

void swap(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

int removeElement(int* nums, int numsSize, int val){
    int last = numsSize - 1;
    int axis = 0;
    int out = numsSize;
    while(nums[last] == val){
        --last;
        --out;
    }
    while(axis < last){
        if(nums[axis] == val){
            while(nums[last] == val){
                --last;
                --out;
            }
            swap(&nums[axis], &nums[last--]);
            --out;
        }
        axis++;
    }
    return out;
}

int main(){
    int a[6] = {1, 4, 2, 3, 1, 1};
    int size = 0;
    int data = removeElement(a, 6, 1);
    printf("%d\n", data);
    return 0;
}
