#ifndef APARTAMENTO_H
#define APARTAMENTO_H

#include <iostream>
#include "Propiedad.h"
#include "Edificio.h"
#include "Usuario.h"
#include "../datatypes/h/dtDireccion.h"
#include "../../ICollection/collections/List.h"
#include "../../ICollection/interfaces/ICollectible.h"

using namespace std;

class Apartamento : public Propiedad{
    private:
        bool disponible;
        Edificio * edificio;
    public:
        Apartamento();
        Apartamento(string, int, int, int, bool, dtDireccion* , float, float, bool, Edificio *, Zona *);
        ~Apartamento();

        float getMetrosTotales();
        void setMetrosTotales(float);
        void setDisponible(bool);
        string CasaApartamentoDisponible();
        void imprimirEdificio();
        

        void eliminarVinculosPropiedad();
        void AgregarMensaje(string);
        
        void CrearMensaje(string, Usuario * u);

        void ListarPropiedadesEdificio();
        void VincularV(Venta *v);
        void VincularA(Alquiler *a);

};


#endif