#include "dtFecha.h"

dtFecha::dtFecha(){
    time_t t;
    struct tm *tm;
    t=time(NULL);
    tm=localtime(&t);
    this->dia = tm->tm_mday;
    this->mes = tm->tm_mon + 1;
    this->anio = tm->tm_year + 1900; // Corrección aquí
}

dtFecha::dtFecha(int _dia, int _mes, int _anio){
    this->dia = _dia;
    this->mes = _mes;
    this->anio = _anio;
}

int dtFecha::getDia(){
    return this->dia;
}

int dtFecha::getMes(){
    return this->mes;
}

int dtFecha::getAnio(){
    return this->anio;
}