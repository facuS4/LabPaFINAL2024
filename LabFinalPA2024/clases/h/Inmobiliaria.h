#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H

#include <iostream>
#include "Usuario.h"
#include "Conversacion.h"
#include "Venta.h"
#include "Alquiler.h"
#include "Propiedad.h"
#include "../datatypes/h/dtDireccion.h"
#include "../../ICollection/collections/List.h"


using namespace std;

class Inmobiliaria : public Usuario{
    private:
        string nombre;
        dtDireccion * ubicacion;
        ICollection * ventas;
        ICollection * alquileres;
    public:
        Inmobiliaria();
        Inmobiliaria(string, string, int, string);
        ~Inmobiliaria();

        string getNombre();
        string getApellido();
        int getEdad();
        dtDireccion * getUbicacion();
        ICollection * getVentas();

        void setNombre(string);
        void setApellido(string);
        void setEdad(int);
        void setUbicacion(dtDireccion *);

        void Asociar(Conversacion c);
        void DesvincularInmobiliaria(Conversacion c);

        void desvincularAlquiler(int);
        void desvincularVenta(int);

        void vincularInmobiliaria(Propiedad);
        void SeleccionarAlquiler(int);
        void SeleccionarVenta(int);

};


#endif