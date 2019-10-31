#pragma once
char* EnterStringFromConsole(char* text,char* errorText);
int   EnterIntFromConsole(char* text,char* errorText,int range__minValue,int range__maxValue);
float EnterFloatFromConsole(char* text,char* errorText,float range__minValue,float range__maxValue);
void* recalloc(void* ptr,size_t n,size_t size);