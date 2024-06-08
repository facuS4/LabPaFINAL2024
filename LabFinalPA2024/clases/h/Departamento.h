#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H

#include <iostream>
#include <string>
#include <set>
#include "Zona.h"
#include "../ICollection/Collections/List.h"

using namespace std;

class Departamento : public ICollectible{
    private:
        char Letradpto;
        string nombre;
        ICollection * Zonas;
    public:
        Departamento();
        Departamento(char, string);
        ~Departamento();

        char getLetradpto();
        void setLetradpto(char);

        string getNombre();
        void setNombre(string);

        ICollection * getZonas();

        set<dtZonas> SeleccionarDepartamento(char Letradpto);

        Propiedad SeleccionarPropiedad(string codigo);
        set<dtPropiedad> SeleccionarZona(string codigo);

        dtZona BuscarZona(string codigo);
       
};


#endif