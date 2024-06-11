#ifndef SISTEMA_H
#define SISTEMA_H

#include "ISistema.h"
#include "clases/h/Departamento.h"
#include "clases/h/Usuario.h"
#include "clases/h/Administrador.h"
#include "clases/h/Inmobiliaria.h"
#include "clases/h/Interesado.h"

using namespace std;

class Sistema : public ISistema{
    private:
        Sistema();
        static Sistema * instancia;
        ICollection * Departamentos;
        ICollection * misUsuarios;
        Usuario * usuarioSesion;


    public:
        ~Sistema(); // destructor // ✅

        void AltaInteresado(string nombre, string apellido, int edad, string email);

        void Listarusuarios(); // ✅

        void altaUsuario(Usuario *);

        Usuario * getUsuarioActual();

        void setUsuarioActual(Usuario *);

        ICollection * getUsuarios();

        static Sistema * getInstancia(); // devuelve el controlador Sistema (Singleton) // ✅

        void AltaInmobiliaria(string email, string nombre, dtDireccion *dir);

        void EliminarPropiedad(string codigo);

        void IngresarEmail(string email);

        void ingreasrcontraseniaNueva(string contrasenia);

        void listarDepartamentos();

        Departamento * seleccionarDepartamento(char letraDpto);

        void Ultimo5Mensajes();

        void EnviarMensaje(string mensaje);

        void AgregarMensaje(string mensaje);

        void CrearMensaje(string mensaje);

        void SelecionarZona(string codigo);

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