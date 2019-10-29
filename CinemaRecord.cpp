#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CinemaRecord.h"



void SetName(CinemaRecord* cr,char* film_name){
	cr->name = (char*)malloc(sizeof(char)* strlen(film_name)+1);
	strcpy(cr->name,film_name);
}

void SetYear(CinemaRecord* cr, int year)
{

	if (year < 1895 || year > 2050) {
		printf("Error! wrong year!");
		return;
	}

	cr->year = year;

}

void SetCountry(CinemaRecord* cr, char* countryName) {

	cr->country = new char[strlen(countryName)+1];
	strcpy(cr->country, countryName);

}

void SetScriptWriter(CinemaRecord* cr, char* scriptWriterName) {

	cr->scriptwriter = (char*)malloc(sizeof(char) * strlen(scriptWriterName)+1);
	strcpy(cr->scriptwriter, scriptWriterName);

}

void SetDirector(CinemaRecord* cr, char* directorName) {

	cr->director = new char[strlen(directorName)+1];
	strcpy(cr->director, directorName);

}

void SetProducer(CinemaRecord* cr, char* producerName) {

	cr->producer = new char[strlen(producerName)+1];
	strcpy(cr->producer, producerName);

}

void SetBudget(CinemaRecord* cr, float cash) {

	cr->budget = cash;

}

void SetDuration(CinemaRecord* cr, int duration) {
	cr->duration = duration;
}

void SetGenre(CinemaRecord* cr, char* genreName) {
	
	cr->genre = (char*)malloc(sizeof(char) * strlen(genreName)+1);
	strcpy(cr->genre, genreName);
}

void SetReleaseDate(CinemaRecord* cr, int day,int month,int year) {
	cr->release_date.tm_mday = day;
	cr->release_date.tm_mon = month;
	cr->release_date.tm_year = year;
}


void SetTagLine(CinemaRecord* cr, char* tagline) {

		cr->tagline = (char*)malloc(sizeof(char) * strlen(tagline)+1);


	strcpy(cr->tagline, tagline);
}



void ShowRecord(CinemaRecord cr){
    printf("%s%d\n%s\n%s\n%s\n%s\n%f\n%d\n%s\n%d/%d/%d\n[%s]",
           cr.name,
		   cr.year,
           cr.country,
           cr.director,
           cr.scriptwriter,
           cr.producer,
           cr.budget,
           cr.duration,
           cr.genre,
           cr.release_date,
           cr.tagline);
}

