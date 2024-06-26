#ifndef MENSAJE_H
#define MENSAJE_H

#include <iostream>
#include "../datatypes/h/dtFecha.h"
//#include "../datatypes/h/dtDireccion.h"

class dtFecha;

#include "../../ICollection/collections/List.h"
#include "../../ICollection/interfaces/ICollectible.h"

using namespace std;

class Mensaje: public ICollectible{
    private:
        dtFecha * fecha;
        string texto;
    public:
        Mensaje();
        Mensaje(dtFecha *, string);
        ~Mensaje();
        dtFecha* getFecha();
        string getTexto();
        void setFecha(dtFecha *);
        void setTexto(string);
};


#endif