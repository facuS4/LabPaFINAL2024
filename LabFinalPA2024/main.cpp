#include <iostream>
#include <string>
#include <set>

#include "SistemaFactory.h"
#include "Sistema.h"
#include "ISistema.h"
class Inmobiliaria;
using namespace std;

ISistema * sis = SistemaFactory::crearSistema();

int main(){
    
    /*Usuario::Usuario(string email, string password){
  CorreoElectronico = email;
  Contrasenia = password;
}*/
      //USUARIOS HARDCODEDEADOS//
    dtDireccion * ladir;
    ladir = new dtDireccion("Bosnia","Mintx","0032","Boris Salvatore");
    Usuario * admin= new Administrador("root@r.com","123");
    Inmobiliaria * imn1= new Inmobiliaria("sss.com","123", "los pepes", ladir);
    Interesado * int1= new Interesado("goof.com","123","pepe",20,"pepoide");
    Inmobiliaria * inm2= new Inmobiliaria("peps.com","", "oepes",ladir);
    Interesado * int2= new Interesado("rs.com","","pepe2",21,"pepoide3");
    sis->altaUsuario(admin);
    sis->altaUsuario(imn1);
    sis->altaUsuario(int1);
    sis->altaUsuario(inm2);
    sis->altaUsuario(int2);

    sis->Listarusuarios();

    while (sis->getUsuarioActual()==nullptr){
      cout << "Inicie sesion con su usuario" << endl << "Recuerde que no se puede crear usuarios"<< endl << endl << "Email: ";
      string ingresar;
      getline(cin,ingresar);
      IIterator * it = sis->getUsuarios()->getIterator();
      Usuario * utemp;
      while (it->hasCurrent()) {  
        utemp = (Usuario *) it->getCurrent();
        if (utemp->getCorreoElectronico()==ingresar){
          sis->setUsuarioActual(utemp);
          break;
        }
        it->next();
      }
      delete it;
      system("clear");
    }
    cout << sis->getUsuarioActual()->getCorreoElectronico() << " Logeado " << endl << endl;
    
    admin->~Usuario();
    imn1->~Inmobiliaria();
    int1->~Interesado();
    inm2->~Inmobiliaria();
    int2->~Interesado();
    
    return 0;
}
