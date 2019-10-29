#pragma once
#include <time.h>

enum SORT_VALUES{
    NAME= 0,
    YEAR = 1,
    COUNTRY,
    DIRECTOR,
    SCRIPTWRITER,
    PRODUCER,
    BUDGET,
    DURATION,
    GENRE,
    RELEASE_DATE,
    TAGLINE
};



typedef struct{
	//название фильма
	char* name;
	// год выпуска фильма
	int year; 

	//страна 
	char* country;

	//режиссер
	char* director;

	//сценарист
	char* scriptwriter;

	//продюссер
	char* producer;

	//бюджет
	float budget;

	//продолжительность
	int duration;

	//жанр фильма
	char* genre;

	//дата выхода
	tm release_date;

	//слоган фильма
	char* tagline;

}CinemaRecord;



void SetName(CinemaRecord* cr,char* film_name);
void SetYear(CinemaRecord* cr,int year);
void SetCountry(CinemaRecord* cr,char* countryName);
void SetScriptWriter(CinemaRecord *cr,char* scriptWriterName);
void SetDirector(CinemaRecord* cr,char * directorName);
void SetProducer(CinemaRecord* cr,char * producerName);
void SetBudget(CinemaRecord* cr,float budget);
void SetDuration(CinemaRecord* cr,int  duration);
void SetGenre(CinemaRecord* cr,char* genreName);
void SetReleaseDate(CinemaRecord* cr, int day,int month,int year);
void SetTagLine(CinemaRecord* cr, char* tagline);
void ShowRecord(CinemaRecord cr);

