
#include "Files.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "Menu.h"

void DrawMenu(const char filename[], int menuItemsCount, ...)
{
    system("clear");
	int num = 0;
	OpenFile(filename);

	scanf("%d", &num);

	va_list pointer_to_arguments;
    va_start(pointer_to_arguments, menuItemsCount);
	
	for (int i = 0; i < menuItemsCount; i++) {
		void *f = va_arg(pointer_to_arguments, void*);//ооооооо
		if (num != 0 && num - 1 == i ){
            ((void(*)())f)();//аааа сложнаааа
			break;
	}
	}
	num = 0;
}
