#ifndef SISTEMA_H
#define SISTEMA_H

#include "ISistema.h"

using namespace std;

class Sistema : public  ISistema{
    private:
        Sistema();
        static Sistema * instancia;
        ICollection * Departamentos;
        ICollection * Usuarios;

    public:
        ~Sistema(); // destructor // ✅
        static Sistema * getInstancia(); // devuelve el controlador Sistema (Singleton) // ✅

        bool AltaInmobiliaria(string email, string nombre, dtDireccion dir);

        void EliminarPropiedad(string codigo);

        void IngresarEmail(string email);

        void ingreasrcontraseniaNueva(string contrasenia);

        set<dtDepartamentos> listarDepartamentos();

        set<dtZona> seleccionarDepartamento(string letraDpto);

        set<string> Ultimo5Mensajes();

        void EnviarMensaje(string mensaje);

        void AgregarMensaje(string mensaje);

        void CrearMensaje(string mensaje);

        set<dtZona> SelecionarZona(string codigo);

        bool boolSeleccionarZona(string codigo);

        set<dtEdificio> ListarEdificio();

        set<dtEdificio> altaApartamento(int ambientes);

        int altaApartamento(int, int, int, bool, dtDireccion, int);

        int altaCasa(int, int, int, bool, dtDireccion, int, int);

        void vincularconInmobiliaria(Propiedad p);

        void seleccionarAlquiler(int precio);

        void seleccionarVenta(int valor, Propiedad p);
};


#endif