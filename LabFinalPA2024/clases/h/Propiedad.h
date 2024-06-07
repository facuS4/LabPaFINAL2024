#ifndef PROPIEDADES_H
#define PROPIEDADES_H

#include <iostream>
#include "Usuario.h"
#include "Venta.h"
#include "Alquiler.h"
#include "clases/datatypes/h/dtDireccion.h"
#include "../ICollection/Collections/List.h"

using namespace std;

class Propiedad : public ICollectible{
    private:
        string codigo;
        int dormitorios;
        int ambientes;
        int banios;
        bool garage;
        dtDireccion direccion;
        float medif;
        float MetrosTotales;
    public:
        Propiedad();
        Propiedad(string, int, int, int, bool, dtDireccion, float, float);
        virtual ~Propiedad();

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

        dtDireccion getDireccion();
        void setDireccion(dtDireccion);

        float getMedif();
        void setMedif(float);

        float getMetrosTotales();
        void setMetrosTotales(float);

        virtual void eliminarVinculosPropiedad()= 0;
        virtual void AgregarMensaje(string)= 0;

        virtual void CrearMensaje(string, Usuario u)= 0;

        virtual set<dtEdificio> ListarPropiedades()= 0;
        virtual void Vincular(Venta v)= 0;
        virtual void Vincular(Alquiler a)= 0;

};


#endif