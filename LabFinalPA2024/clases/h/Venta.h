#ifndef VENTA_H
#define VENTA_H

#include <iostream>
#include "../ICollection/Collections/List.h"

using namespace std;

class Venta : public ICollectible{
    private:
        float precioVenta;
    public:
        Venta();
        Venta(string, string);
        ~Venta();

        float getPrecioAlquiler();
        void setPrecioAlquiler(float);


        void desvincualarVenta(string codigo);
       
};


#endif