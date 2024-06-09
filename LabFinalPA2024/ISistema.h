#ifndef ISISTEMA_H
#define ISISTEMA_H

#include <string.h>
#include <iostream>
#include <set>

#include "ICollection/collections/List.h"
#include "ICollection/collections/ListIterator.h"
#include "ICollection/collections/ListNode.h"
#include "ICollection/collections/OrderedDictionary.h"
#include "ICollection/collections/OrderedDictionaryEntry.h"
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/ICollection.h"
#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/interfaces/IIterator.h"
#include "ICollection/interfaces/IKey.h"
#include "ICollection/interfaces/OrderedKey.h"
#include "ICollection/Integer.h"
#include "ICollection/String.h"

#include "dtDireccion.h"
#include "Propiedad.h"

using namespace std;

class ISistema {
    public:
        virtual ~ISistema(); // destructor

        virtual bool AltaInmobiliaria(string email, string nombre, dtDireccion dir) = 0;

        virtual void EliminarPropiedad(string codigo) = 0;

        virtual void IngresarEmail(string email) = 0;

        virtual void ingreasrcontraseniaNueva(string contrasenia) = 0;

        virtual void listarDepartamentos() = 0;

        virtual set<dtZona> seleccionarDepartamento(string letraDpto) = 0;

        virtual set<string> Ultimo5Mensajes() = 0;

        virtual void EnviarMensaje(string mensaje) = 0;

        virtual void AgregarMensaje(string mensaje) = 0;

        virtual void CrearMensaje(string mensaje) = 0;

        virtual void SelecionarZona(string codigo) = 0;

        virtual bool boolSeleccionarZona(string codigo) = 0;

        virtual set<dtEdificio> ListarEdificio() = 0;

        virtual set<dtEdificio> altaApartamento(int ambientes) = 0;

        virtual int altaApartamento(int, int, int, bool, dtDireccion, int) = 0;

        virtual int altaCasa(int, int, int, bool, dtDireccion, int, int) = 0;

        virtual void vincularconInmobiliaria(Propiedad* p) = 0;

        virtual void seleccionarAlquiler(int precio) = 0;

        virtual void seleccionarVenta(int valor, Propiedad *p) = 0;
};




#endif