#ifndef MENSAJE_H
#define MENSAJE_H

#include <iostream>
#include "clases/datatypes/h/dtFecha.h"
#include "../ICollection/Collections/List.h"

using namespace std;

class Mensaje{
    private:
        dtFecha fecha;
        string texto;
    public:
        Mensaje();
        Mensaje(dtFecha, string);
        ~Mensaje();
        dtFecha getFecha();
        string getTexto();
        void setFecha(dtFecha);
        void setTexto(string);
};


#endif