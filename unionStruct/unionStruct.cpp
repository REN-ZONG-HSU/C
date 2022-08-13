#include <stdio.h>
struct Node{
    char a;
    long long b;
    int c;
    char d[3];
};

struct Node2{
    int a;
    struct Node2 *next;
};

union T{
    char a;
    struct Node b;
};

int main(){
    struct Node node;
    struct Node2 node2;
    union T t;
    printf("%d\n", sizeof(t));
    printf("%d\n", sizeof(node2));
    return 0;
}
