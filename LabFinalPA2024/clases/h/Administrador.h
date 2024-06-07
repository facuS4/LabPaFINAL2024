#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include <iostream>
#include "Usuario.h"
#include "Conversacion.h"
#include "../ICollection/Collections/List.h"

using namespace std;

class Administrador : public Usuario{
    private:
    public:
        Administrador();
        Administrador(string, string);
        ~Administrador();


        void Asociar(Conversacion c);
       
};


#endif