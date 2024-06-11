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
        Inmobiliaria(string, string, string, dtDireccion *);
        ~Inmobiliaria();

        string getNombre();
        dtDireccion * getUbicacion();

        ICollection * getVentas();
        ICollection * getAlquileres();

        void setUbicacion(dtDireccion *);
        void setVentas(ICollection *);
        void setAlquileres(ICollection *);

        void setNombre(string);

        void Asociar(Conversacion* c);
        void DesvincularInmobiliaria(Conversacion *c);

        void desvincularAlquiler(int);
        void desvincularVenta(int);

        void vincularInmobiliaria(Propiedad*);
        void SeleccionarAlquiler(int);
        void SeleccionarVenta(int);

};


#endif