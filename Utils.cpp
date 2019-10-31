#include <stdio.h>
#include <stdlib.h>
#include <malloc/malloc.h>
#include <string.h>
#include "Utils.h"


char* EnterStringFromConsole(char*text,char* errorText)
{
	char* res = (char*)malloc(128);
    size_t len = 0;
	while (1) {
        printf("%s",text);
        scanf("%[^\n]",res);
            if(res !=NULL){
				return res;
			}

        else {
            printf("%s", errorText);
        }
    }
}

int EnterIntFromConsole(char* text,char* errorText,int range__minValue ,int range__maxValue) {
	int num = 0;
	while (1){
	    printf("%s",text);
        if (scanf("%d*c", &num) != -2 && num >= range__minValue  && num <= range__maxValue){

			return num;
        }
		else{
			printf("%s",errorText);
        }
    }

}

float EnterFloatFromConsole(char* text,char*errorText,float range__minValue,float range__maxValue) {
	float num = 0;
	while (1){
        printf("%s",text);
		if (scanf("%f*c", &num) != -2 && num>= range__minValue && num <= range__maxValue){
			return num;
        }
		else
			printf("%s",errorText);
}

}

//это не нужно трогать вообще она не нужна
 void* recalloc( void * ptr,size_t n,size_t size){
		size_t actual_size = malloc_size(ptr); // заменить на _msize в windows

		if(actual_size >= n){
			return ptr;
		}

		void * ret_value = calloc(n,sizeof(typeof(ptr)));
		memcpy(ret_value,ptr,actual_size);

		free(ptr);
		return ret_value;
}
