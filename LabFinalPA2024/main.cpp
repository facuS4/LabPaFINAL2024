#include <iostream>
#include <string>
#include <set>

#include "SistemaFactory.h"
#include "Sistema.h"
#include "ISistema.h"

using namespace std;

ISistema * sis = SistemaFactory::crearSistema();

int main(){
    
    /*Usuario::Usuario(string email, string password){
  CorreoElectronico = email;
  Contrasenia = password;
}*/
    
    Administrador * admin= new Administrador("root@r.com","123");
    Inmobiliaria * imn1= new Inmobiliaria("sss.com","123", "los pepes");
    Interesado * int1= new Interesado("goof.com","123","pepe",20,"pepoide");
    Inmobiliaria * inm2= new Inmobiliaria("peps.com",nullptr, "oepes");
    Interesado * int2= new Interesado("rs.com",nullptr,"pepe2",21,"pepoide3");

    

    for(int i=0;i<5;i++){

    }


    if (sis->getUsuarioActual()==nullptr){
        
    }
    
    cout << "Hello, World!" << endl;
    return 0;

    admin->~Administrador();
    imn1->~Inmobiliaria();
    int1->~Interesado();
    inm2->~Inmobiliaria();
    int2->~Interesado();

}
