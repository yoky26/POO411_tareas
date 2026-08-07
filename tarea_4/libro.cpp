#include "libro.h"

Libro::Libro(std::string t, std::string a) : Material(t) {
    autor = a;
}

std::string Libro::getTipo() const {
    return "Libro";
}

std::string Libro::getDato() const {
    return autor;
}