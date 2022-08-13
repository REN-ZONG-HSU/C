#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void GetMemory(char **p) {
	*p=(char *)malloc(100);
}


int main(){
	char *str=NULL;
	printf("%x\n", str);
	GetMemory(&str);
	printf("%x\n", str);
	//strcpy(str,"hello world");
}  