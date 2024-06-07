#ifndef CASA_H
#define CASA_H

#include <iostream>
#include "Propiedad.h"
#include "clases/datatypes/h/dtDireccion.h"
#include "../ICollection/Collections/List.h"

using namespace std;

class Casa : public Propiedad{
    private:
        float metrosTotales;
    public:
        Casa();
        Casa(string, int, int, int, bool, dtDireccion, float, float, float);
        ~Casa();

        float getMetrosTotales();
        void setMetrosTotales(float);

        void eliminarVinculosPropiedad();
        void AgregarMensaje(string);

        void CrearMensaje(string, Usuario u);

        set<dtEdificio> ListarPropiedades();
        void Vincular(Venta v);
        void Vincular(Alquiler a);

};


#endif