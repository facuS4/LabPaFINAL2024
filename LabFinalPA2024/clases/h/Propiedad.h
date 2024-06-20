#ifndef PROPIEDADES_H
#define PROPIEDADES_H

class Venta;
class Alquiler;
class Zona;
#include <iostream>
#include "Usuario.h"
#include "Venta.h"
#include "Alquiler.h"
#include "Conversacion.h"
#include "Zona.h"
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
        Zona * mizona;
    public:
        Propiedad();
        Propiedad(string, int, int, int, bool, dtDireccion*, float, float, Zona *);
        virtual ~Propiedad()=0;
        ICollection * getConversaciones();

        void setConversaciones(Conversacion *);
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

        Zona * getZona();

        dtDireccion* getDireccion();
        void setDireccion(dtDireccion*);

        virtual string CasaApartamentoDisponible()=0;
        
        float getMedif();
        void setMedif(float);
        virtual void imprimirEdificio()=0;

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