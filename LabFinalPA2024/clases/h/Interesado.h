#ifndef INTERESADO_H
#define INTERESADO_H

#include <iostream>
#include "Usuario.h"
#include "Conversacion.h"
#include "../../ICollection/collections/List.h"


using namespace std;

class Interesado : public Usuario{
    private:
        string nombre;
        int edad;
        string apellido;
        ICollection * conversaciones;
    public:
        Interesado();
        Interesado(string, string, int, string);
        ~Interesado();

        string getNombre();
        string getApellido();
        int getEdad();

        void setNombre(string);
        void setApellido(string);
        void setEdad(int);

        void Asociar(Conversacion c);
        void Desvincular(Conversacion c);
};


#endif