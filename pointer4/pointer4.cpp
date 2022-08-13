#include <stdio.h>
struct Node{
    char a;
    long long b;
    int c;
    char d[3];
};

int main(){
    struct Node node;
    struct Node *p = &node;
    printf("%x\n", p);
    printf("%x\n", p + 1);
    return 0;
}
