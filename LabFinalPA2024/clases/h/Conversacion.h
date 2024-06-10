#ifndef CONVERSACION_H
#define CONVERSACION_H

#include <iostream>
#include "Usuario.h"
#include "../../ICollection/collections/List.h"
#include "../../ICollection/interfaces/ICollectible.h"

class Usuario;

using namespace std;

class Conversacion{
    private:
        ICollection * mensajes;
        ICollection * inmobiliarias;
    public:
        Conversacion();
        ~Conversacion();
        void eliminarVinculosConversacion();
        void AgregarMensaje(string);
        void CrearMensaje(string, Usuario * u);
};


#endif