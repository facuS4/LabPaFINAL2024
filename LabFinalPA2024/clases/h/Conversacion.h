#ifndef CONVERSACION_H
#define CONVERSACION_H

#include <iostream>
#include "Usuario.h"
#include "../../ICollection/collections/List.h"
#include "../../ICollection/interfaces/ICollectible.h"
#include "../h/Mensaje.h"

class Usuario;

using namespace std;

class Conversacion:public ICollectible{
    private:
        ICollection * mensajes;
        //ICollection * inmobiliarias;
    public:
        Conversacion();
        ~Conversacion();
        void eliminarVinculosConversacion();
        void AgregarMensaje(Mensaje *);
        void CrearMensaje(string, Usuario * u);
};


#endif