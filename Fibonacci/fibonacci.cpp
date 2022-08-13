#include "stdio.h"
#include "stdlib.h"

int fibonacci(int n){
    int f0 = 1, f1 = 1;
    if(n == 0 || n == 1){
        return 1;
    }
    else{
        int ans;
        for(int axis = 1; axis < n; ++axis){
            ans = f0 + f1;
            f0 = f1;
            f1 = ans;
        }
        return ans;
    }
}

int main(){
    printf("%d\n", fibonacci(3));
    return 0;
}