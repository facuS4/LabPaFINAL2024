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
        Propiedad * propiedadtemp=nullptr;
    public:
        Inmobiliaria();
        Inmobiliaria(string, string, string, dtDireccion *);
        ~Inmobiliaria();

        string getNombre();
        dtDireccion * getUbicacion();
        void eliminarAlquiler(Alquiler *);
        void eliminarVenta(Venta *);

        ICollection * getVentas();
        ICollection * getAlquileres();

        void setUbicacion(dtDireccion *);
        void setVentas(ICollectible *);
        void setAlquileres(ICollectible *);

        void setNombre(string);

        void Asociar(Conversacion* c);
        void DesvincularInmobiliaria(Conversacion *c);
        bool PerteneceAinmobiliaria(string codigo);
        void desvincularAlquiler(int);
        void desvincularVenta(int);
        void EliminarPropiedad(string codigo);
        void vincularInmobiliaria(Propiedad*);
        void SeleccionarAlquiler(int);
        void SeleccionarVenta(int);
        void IcolAlquileres(ICollection *);
        void IcolVentas(ICollection *);
        void menuprueba();

};


#endif