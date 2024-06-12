#ifndef PROPIEDADES_H
#define PROPIEDADES_H

class Venta;
class Alquiler;
#include <iostream>
#include "Usuario.h"
#include "Venta.h"
#include "Alquiler.h"
#include "Conversacion.h"
#include "../datatypes/h/dtDireccion.h"
#include "../../ICollection/collections/List.h"
#include "../../ICollection/interfaces/ICollectible.h"




using namespace std;

class Propiedad : public ICollectible{
    private:
        string codigo;
        int dormitorios;
        int ambientes;
        int banios;
        bool garage;
        dtDireccion* direccion;
        float medif;
        float MetrosTotales;
        ICollection * Conversaciones;
    public:
        Propiedad();
        Propiedad(string, int, int, int, bool, dtDireccion*, float, float);
        virtual ~Propiedad()=0;

        void setConvo(Conversacion *);
        string getCodigo();
        void setCodigo(string);

        int getDormitorios();
        void setDormitorios(int);

        int getAmbientes();
        void setAmbientes(int);

        int getBanios();
        void setBanios(int);

        bool getGarage();
        void setGarage(bool);

        dtDireccion* getDireccion();
        void setDireccion(dtDireccion*);

        float getMedif();
        void setMedif(float);

        float getMetrosTotales();
        void setMetrosTotales(float);

        virtual void eliminarVinculosPropiedad()= 0;
        virtual void AgregarMensaje(string)= 0;

        virtual void CrearMensaje(string, Usuario * u)= 0;

        virtual void ListarPropiedadesEdificio()= 0;
        virtual void VincularV(Venta *v)= 0;
        virtual void VincularA(Alquiler *a)= 0;

};


#endif