#ifndef ALQUILER_H
#define ALQUILER_H

#include <iostream>
#include "../ICollection/Collections/List.h"

using namespace std;

class Alquiler : public ICollectible{
    private:
        float precioAlquiler;
    public:
        Alquiler();
        Alquiler(string, string);
        ~Alquiler();

        float getPrecioAlquiler();
        void setPrecioAlquiler(float);


        void desvincualarAlquiler(string codigo);
       
};


#endif