#include <stdio.h>
#include "stdlib.h"
#include "string.h"

char * addBinary(char * a, char * b){
    int lenA = strlen(a);
    int lenB = strlen(b);
    int lenOut = (lenA > lenB)?lenA + 1:lenB + 1;
    char *out = (char *)calloc(lenOut + 1, sizeof(char));
    int carry = 0;
    int ptrA = lenA - 1;
    int ptrB = lenB - 1;
    for(int axis = lenOut - 1; axis >= 0; axis--){
        int sum;
        if(ptrA >= 0 && ptrB >= 0){
            sum = (a[ptrA--] - '0') + (b[ptrB--] - '0') + carry;
        }
        else if(ptrA >= 0 && ptrB < 0){
            sum = (a[ptrA--] - '0') + carry;
        }
        else if(ptrA < 0 && ptrB >= 0){
            sum = (b[ptrB--] - '0') + carry;
        }
        else{
            sum = carry;
        }
        carry = sum >> 1;
        sum = sum & 1;
        out[axis] = '0' + sum;
    }
    return (out[0] == '0')?&out[1]:out;
}

int main(){
    char *a = "0";
    char *b = "0";
    printf("%s\n", addBinary(a, b));
    return 0;
}

