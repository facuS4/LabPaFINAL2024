#include "dtHora.h"

dtHora::dtHora(){
    time_t t;
    struct tm *tm;
    t=time(NULL);
    tm=localtime(&t);
    this->horas = tm->tm_hour;
    this->minutos = tm->tm_min;
}

dtHora::dtHora(int _horas, int _minuto){
    this->horas = _horas;
    this->minutos = _minuto;
}

int dtHora::getHoras(){
    return this->horas;
}

int dtHora::getMinutos(){
    return this->minutos;
}