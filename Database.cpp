#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Database.h"
#include "Utils.h"
#include "CinemaRecord.h"


CinemaRecord** ReadDatabaseFile(char * filename,int &length){


    CinemaRecord ** Table;
    FILE* f = fopen(filename,"r");
    char buffer[512];
    int linesCount = 0;

    Table  = (CinemaRecord**)calloc(1,sizeof( CinemaRecord* ));

    while(fgets(buffer,512,f)){

        Table[linesCount] = (CinemaRecord*)calloc(1, sizeof(CinemaRecord));
        // заполняем структуру значениями
        StringToCinemaRecord(&Table[linesCount],buffer);
        linesCount++;
        recalloc(Table,linesCount, sizeof( CinemaRecord* )); // перевыделяем память еще на одну ячейку больше

    }

    length = linesCount;
    fclose(f);
    return Table;
}

void ShowTable(CinemaRecord ** records,int length){

    system("clear");
    for(int i=0;i<length;i++){
        printf("%d:",i);
        ShowRecord(*records[i]);
        printf("\n____________________________________________________________________\n");
    }

    getchar();

}


void StringToCinemaRecord(CinemaRecord** record, char* buffer){



    //разбить строку на "|" и сделать подписать
    char * str = strtok(buffer,"|");
    SetName(*record,str);


    str = strtok(NULL,"|");
    SetYear(*record, atoi(str)); // на выходе получается строка мы её конвертируем в число

    str = strtok(NULL,"|");
    SetCountry(*record,str);

    str = strtok(NULL,"|");
    SetDirector(*record,str);

    str = strtok(NULL,"|");
    SetScriptWriter(*record,str);

    str = strtok(NULL,"|");
    SetProducer(*record,str);

    str = strtok(NULL,"|");
    SetBudget(*record,atof(str));

    str = strtok(NULL,"|");
    SetDuration(*record,atoi(str));

    str = strtok(NULL,"|");
    SetGenre(*record,str);

    str = strtok(NULL,"|");
    //формат даты будет таким
    int year,month,day;
    sscanf(str,"%d/%d/%d",&year,&month,&day);

    SetReleaseDate(*record,day,month,year);

    str = strtok(NULL,"|");
    SetTagLine(*record,str);

}



void EditRecord(CinemaRecord* record){

        SetName(record,EnterStringFromConsole("Enter Film name:","error: try again"));

        SetYear(record,EnterIntFromConsole("Enter Year:","error:try again",1895,2100));

        SetCountry(record,EnterStringFromConsole("Enter Country:","error:try again"));
        SetDirector(record,EnterStringFromConsole("Enter Film Director","error: try again"));
        SetScriptWriter(record,EnterStringFromConsole("Enter ScriptWriter","error: try again"));
        SetProducer(record,EnterStringFromConsole("Enter Producer name:","error: try again"));
        SetBudget(record,EnterFloatFromConsole("Enter budget","error: try again",0,500000000000));
        SetDuration(record,EnterIntFromConsole("Enter Duration","error:try again",1,14440));
        SetGenre(record,EnterStringFromConsole("Enter Film Genre","error:try again"));
        SetReleaseDate(record,EnterIntFromConsole("Enter Year:","error: try again",1895,2100),
                              EnterIntFromConsole("Enter Month:[1-12]","error:enter correct date[1-12]",1,12),
                              EnterIntFromConsole("Enter Day:[1-31]","error:enter correct date[1-31]",1,31));

        SetTagLine(record,EnterStringFromConsole("Enter tagline","error:try again"));

}

void AddNewRecord(CinemaRecord ** records_table,int &length, CinemaRecord* new_record){


    recalloc(records_table,++length, sizeof(CinemaRecord*));
    records_table[length] = new_record;

}

void DeleteRecord(CinemaRecord* records_table,int &length,int record_number){

        for(int i = record_number;i<length;i++){
            records_table[i] = records_table[i+1];
        }
    length--;
}

/*функция для третьего пункта меню
 * отсортировать запись по заданному параметру
 * sort_param отвечает за нужный параметр в cinemaRecord
 * sortMinMax  отвечает за сортировку от минимального к максимальному и по умолчанию равно true
 * если sortMinMax = false тогда записи будут отсортированы по другому принципу
 * */


