#ifndef LIBRO_H
#define LIBRO_H

#include "material.h"

class Libro : public Material {
private:
    std::string autor;

public:
    Libro(std::string t, std::string a);
    std::string getTipo() const;
    std::string getDato() const;
};

#endif