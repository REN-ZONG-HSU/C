#include "stdio.h"
#include "stdlib.h"

int main(){
    int a[3] = {1, 2, 3};
    int *p;
    int **pp;

    p = a;
    pp = &p;

    *p += 1;//2, 2, 3
    p += 1;
    **pp -= 1;//2, 1, 3

    *p += 1;//2, 2, 3
    *pp += 1;//

    printf("%d\n", a[0]);//2
    printf("%d\n", a[1]);//2
    printf("%d\n", a[2]);//3
    printf("%d\n", *p);//3
    printf("%d\n", **pp);//3
}  