void SortByName(CinemaRecord* records_table,int length,bool MinMax){
    CinemaRecord temp_record;
    if(MinMax)
        for(int i=0;i<length;i++)
            for(int j=0;j<length;j++)
                for(int k = 0;k<strlen(records_table[i].name);k++)
                    if(records_table[i].name[k] == records_table[j].name[k])
                        continue;
                    else if(records_table[i].name[k] > records_table[j].name[k]){
                        temp_record = records_table[i];
                        records_table[i] = records_table[j];
                        records_table[j] = temp_record;
                    }
                    else
                        for(int i=0;i<length;i++)
                            for(int j=0;j<length;j++)
                                for(int k = 0;k<strlen(records_table[i].name);k++)
                                    if(records_table[i].name[k] == records_table[j].name[k])
                                        continue;
                                    else if(records_table[i].name[k] < records_table[j].name[k]){
                                        temp_record = records_table[i];
                                        records_table[i] = records_table[j];
                                        records_table[j] = temp_record;
                                    }
}

void SortByYear(CinemaRecord* records_table,int length,bool MinMax){

    CinemaRecord temp_record;
    if(MinMax)
        for(int i=0;i<length;i++)
            for(int j = 0;j<length;j++)
                if(records_table[i].year > records_table[i].year){
                    temp_record = records_table[i];
                    records_table[i] = records_table[j];
                    records_table[j] = temp_record;
                }

    else
         for(int i=0;i<length;i++)
             for(int j = 0;j<length;j++)
                 if(records_table[i].year < records_table[i].year){
                     temp_record = records_table[i];
                     records_table[i] = records_table[j];
                     records_table[j] = temp_record;
                 }
}

void SortByCountry(CinemaRecord* records_table,int length,bool MinMax){
    CinemaRecord temp_record;
    if(MinMax)
        for(int i=0;i<length;i++)
            for(int j=0;j<length;j++)
                for(int k = 0;k<strlen(records_table[i].country);k++)
                    if(records_table[i].country[k] == records_table[j].country[k])
                        continue;
                    else if(records_table[i].country[k] > records_table[j].country[k]){
                        temp_record = records_table[i];
                        records_table[i] = records_table[j];
                        records_table[j] = temp_record;
                    }
    else
                        for(int i=0;i<length;i++)
                            for(int j=0;j<length;j++)
                                for(int k = 0;k<strlen(records_table[i].country);k++)
                                    if(records_table[i].country[k] == records_table[j].country[k])
                                        continue;
                                    else if(records_table[i].country[k] < records_table[j].country[k]){
                                        temp_record = records_table[i];
                                        records_table[i] = records_table[j];
                                        records_table[j] = temp_record;
                                    }
}

void SortByDirector(CinemaRecord* records_table,int length,bool MinMax){
    CinemaRecord temp_record;
    if(MinMax)
        for(int i=0;i<length;i++)
            for(int j=0;j<length;j++)
                for(int k = 0;k<strlen(records_table[i].director);k++)
                    if(records_table[i].director[k] == records_table[j].director[k])
                        continue;
                    else if(records_table[i].director[k] > records_table[j].director[k]){
                        temp_record = records_table[i];
                        records_table[i] = records_table[j];
                        records_table[j] = temp_record;
                    }
    else
                        for(int i=0;i<length;i++)
                            for(int j=0;j<length;j++)
                                for(int k = 0;k<strlen(records_table[i].director);k++)
                                    if(records_table[i].director[k] == records_table[j].director[k])
                                        continue;
                                    else if(records_table[i].director[k] < records_table[j].director[k]){
                                        temp_record = records_table[i];
                                        records_table[i] = records_table[j];
                                        records_table[j] = temp_record;
                                    }
}

