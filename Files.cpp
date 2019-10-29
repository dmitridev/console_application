
#include <stdio.h>
#include <string.h>
#include "Files.h"

void OpenFile(const char path[]) {


	FILE * f = fopen(path, "r");
	char buffer[80];

	while (!feof(f)){
        strcpy(buffer,"");
        fgets(buffer, 80, f);

		printf(buffer);
	}
	

}

void SaveFile(char* path,char* info) {
	FILE* f = fopen(path, "w");
	fprintf(f, "%s", info);
	fclose(f);
}