#ifndef SISTEMA_H
#define SISTEMA_H

#include "ISistema.h"
#include "clases/h/Departamento.h"
#include "clases/h/Usuario.h"
#include "clases/h/Administrador.h"
#include "clases/h/Inmobiliaria.h"
#include "clases/h/Interesado.h"
#include "clases/h/Edificio.h"
#include "clases/h/Casa.h"
#include "clases/h/Apartamento.h"
#include "clases/h/Propiedad.h"
#include "clases/h/Mensaje.h"
#include "clases/h/Conversacion.h"
#include "clases/h/Alquiler.h"
#include "clases/h/Venta.h"






using namespace std;

class Sistema : public ISistema{
    private:
        Sistema();
        static Sistema * instancia;
        ICollection * Departamentos;
        ICollection * misUsuarios;
        ICollection * Edificios;
        Usuario * usuarioSesion;


    public:
        ~Sistema(); // destructor // ✅

        void setDepartamento(Departamento * u);

        ICollection * getDepartamento();
        
        void mostrarPropiedades(string, Zona *);

        void AltaEdificio(string nombre, int pisos, int gastosComunes);

        void AltaInteresado(string email,string nombre, string apellido, int edad);

        void Listarusuarios(); // ✅

        void altaUsuario(Usuario *);

        Usuario * getUsuarioActual();

        void setUsuarioActual(Usuario *);

        ICollection * getUsuarios();

        static Sistema * getInstancia(); // devuelve el controlador Sistema (Singleton) // ✅

        void AltaInmobiliaria(string email, string nombre);

        void EliminarPropiedad(string codigo);

        void IngresarEmail(string email);

        void ingreasrcontraseniaNueva(string contrasenia);

        void listarDepartamentos();

        Departamento * seleccionarDepartamento(char letraDpto);

        void Ultimo5Mensajes();

        void EnviarMensaje(string mensaje);

        void AgregarMensaje(string mensaje);

        void CrearMensaje(string mensaje);

        Zona * SelecionarZona(string codigo,Departamento * depto);

        bool boolSeleccionarZona(string codigo);

        void ListarEdificio();

        void altaApartamento(int ambientes);

        int altaApartamento(int, int, int, bool, dtDireccion, int);

        int altaCasa(int, int, int, bool, dtDireccion, int, int);

        void vincularconInmobiliaria(Propiedad *p);

        void seleccionarAlquiler(int precio);

        void seleccionarVenta(int valor, Propiedad *p);

        void AltaDepartamento(char, string);

};


#endif