#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H

#include <iostream>
#include <string>
#include <set>
#include "Zona.h"
#include "../../ICollection/collections/List.h"
#include "../../ICollection/interfaces/ICollectible.h"


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
        void setZona(Zona *z);

        char getLetradpto();
        void setLetradpto(char);

        string getNombre();
        void setNombre(string);

        ICollection * getZonas();

        void SeleccionarDepartamento(char Letradpto);

        Propiedad * SeleccionarPropiedad(string codigo);
        void SeleccionarZona(string codigo);

        void BuscarZona(string codigo);
       
};


#endif