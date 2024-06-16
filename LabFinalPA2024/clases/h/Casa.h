#ifndef CASA_H
#define CASA_H

#include <iostream>
#include "Propiedad.h"
#include "../datatypes/h/dtDireccion.h"
#include "../../ICollection/collections/List.h"
#include "../../ICollection/interfaces/ICollectible.h"


using namespace std;

class Casa : public Propiedad{
    private:
        float metrosVerdes;
    public:
        Casa();
        Casa(string, int, int, int, bool, dtDireccion *, float, float, float, Zona *);
        ~Casa();

        float getMetrosVerdes();
        void setMetrosVerdes(float);

        void eliminarVinculosPropiedad();
        void AgregarMensaje(string);

        void CrearMensaje(string, Usuario* u);

        void ListarPropiedadesEdificio();
        void VincularV(Venta *v);
        void VincularA(Alquiler * a);

};


#endif