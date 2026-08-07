#include "revista.h"

Revista::Revista(std::string t, std::string e) : Material(t) {
    editorial = e;
}

std::string Revista::getTipo() const {
    return "Revista";
}

std::string Revista::getDato() const {
    return editorial;
}