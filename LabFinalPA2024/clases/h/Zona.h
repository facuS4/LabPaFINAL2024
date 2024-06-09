#ifndef ZONA_H
#define ZONA_H

#include <iostream>
#include <string>
#include <set>
#include "clases/datatypes/h/dtDireccion.h"
#include "./Propiedad.h"
#include "Departamento.h"
#include "../ICollection/Collections/List.h"

using namespace std;

class Zona : public ICollectible{
    private:
        string codigo;
        string nombre;
        ICollection * Propiedades;
        Departamento * departamento;
    public:
        Zona();
        Zona(string, string);
        ~Zona();

        string getCodigo();
        void setCodigo(string);

        string getNombre();
        void setNombre(string);

        void EliminarPropiedad(string codigo);
        set<dtPropiedad> SeleccionarZona(string codigo);
        Propiedad SeleccionarPropiedad(string codigo, string nombreus);

        set<dtEdificio> ListarEdificios();

        bool altaApartamento(int, int, int, bool, dtDireccion, int);
        bool altaCasa(int, int, int, bool, dtDireccion, int, int);

       
};


#endif