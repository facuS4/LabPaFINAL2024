#include <iostream>
#include <string>
#include <set>

#include "SistemaFactory.h"
#include "Sistema.h"
#include "ISistema.h"

using namespace std;

ISistema * sis = SistemaFactory::crearSistema();

int main(){
    cout << "Hello, World!" << endl;
    return 0;
}