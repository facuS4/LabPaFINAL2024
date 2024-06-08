#include "dtDepartamento.h"

dtDepartamento::dtDepartamento() {
}

dtDepartamento::dtDepartamento(string nombre, char letraDpto) {
    this->nombre = nombre;
    this->letraDpto = letraDpto;
}

string dtDepartamento::getNombre() {
    return this->nombre;
}

char dtDepartamento::getLetraDpto() {
    return this->letraDpto;
}

dtDepartamento::~dtDepartamento() {
}
