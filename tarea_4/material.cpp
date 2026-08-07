#include "material.h"

int Material::contador = 0;

Material::Material(std::string t) {
    titulo = t;
    disponible = true;
    contador = contador + 1;
    codigo = "MAT-" + std::to_string(contador);
}

std::string Material::getCodigo() const {
    return codigo;
}

std::string Material::getTitulo() const {
    return titulo;
}

bool Material::estaDisponible() const {
    return disponible;
}

void Material::cambiarEstado(bool e) {
    disponible = e;
}