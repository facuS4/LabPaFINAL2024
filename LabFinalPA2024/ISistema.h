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
#include "clases/h/Usuario.h"
#include "clases/h/Zona.h"
#include "clases/h/Mensaje.h"
#include "clases/h/Conversacion.h"

#include "./clases/h/Propiedad.h"
#include "./clases/h/Departamento.h"
#include "./clases/h/Edificio.h"


using namespace std;

class ISistema {
    public:
        virtual ~ISistema(); // destructor

        virtual void AltaInteresado(string ,string , string , int ) =0;

        virtual void mostrarPropiedades(string, Zona *)=0;

        virtual void AltaEdificio(string nombre, int pisos, int gastosComunes)=0;

        virtual void setDepartamento(Departamento * u)=0;

        virtual ICollection * getDepartamento()=0;

        virtual void setUsuarioActual(Usuario *)=0;

        virtual void Listarusuarios()=0;

        virtual ICollection * getUsuarios()=0;

        virtual Usuario * getUsuarioActual()=0;
        virtual Conversacion * getConversacionActual()=0;

        virtual void altaUsuario(Usuario *)=0;

        virtual void AltaInmobiliaria(string email, string nombre) = 0;

        virtual void EliminarPropiedad(string codigo) = 0;

        virtual void IngresarEmail(string email) = 0;

        virtual void ingreasrcontraseniaNueva(string contrasenia) = 0;

        virtual void listarDepartamentos() = 0;

        virtual Departamento * seleccionarDepartamento(char letraDpto) = 0;

        virtual void Ultimo5Mensajes() = 0;

        virtual void SeleccionarConversacionInmobiliaria() = 0;
        
        virtual void enviarMensajeInmobiliaria() = 0;

        virtual void EnviarMensajeInteresado() = 0;

        virtual void AgregarMensaje(string mensaje) = 0;

        virtual void CrearMensaje(string mensaje) = 0;

        virtual Zona * SelecionarZona(string codigo,Departamento * depto)=0;

        virtual bool boolSeleccionarZona(string codigo) = 0;

        virtual void ListarEdificio() = 0;

        virtual void altaApartamento(int ambientes) = 0;

        virtual int altaApartamento(int, int, int, bool, dtDireccion, int) = 0;

        virtual int altaCasa(int, int, int, bool, dtDireccion, int, int) = 0;

        virtual void vincularconInmobiliaria(Propiedad *p) = 0;

        virtual void ObtenerReporteInmobiliaria()=0;

        virtual void seleccionarAlquiler(int precio) = 0;

        virtual void seleccionarVenta(int valor, Propiedad *p) = 0;

        virtual void AltaDepartamento(char, string) = 0;

        virtual void altaPropiedad() = 0;

        virtual Edificio * SeleccionarEdificio(string nombre) = 0;

        virtual void modificarPropiedad() = 0;
};




#endif