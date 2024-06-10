#ifndef USUARIO_H
#define USUARIO_H

#include <string.h>
#include <iostream>
#include <set>

using namespace std;

#include "Conversacion.h"
#include "../../ICollection/collections/List.h"
#include "../../ICollection/interfaces/ICollectible.h"


class Usuario : public ICollectible {
    private:
        string CorreoElectronico;
        string Contrasenia;

    public:
        Usuario();
        Usuario(string, string);
        virtual ~Usuario();

        string getCorreoElectronico();
        string getContrasenia();
        void setCorreoElectronico(string);
        void setContrasenia(string);

        virtual void Asociar (Conversacion * c) = 0;
};

#endif