void SortByScriptWriter(CinemaRecord* records_table,int length,bool MinMax){
    CinemaRecord temp_record;
    if(MinMax)
        for(int i=0;i<length;i++)
            for(int j=0;j<length;j++)
                for(int k = 0;k<strlen(records_table[i].scriptwriter);k++)
                    if(records_table[i].scriptwriter[k] == records_table[j].scriptwriter[k])
                        continue;
                    else if(records_table[i].scriptwriter[k] > records_table[j].scriptwriter[k]){
                        temp_record = records_table[i];
                        records_table[i] = records_table[j];
                        records_table[j] = temp_record;
                    }
                    else
                        for(int i=0;i<length;i++)
                            for(int j=0;j<length;j++)
                                for(int k = 0;k<strlen(records_table[i].scriptwriter);k++)
                                    if(records_table[i].scriptwriter[k] == records_table[j].scriptwriter[k])
                                        continue;
                                    else if(records_table[i].scriptwriter[k] < records_table[j].scriptwriter[k]){
                                        temp_record = records_table[i];
                                        records_table[i] = records_table[j];
                                        records_table[j] = temp_record;
                                    }
}

void SortByProducer(CinemaRecord* records_table,int length,bool MinMax){
    CinemaRecord temp_record;
    if(MinMax)
        for(int i=0;i<length;i++)
            for(int j=0;j<length;j++)
                for(int k = 0;k<strlen(records_table[i].producer);k++)
                    if(records_table[i].producer[k] == records_table[j].producer[k])
                        continue;
                    else if(records_table[i].producer[k] > records_table[j].producer[k]){
                        temp_record = records_table[i];
                        records_table[i] = records_table[j];
                        records_table[j] = temp_record;
                    }
                    else
                        for(int i=0;i<length;i++)
                            for(int j=0;j<length;j++)
                                for(int k = 0;k<strlen(records_table[i].producer);k++)
                                    if(records_table[i].producer[k] == records_table[j].producer[k])
                                        continue;
                                    else if(records_table[i].producer[k] < records_table[j].producer[k]){
                                        temp_record = records_table[i];
                                        records_table[i] = records_table[j];
                                        records_table[j] = temp_record;
                                    }
}

void SortByBudget(CinemaRecord* records_table,int length,bool MinMax){

    CinemaRecord temp_record;
    if(MinMax)
        for(int i=0;i<length;i++)
            for(int j = 0;j<length;j++)
                if(records_table[i].budget > records_table[i].budget){
                    temp_record = records_table[i];
                    records_table[i] = records_table[j];
                    records_table[j] = temp_record;
                }

                else
                    for(int i=0;i<length;i++)
                        for(int j = 0;j<length;j++)
                            if(records_table[i].budget < records_table[i].budget){
                                temp_record = records_table[i];
                                records_table[i] = records_table[j];
                                records_table[j] = temp_record;
                            }
}

void SortByDuration(CinemaRecord* records_table,int length,bool MinMax){

    CinemaRecord temp_record;
    if(MinMax)
        for(int i=0;i<length;i++)
            for(int j = 0;j<length;j++)
                if(records_table[i].duration > records_table[i].duration){
                    temp_record = records_table[i];
                    records_table[i] = records_table[j];
                    records_table[j] = temp_record;
                }

                else
                    for(int i=0;i<length;i++)
                        for(int j = 0;j<length;j++)
                            if(records_table[i].duration < records_table[i].duration){
                                temp_record = records_table[i];
                                records_table[i] = records_table[j];
                                records_table[j] = temp_record;
                            }
}

void SortByGenre(CinemaRecord* records_table,int length,bool MinMax){
    CinemaRecord temp_record;
    if(MinMax)
        for(int i=0;i<length;i++)
            for(int j=0;j<length;j++)
                for(int k = 0;k<strlen(records_table[i].genre);k++)
                    if(records_table[i].genre[k] == records_table[j].genre[k])
                        continue;
                    else if(records_table[i].genre[k] > records_table[j].genre[k]){
                        temp_record = records_table[i];
                        records_table[i] = records_table[j];
                        records_table[j] = temp_record;
                    }
                    else
                        for(int i=0;i<length;i++)
                            for(int j=0;j<length;j++)
                                for(int k = 0;k<strlen(records_table[i].genre);k++)
                                    if(records_table[i].genre[k] == records_table[j].genre[k])
                                        continue;
                                    else if(records_table[i].genre[k] < records_table[j].genre[k]){
                                        temp_record = records_table[i];
                                        records_table[i] = records_table[j];
                                        records_table[j] = temp_record;
                                    }
}

