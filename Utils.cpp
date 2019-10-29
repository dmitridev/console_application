#include <stdio.h>
#include <stdlib.h>
#include "Utils.h"


char* EnterStringFromConsole()
{
	char* res = (char*)malloc(sizeof(char) * 100);
	while (1)
		if (scanf("%s", res) != -2)
			return res;
		else printf("Error! try again!");

}

int EnterIntFromConsole()
{
	int num = 0;
	while (1)
		if (scanf("%d", &num) != -2)
			return num;
		else
			printf("Error! try again!\n");
}

float EnterFloatFromConsole()
{
	float num = 0;
	while (1)
		if (scanf("%f", &num) != -2)
			return num;
		else
			printf("Error! try again!\n");
}

