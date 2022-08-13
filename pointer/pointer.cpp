#include "stdio.h"
#include "stdlib.h"

int main(){
    int arr[5] = {0};
    int *p = arr;
    printf("1.0x%x\t%d\n", p, *p);
    printf("1.0x%x\t%d\n", p++, *p);
    printf("1.0x%x\t%d\n", p, *p++);
    printf("2.0x%x\t%d\n", p, *p++ = 2);
    printf("3.0x%x\t%d\n", p, (*p)++);
    printf("4.0x%x\t%d\n", p, *++p = 2);
    printf("5.0x%x\t%d\n", p, *(++p));
    printf("6.0x%x\t%d\n", p, *p);
    for(int axis = 0; axis < 5; axis++){
        printf("%d\n", arr[axis]);
    }
}    