void SortByReleaseDate(CinemaRecord* records_table,int length,bool MinMax){
    CinemaRecord temp_record;
    if(MinMax)
        for(int i=0;i<length;i++)
            for(int j=0;j<length;j++)
                if(records_table[i].release_date.tm_year > records_table[j].release_date.tm_year) {

                    temp_record = records_table[i];
                    records_table[i] = records_table[j];
                    records_table[j] = temp_record;

                }
                else if(records_table[i].release_date.tm_mon > records_table[j].release_date.tm_mon){

                        temp_record = records_table[i];
                        records_table[i] = records_table[j];
                        records_table[j] = temp_record;

                }else if(records_table[i].release_date.tm_mday > records_table[j].release_date.tm_mday){

                        temp_record = records_table[i];
                        records_table[i] = records_table[j];
                        records_table[j] = temp_record;
                }
    else
                    for(int i=0;i<length;i++)
                        for(int j=0;j<length;j++)
                            if(records_table[i].release_date.tm_year < records_table[j].release_date.tm_year) {

                                temp_record = records_table[i];
                                records_table[i] = records_table[j];
                                records_table[j] = temp_record;

                            }
                            else if(records_table[i].release_date.tm_mon < records_table[j].release_date.tm_mon){

                                temp_record = records_table[i];
                                records_table[i] = records_table[j];
                                records_table[j] = temp_record;

                            }else if(records_table[i].release_date.tm_mday < records_table[j].release_date.tm_mday){

                                temp_record = records_table[i];
                                records_table[i] = records_table[j];
                                records_table[j] = temp_record;
                            }

}

void SortByTagLine(CinemaRecord* records_table,int length,bool MinMax){
    CinemaRecord temp_record;
    if(MinMax)
        for(int i=0;i<length;i++)
            for(int j=0;j<length;j++)
                for(int k = 0;k<strlen(records_table[i].tagline);k++)
                    if(records_table[i].tagline[k] == records_table[j].tagline[k])
                        continue;
                    else if(records_table[i].tagline[k] > records_table[j].tagline[k]){
                        temp_record = records_table[i];
                        records_table[i] = records_table[j];
                        records_table[j] = temp_record;
                    }
                    else
                        for(int i=0;i<length;i++)
                            for(int j=0;j<length;j++)
                                for(int k = 0;k<strlen(records_table[i].tagline);k++)
                                    if(records_table[i].tagline[k] == records_table[j].tagline[k])
                                        continue;
                                    else if(records_table[i].tagline[k] < records_table[j].tagline[k]){
                                        temp_record = records_table[i];
                                        records_table[i] = records_table[j];
                                        records_table[j] = temp_record;
                                    }
}

void SortByParameter(SORT_VALUES parameter,CinemaRecord *records_table,int length,bool MinMax){
    switch(parameter){
        case NAME:{
            SortByName(records_table,length,MinMax);
            break;
        }
        case YEAR:{
            SortByYear(records_table,length,MinMax);
            break;
        }
        case COUNTRY:{
            SortByCountry(records_table,length,MinMax);
            break;
        }
        case PRODUCER:{
            SortByProducer(records_table,length,MinMax);
            break;
        }
        case DIRECTOR:{
            SortByDirector(records_table,length,MinMax);
            break;
        }
        case SCRIPTWRITER:{
            SortByScriptWriter(records_table,length,MinMax);
            break;
        }
        case BUDGET:{
            SortByBudget(records_table,length,MinMax);
            break;
        }
        case DURATION:{
            SortByDuration(records_table,length,MinMax);
            break;
        }
        case GENRE:{
            SortByGenre(records_table,length,MinMax);
            break;
        }
        case RELEASE_DATE:{
            SortByReleaseDate(records_table,length,MinMax);
            break;
        }
        case TAGLINE:{
            SortByTagLine(records_table,length,MinMax);
            break;
        }

    }
}

