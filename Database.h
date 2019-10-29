#pragma once
#include "CinemaRecord.h"





//работа и преобразование строки в структуру CinemaRecord
void StringToCinemaRecord(CinemaRecord* record, char* str);
//Прочитать файл базы данных

CinemaRecord* ReadDatabaseFile(char * filename,int &length);
//показать таблицу
void ShowTable(CinemaRecord * records,int length);

/* пункт 2 редактировать запись*/
void AddNewRecord(CinemaRecord * records_table,int length, CinemaRecord* new_record);
void EditRecord(CinemaRecord* record);
void DeleteRecord(CinemaRecord* records_table,int length,int record_number);

/*пункт 3 сортировать по*/

void SortByName(CinemaRecord* records_table,int length,bool MinMax = true);
void SortByYear(CinemaRecord* records_table,int length,bool MinMax = true);
void SortByCountry(CinemaRecord* records_table,int length,bool MinMax = true);
void SortByDirector(CinemaRecord* records_table,int length,bool MinMax = true);
void SortByScriptWriter(CinemaRecord* records_table,int length,bool MinMax = true);
void SortByProducer(CinemaRecord* records_table,int length,bool MinMax = true);
void SortByBudget(CinemaRecord* records_table,int length,bool MinMax = true);
void SortByDuration(CinemaRecord* records_table,int length,bool MinMax = true);
void SortByGenre(CinemaRecord* records_table,int length,bool MinMax = true);
void SortByReleaseDate(CinemaRecord* records_table,int length,bool MinMax = true);
void SortByTagLine(CinemaRecord* records_table,int length,bool MinMax = true);