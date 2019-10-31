#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){

	int val = 0;
	char* str = (char*)malloc(128);	
	fgets(&str,strlen(str),stdin);
	printf("%s",str);
	getchar();	
	
}
