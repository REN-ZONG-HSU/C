#include <stdio.h>
#include "stdlib.h"
#include "string.h"

char * longestCommonPrefix(char ** strs, int strsSize){
    int ptr = 0;
    bool flag = 1;
    if(strsSize == 1){
        return strs[0];
    }
     
    while(flag){
        for(int axis = 0; axis < strsSize - 1; axis++){
            if((strs[axis + 1][ptr]) == 0 || (strs[axis][ptr]) == 0 || strs[axis + 1][ptr] != strs[axis][ptr]){
                flag = 0;
                break;
            }
        }
        ptr++;
    }
    char *out = (char *)calloc(ptr, sizeof(char));
    memcpy(out, strs[0], ptr - 1);
    return out;
}

int main(){
    char *a[2] = {"",""};
    printf("%s\n", longestCommonPrefix(a, 2));
    return 0;
}
