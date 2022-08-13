#include <stdio.h>

int binarySerach(int *ptr, int size, int val){
    int left = 0;
    int right = size - 1;
    while(right >= left){
        int mid = (left + right) / 2;
        if(ptr[mid] > val){
            right = mid - 1;
        }
        else if(ptr[mid] < val){
            left = mid + 1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

int main(){
    int arr[7] = {1, 3, 5, 7, 9, 11, 13};
    printf("%d\n", binarySerach(arr, 7, 11));
    return 0;
}
