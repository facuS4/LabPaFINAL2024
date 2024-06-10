#ifndef APARTAMENTO_H
#define APARTAMENTO_H

#include <iostream>
#include "Propiedad.h"
#include "Edificio.h"
#include "Usuario.h"
#include "clases/datatypes/h/dtDireccion.h"
#include "../ICollection/Collections/List.h"

using namespace std;

class Apartamento : public Propiedad{
    private:
        bool disponible;
        Edificio edificio;
    public:
        Apartamento();
        Apartamento(string, int, int, int, bool, dtDireccion, float, float, bool);
        ~Apartamento();

        float getMetrosTotales();
        void setMetrosTotales(float);

        void eliminarVinculosPropiedad();
        void AgregarMensaje(string);
        
        void CrearMensaje(string, Usuario * u);

        void ListarPropiedadesEdificio();
        void Vincular(Venta v);
        void Vincular(Alquiler a);

};


#endif