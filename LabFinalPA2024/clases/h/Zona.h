#ifndef ZONA_H
#define ZONA_H

#include <iostream>
#include <string>
#include <set>
#include "../datatypes/h/dtDireccion.h"
#include "./Propiedad.h"
// #include "Departamento.h"
#include "../../ICollection/collections/List.h"
#include "../../ICollection/interfaces/ICollectible.h"

class Departamento;

using namespace std;

class Zona : public ICollectible{
    private:
        string codigo;
        string nombre;
        ICollection * Propiedades;
        Departamento * departamento;
    public:
        Zona();
        Zona(string, string, Departamento*);
        ~Zona();

        string getCodigo();
        void setCodigo(string);
        Departamento  * getDepartamento();

        string getNombre();
        void setNombre(string);

        ICollection * getPropiedades();
        void setPropiedades(ICollectible *);

        void EliminarPropiedad(Propiedad *);
        void SeleccionarZona(string codigo);
        Propiedad * SeleccionarPropiedad(string codigo, string nombreus);

        bool ListarPropiedades();
        void ListarEdificios();

        bool altaApartamento(int, int, int, bool, dtDireccion , int);
        bool altaCasa(int, int, int, bool, dtDireccion , int, int);

       
};


#endif