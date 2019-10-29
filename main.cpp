// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "CinemaRecord.h"
#include "Database.h"
#include "Files.h"
#include "Utils.h"
#include "Menu.h"
#include <string.h>

void RusMenu();
void EnMenu();
void Exit();


CinemaRecord* records_table;
CinemaRecord * new_record;
char* current_menu_textfile;
int length;
bool RussianOrEnglish = true; //true если русский язык, false если английский



char* ChangeTextFileToCurrentLanguage(char * textFile){
        size_t i = 0;
        char * retValue = (char*)malloc(sizeof(char)* strlen(textFile));
        for(i = strlen(textFile);i>0;i++){
            if(textFile[i] == '_'){
                break; // нашли точку смены текстового имени
                //теперь зная где менять файл что делать дальше?
            }
        }
        char * tmp= (char*)malloc(sizeof(char)*i);
        strncpy(tmp,textFile,i);

        sprintf(retValue,"%s%s",tmp,retValue);

    return retValue;
}

void ChangeLang(){
    RussianOrEnglish = !RussianOrEnglish;
    ChangeTextFileToCurrentLanguage(current_menu_textfile);
}

void OnMainMenu(){
    if(RussianOrEnglish){
        RusMenu();
    }else EnMenu();

}
void Menu_ShowTable(){
    fflush(stdin);

    ShowTable(records_table,length);

    getchar();
    OnMainMenu();
}


void Menu_AddNewRecord(){
    CinemaRecord * new_record = (CinemaRecord*)malloc(sizeof(CinemaRecord));
    EditRecord(new_record);
    AddNewRecord(records_table,length,new_record);
}




void Menu_EditTable(){
    current_menu_textfile = (char*)malloc(sizeof(char)*21);
    strcpy(current_menu_textfile,RussianOrEnglish ? "/Users/admin/Desktop/программирование/c++/Console_application/Edit_Menu_Russian.txt":"Edit_Menu_English.txt");


    DrawMenu(current_menu_textfile,
             5, // 5 пунктов меню
             Menu_AddNewRecord,
             EditRecord,
             DeleteRecord,
             ChangeLang,
             OnMainMenu);
}


int main()
{

    setlocale(LC_ALL, "");

    records_table = ReadDatabaseFile("/Users/admin/Desktop/программирование/c++/Console_application/Database.txt",length);
    getchar();
    DrawMenu("/Users/admin/Desktop/программирование/c++/Console_application/Menu_Main.txt",
                  3, // 3 пункта меню
                  RusMenu, // 1 - выбрать русский язык
                  EnMenu,  // 2 - выбрать английский язык
                  Exit);   // 3 - выход

    return 0;
}








void RusMenu(){

    current_menu_textfile = (char*)malloc(sizeof(char)*100);
    strcpy(current_menu_textfile,"/Users/admin/Desktop/программирование/c++/Console_application/Menu_Russian.txt");

    DrawMenu(current_menu_textfile,
             9,
             Menu_ShowTable, // 1 - показать таблицу
             Menu_EditTable,      // 2 - редактировать таблицу
             NULL,      // 3 - сортировать по
             NULL,      // 4 - поиск по записям
             NULL,      // 5 - Поиск по минимальным и максимальным значениям
             NULL,      // 6 - Сохранить таблицу в новый файл
             NULL,      // 7 - помощь
             EnMenu,    // 8 - переключиться на английский язык
             Exit);     // 9 - выход
}

void EnMenu(){
    current_menu_textfile = (char*)malloc(sizeof(char)*100);
    strcpy(current_menu_textfile,"/Users/admin/Desktop/программирование/c++/Console_application/Menu_English.txt");
    DrawMenu(current_menu_textfile,
             9,
             Menu_ShowTable,      // 1 - Show table
             Menu_EditTable,      // 2 - Edit table
             NULL,                // 3 - Sort by...
             NULL,                // 4 - Search in records
             NULL,                // 5 - Search min and max values
             NULL,                // 6 - Save table to new file
             NULL,                // 7 - Help
             RusMenu,             // 8 - Переключиться на русский язык
             Exit);               // 9 - выход
}


void Exit() {
    exit(0);
}
