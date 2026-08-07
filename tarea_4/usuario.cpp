#include "usuario.h"

int Usuario::contador = 0;

Usuario::Usuario(std::string n) {
    nombre = n;
    contador = contador + 1;
    codigo = "USU-" + std::to_string(contador);
}

std::string Usuario::getCodigo() const {
    return codigo;
}

std::string Usuario::getNombre() const {
    return nombre;
}