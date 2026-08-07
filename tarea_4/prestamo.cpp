#include "prestamo.h"

Prestamo::Prestamo(std::string u, std::string m) {
    codUsuario = u;
    codMaterial = m;
}

std::string Prestamo::getCodUsuario() const {
    return codUsuario;
}

std::string Prestamo::getCodMaterial() const {
    return codMaterial;
}