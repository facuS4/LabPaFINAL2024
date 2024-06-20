#ifndef ALQUILER_H
#define ALQUILER_H

class Venta;
class Propiedad;
class Casa;
class Apartamento;
#include <iostream>
#include "../../ICollection/collections/List.h"
#include "../../ICollection/interfaces/ICollectible.h"
#include "Propiedad.h"

using namespace std;

class Alquiler : public ICollectible{
    private:
        float precioAlquiler;
        Propiedad * p;
    public:
        Alquiler();
        Alquiler(float);
        ~Alquiler();

        float getPrecioAlquiler();
        void setPrecioAlquiler(float);
        void setPropiedad(Propiedad * pp);
        Propiedad * getPropiedad();
        void ObtenerReporteInmobiliaria4();
        void desvincualarAlquiler(string codigo);
       
};


#endif