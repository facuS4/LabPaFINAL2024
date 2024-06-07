#ifndef EDIFICIo_H
#define EDIFICIo_H

#include <iostream>
#include "Propiedad.h"
#include "clases/datatypes/h/dtDireccion.h"
#include "../ICollection/Collections/List.h"

using namespace std;

class Edificio{
    private:
        string nombre;
        int cantPisos;
        float gastosComunes;
    public:
        Edificio();
        Edificio(string, int, float);
        ~Edificio();

        string getNombre();
        void setNombre(string);

        int getCantPisos();
        void setCantPisos(int);

        float getGastosComunes();
        void setGastosComunes(float);

        void desvincularPropiedad(string codigo);
};


#endif